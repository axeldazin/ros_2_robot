#include "tower_perception/scene_analyzer.hpp"

#include <algorithm>
#include <cmath>
#include <memory>
#include <stdexcept>
#include <opencv2/imgproc.hpp>
#include "image_geometry/pinhole_camera_model.hpp"
#include "tf2/LinearMath/Matrix3x3.hpp"
#include "tf2/LinearMath/Quaternion.hpp"
#include "tower_model/cube.hpp"
#include "tower_model/cylindre.hpp"
#include "tower_model/rectangle.hpp"
#include "tower_model/ros_conversion.hpp"

namespace tower_perception
{
cv::Mat depth_in_metres(const cv::Mat & depth, double integer_depth_scale)
{
  cv::Mat metres;
  if (!std::isfinite(integer_depth_scale) || integer_depth_scale <= 0.0) {
    throw std::invalid_argument("depth_scale doit etre positif et fini.");
  }
  if (depth.type() == CV_16UC1) {
    depth.convertTo(metres, CV_32FC1, integer_depth_scale);
  } else if (depth.type() == CV_32FC1) {
    metres = depth;
  } else {
    throw std::invalid_argument("Profondeur attendue : 16UC1 ou 32FC1.");
  }
  return metres;
}

SceneResult analyze_scene(
  const cv::Mat & bgr, const cv::Mat & depth,
  const sensor_msgs::msg::CameraInfo & info, const std_msgs::msg::Header & header,
  const DetectorConfig & detector, const GeometryConfig & geometry)
{
  if (bgr.empty() || depth.type() != CV_32FC1 || depth.size() != bgr.size()) {
    throw std::invalid_argument("La profondeur doit etre alignee sur l'image couleur.");
  }
  if (header.frame_id.empty() || info.header.frame_id != header.frame_id ||
    info.width != static_cast<unsigned>(bgr.cols) ||
    info.height != static_cast<unsigned>(bgr.rows) ||
    !std::isfinite(info.k[0]) || !std::isfinite(info.k[4]) ||
    !std::isfinite(info.p[0]) || !std::isfinite(info.p[5]) ||
    info.k[0] <= 0.0 || info.k[4] <= 0.0 || info.p[0] <= 0.0 || info.p[5] <= 0.0)
  {
    throw std::invalid_argument("CameraInfo absent/incompatible : taille, repere ou calibration.");
  }
  if (info.distortion_model != "plumb_bob" && info.distortion_model != "rational_polynomial") {
    throw std::invalid_argument("Distorsion attendue : plumb_bob ou rational_polynomial.");
  }
  image_geometry::PinholeCameraModel camera;
  camera.fromCameraInfo(info);
  auto ray_at = [&camera](const cv::Point2d & pixel) {
      const auto ray = camera.projectPixelTo3dRay(camera.rectifyPoint(pixel));
      const cv::Vec3d direction(ray.x, ray.y, ray.z);
      if (!std::isfinite(cv::norm(direction)) || std::abs(ray.z) < 1e-9) {
        throw std::runtime_error("Calibration invalide : rayon non defini.");
      }
      return direction / ray.z;
    };
  const double normal_norm = cv::norm(geometry.table_normal);
  if (!std::isfinite(normal_norm) || normal_norm < 1e-9) {
    throw std::invalid_argument("La normale du support doit etre finie et non nulle.");
  }
  const cv::Vec3d normal = geometry.table_normal / normal_norm;

  SceneResult result;
  result.observation.header = header;
  result.debug_image = bgr.clone();
  const double drawing_scale = std::max(1.0, std::min(bgr.cols, bgr.rows) / 480.0);
  const int outline_thickness = std::max(2, cvRound(1.5 * drawing_scale));
  const int text_thickness = std::max(1, cvRound(drawing_scale));
  for (const auto & detection : detect_colors(bgr, detector)) {
    cv::Mat mask = cv::Mat::zeros(depth.size(), CV_8UC1);
    cv::drawContours(mask, std::vector<std::vector<cv::Point>>{detection.contour},
      0, cv::Scalar(255), cv::FILLED);
    cv::erode(mask, mask, cv::getStructuringElement(cv::MORPH_ELLIPSE, {5, 5}));
    const int pixel_count = cv::countNonZero(mask);
    std::vector<float> depths;
    for (int y = 0; y < depth.rows; ++y) {
      for (int x = 0; x < depth.cols; ++x) {
        const float z = depth.at<float>(y, x);
        if (mask.at<unsigned char>(y, x) && std::isfinite(z) &&
          z >= geometry.min_depth && z <= geometry.max_depth)
        {
          depths.push_back(z);
        }
      }
    }
    if (depths.empty() || pixel_count == 0 ||
      static_cast<double>(depths.size()) / pixel_count < geometry.min_valid_depth_fraction)
    {
      throw std::runtime_error("Profondeur insuffisante pour une piece : analyse refusee.");
    }
    auto median = depths.begin() + depths.size() / 2;
    std::nth_element(depths.begin(), median, depths.end());
    const cv::Vec3d top_center = ray_at(detection.box.center) * *median;

    // Intersection des rayons des coins avec le plan de la face superieure.
    cv::Point2f pixels[4];
    detection.box.points(pixels);
    cv::Vec3d corners[4];
    for (int i = 0; i < 4; ++i) {
      const auto ray = ray_at(pixels[i]);
      const double denominator = normal.dot(ray);
      if (std::abs(denominator) < 1e-6) {
        throw std::runtime_error("Camera presque parallele au plan des pieces.");
      }
      const double scale = normal.dot(top_center) / denominator;
      if (!std::isfinite(scale) || scale <= 0.0) {
        throw std::runtime_error("Intersection de projection invalide.");
      }
      corners[i] = ray * scale;
    }
    cv::Vec3d x_axis = corners[1] - corners[0];
    const cv::Vec3d other_edge = corners[2] - corners[1];
    double length = cv::norm(x_axis);
    double width = cv::norm(other_edge);
    if (width > length) {
      std::swap(length, width);
      x_axis = other_edge;
    }
    if (!std::isfinite(length) || !std::isfinite(width) || width < 1e-6) {
      throw std::runtime_error("Dimensions projetees invalides.");
    }
    x_axis /= cv::norm(x_axis);
    // Reorthogonaliser pour obtenir un quaternion valide, meme avec une vue inclinee.
    cv::Vec3d y_axis = normal.cross(x_axis);
    y_axis /= cv::norm(y_axis);
    x_axis = y_axis.cross(normal);
    tf2::Matrix3x3 rotation(
      x_axis[0], y_axis[0], normal[0],
      x_axis[1], y_axis[1], normal[1],
      x_axis[2], y_axis[2], normal[2]);
    tf2::Quaternion orientation;
    rotation.getRotation(orientation);
    orientation.normalize();

    std::unique_ptr<tower_model::Piece> piece;
    // La forme donne les dimensions physiques connues. Le contour fournit l'orientation.
    if (detection.shape == Shape::Cube) {
      piece = std::make_unique<tower_model::Cube>(0, geometry.cube_side);
    } else if (detection.shape == Shape::Rectangle) {
      piece = std::make_unique<tower_model::Rectangle>(0,
        geometry.rectangle_length, geometry.rectangle_width, geometry.rectangle_height);
    } else {
      piece = std::make_unique<tower_model::Cylindre>(
        0, geometry.cylinder_diameter / 2.0, geometry.cylinder_height);
    }
    // La profondeur mesure le dessus : le centre est une demi-hauteur plus bas.
    const auto center = top_center - normal * (piece->dimensions().hauteur / 2.0);
    geometry_msgs::msg::PoseStamped pose;
    pose.header = header;
    pose.pose.position.x = center[0];
    pose.pose.position.y = center[1];
    pose.pose.position.z = center[2];
    pose.pose.orientation.x = orientation.x();
    pose.pose.orientation.y = orientation.y();
    pose.pose.orientation.z = orientation.z();
    pose.pose.orientation.w = orientation.w();
    const float score = detection.shape_score * static_cast<float>(depths.size()) / pixel_count;
    result.observation.pieces.push_back(tower_model::to_message(*piece, pose, score));

    const cv::Scalar color = detection.shape == Shape::Cube ? cv::Scalar(0, 0, 255) :
      detection.shape == Shape::Rectangle ? cv::Scalar(255, 0, 0) : cv::Scalar(0, 255, 0);
    // Simplifier seulement le trace : les mesures gardent le contour issu du masque nettoye.
    std::vector<cv::Point> outline;
    cv::approxPolyDP(detection.contour, outline,
      detector.contour_simplification_ratio * cv::arcLength(detection.contour, true), true);
    cv::drawContours(result.debug_image, std::vector<std::vector<cv::Point>>{outline},
      0, color, outline_thickness, cv::LINE_AA);
    // Centre visible dans l'image ; sa projection 3D est envoyee dans piece.pose.
    cv::drawMarker(result.debug_image, detection.box.center, cv::Scalar(0, 255, 255),
      cv::MARKER_CROSS, cvRound(12 * drawing_scale), outline_thickness, cv::LINE_AA);
    const cv::Point label(cvRound(detection.box.center.x + 8 * drawing_scale),
      cvRound(detection.box.center.y - 8 * drawing_scale));
    cv::putText(result.debug_image, piece->forme(), label,
      cv::FONT_HERSHEY_SIMPLEX, 0.5 * drawing_scale, cv::Scalar(0, 0, 0),
      text_thickness + 2 * cvRound(drawing_scale), cv::LINE_AA);
    cv::putText(result.debug_image, piece->forme(), label,
      cv::FONT_HERSHEY_SIMPLEX, 0.5 * drawing_scale, cv::Scalar(255, 255, 255),
      text_thickness, cv::LINE_AA);
  }
  return result;
}
}  // namespace tower_perception
