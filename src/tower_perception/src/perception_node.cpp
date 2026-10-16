#include "tower_perception/perception_node.hpp"

#include <algorithm>
#include <cmath>
#include <functional>
#include <stdexcept>
#include <vector>
#include "cv_bridge/cv_bridge.hpp"
#include "sensor_msgs/image_encodings.hpp"
#include "tf2_geometry_msgs/tf2_geometry_msgs.hpp"

namespace tower_perception
{
PerceptionNode::PerceptionNode(const rclcpp::NodeOptions & options)
: Node("perception_node", options)
{
  const auto color_topic = startup_parameter<std::string>(
    "color_topic", "/camera/camera/color/image_raw");
  const auto depth_topic = startup_parameter<std::string>(
    "depth_topic", "/camera/camera/aligned_depth_to_color/image_raw");
  const auto info_topic = startup_parameter<std::string>(
    "camera_info_topic", "/camera/camera/color/camera_info");
  output_frame_ = startup_parameter<std::string>("output_frame", "");
  depth_scale_ = startup_parameter<double>("depth_scale", 0.001);
  max_age_ = startup_parameter<double>("max_snapshot_age_s", 2.0);
  tracking_distance_ = startup_parameter<double>("tracking_distance_m", 0.05);
  const double sync_tolerance = startup_parameter<double>("sync_tolerance_s", 0.05);
  geometry_.cube_side = startup_parameter<double>("cube_side_m", geometry_.cube_side);
  geometry_.rectangle_length = startup_parameter<double>("rectangle_length_m", geometry_.rectangle_length);
  geometry_.rectangle_width = startup_parameter<double>("rectangle_width_m", geometry_.rectangle_width);
  geometry_.rectangle_height = startup_parameter<double>("rectangle_height_m", geometry_.rectangle_height);
  geometry_.cylinder_diameter = startup_parameter<double>("cylinder_diameter_m", geometry_.cylinder_diameter);
  geometry_.cylinder_height = startup_parameter<double>("cylinder_height_m", geometry_.cylinder_height);
  geometry_.min_depth = startup_parameter<double>("min_depth_m", 0.1);
  geometry_.max_depth = startup_parameter<double>("max_depth_m", 3.0);
  geometry_.min_valid_depth_fraction = startup_parameter<double>("min_valid_depth_fraction", 0.5);
  const auto normal = startup_parameter<std::vector<double>>("table_normal_camera", {0.0, 0.0, -1.0});
  if (normal.size() != 3) {
    throw std::invalid_argument("table_normal_camera doit contenir trois valeurs.");
  }
  geometry_.table_normal = {normal[0], normal[1], normal[2]};
  const double norm = cv::norm(geometry_.table_normal);
  auto positive = [](double value) {return std::isfinite(value) && value > 0.0;};
  if (!positive(depth_scale_) || !positive(max_age_) || !positive(sync_tolerance) ||
    !positive(tracking_distance_) || !positive(norm) || !positive(geometry_.min_depth) ||
    !positive(geometry_.max_depth) || geometry_.max_depth <= geometry_.min_depth ||
    !positive(geometry_.min_valid_depth_fraction) || geometry_.min_valid_depth_fraction > 1.0 ||
    !positive(geometry_.cube_side) || !positive(geometry_.rectangle_length) ||
    !positive(geometry_.rectangle_width) || !positive(geometry_.rectangle_height) ||
    !positive(geometry_.cylinder_diameter) || !positive(geometry_.cylinder_height))
  {
    throw std::invalid_argument("Parametre geometrique invalide : consulter config/perception.yaml.");
  }

  detector_.min_area = startup_parameter<double>("min_area_px", detector_.min_area);
  detector_.min_area_fraction = startup_parameter<double>(
    "min_area_fraction", detector_.min_area_fraction);
  detector_.min_fill = startup_parameter<double>("min_fill_ratio", 0.7);
  detector_.min_circularity = startup_parameter<double>("min_circularity", 0.65);
  detector_.min_cylinder_solidity = startup_parameter<double>(
    "min_cylinder_solidity", detector_.min_cylinder_solidity);
  detector_.max_cube_aspect = startup_parameter<double>("max_cube_aspect_ratio", 1.4);
  const auto morphology = startup_parameter<int>("morphology_size", 3);
  detector_.scale_morphology_with_resolution = startup_parameter<bool>(
    "scale_morphology_with_resolution", detector_.scale_morphology_with_resolution);
  detector_.contour_simplification_ratio = startup_parameter<double>(
    "contour_simplification_ratio", detector_.contour_simplification_ratio);
  const auto roi = startup_parameter<std::vector<int64_t>>("roi", {0, 0, 0, 0});
  if (roi.size() != 4 || std::any_of(roi.begin(), roi.end(), [](int64_t v) {
      return v < 0 || v > 100000;
    }) || ((roi[2] == 0 || roi[3] == 0) && roi != std::vector<int64_t>{0, 0, 0, 0}))
  {
    throw std::invalid_argument("roi attend [x, y, largeur, hauteur] ou [0, 0, 0, 0].");
  }
  detector_.roi = cv::Rect(roi[0], roi[1], roi[2], roi[3]);
  detector_.morphology_size = morphology;
  if (!positive(detector_.min_area) || !std::isfinite(detector_.min_area_fraction) ||
    detector_.min_area_fraction < 0.0 || detector_.min_area_fraction >= 1.0 ||
    !positive(detector_.min_fill) || detector_.min_fill > 1.0 ||
    !positive(detector_.min_circularity) || detector_.min_circularity > 1.0 ||
    !positive(detector_.min_cylinder_solidity) || detector_.min_cylinder_solidity > 1.0 ||
    !positive(detector_.max_cube_aspect) || detector_.max_cube_aspect < 1.0 ||
    !std::isfinite(detector_.contour_simplification_ratio) ||
    detector_.contour_simplification_ratio < 0.0 || detector_.contour_simplification_ratio > 0.01 ||
    morphology < 1 || morphology > 31 || morphology % 2 == 0)
  {
    throw std::invalid_argument(
      "Seuils invalides : noyau impair entre 1 et 31, contour_simplification_ratio entre 0 et 0.01.");
  }
  const std::array<std::string, 4> names{{"red", "red_wrap", "blue", "green"}};
  for (std::size_t i = 0; i < names.size(); ++i) {
    auto read_hsv = [this](const std::string & name, const cv::Scalar & initial) {
        const auto values = startup_parameter<std::vector<int64_t>>(
          name, {static_cast<int64_t>(initial[0]), static_cast<int64_t>(initial[1]),
            static_cast<int64_t>(initial[2])});
        if (values.size() != 3 || values[0] < 0 || values[0] > 179 ||
          values[1] < 0 || values[1] > 255 || values[2] < 0 || values[2] > 255)
        {
          throw std::invalid_argument("Seuil HSV invalide : " + name);
        }
        return cv::Scalar(values[0], values[1], values[2]);
      };
    auto & range = detector_.ranges[i];
    range.low = read_hsv(names[i] + "_hsv_low", range.low);
    range.high = read_hsv(names[i] + "_hsv_high", range.high);
    for (int channel = 0; channel < 3; ++channel) {
      if (range.low[channel] > range.high[channel]) {
        throw std::invalid_argument("Bornes HSV inversees pour " + names[i]);
      }
    }
  }

  pieces_pub_ = create_publisher<tower_interfaces::msg::PieceArray>("/detected_pieces", 10);
  debug_pub_ = create_publisher<Image>("/perception/debug_image", 2);
  camera_info_sub_ = create_subscription<sensor_msgs::msg::CameraInfo>(
    info_topic, rclcpp::SensorDataQoS(),
    [this](sensor_msgs::msg::CameraInfo::ConstSharedPtr message) {camera_info_ = message;});
  color_sub_.subscribe(this, color_topic, rmw_qos_profile_sensor_data);
  depth_sub_.subscribe(this, depth_topic, rmw_qos_profile_sensor_data);
  synchronizer_ = std::make_shared<message_filters::Synchronizer<SyncPolicy>>(
    SyncPolicy(10));
  synchronizer_->setMaxIntervalDuration(rclcpp::Duration::from_seconds(sync_tolerance));
  synchronizer_->connectInput(color_sub_, depth_sub_);
  synchronizer_->registerCallback(&PerceptionNode::on_images, this);
  tf_buffer_ = std::make_unique<tf2_ros::Buffer>(get_clock());
  tf_listener_ = std::make_shared<tf2_ros::TransformListener>(*tf_buffer_);

  service_ = create_service<AnalyzeImage>("/perception/analyze_image",
    [this](const AnalyzeImage::Request::SharedPtr, AnalyzeImage::Response::SharedPtr response) {
      *response = analyze();
    });
  trigger_sub_ = create_subscription<std_msgs::msg::Empty>("/perception/analyze", 10,
    [this](std_msgs::msg::Empty::ConstSharedPtr) {
      const auto response = analyze();
      if (!response.success) {
        RCLCPP_WARN(get_logger(), "%s", response.message.c_str());
      }
    });
  RCLCPP_INFO(get_logger(), "Pret : service /perception/analyze_image ou topic /perception/analyze.");
  RCLCPP_INFO(get_logger(), "Dimensions physiques chargees ; configurer la normale du support avant utilisation.");
}

void PerceptionNode::on_images(
  const Image::ConstSharedPtr & color, const Image::ConstSharedPtr & depth)
{
  // Aucune detection ici : seulement memoriser la derniere paire synchronisee.
  color_ = color;
  depth_ = depth;
}

PerceptionNode::AnalyzeImage::Response PerceptionNode::analyze()
{
  AnalyzeImage::Response response;
  try {
    if (!color_ || !depth_ || !camera_info_) {
      throw std::runtime_error("En attente : couleur, profondeur alignee et CameraInfo requis.");
    }
    const double age = (now() - rclcpp::Time(color_->header.stamp, get_clock()->get_clock_type())).seconds();
    if (age < -0.1 || age > max_age_) {
      throw std::runtime_error("Images perimees ou horloges incompatibles : attendre une nouvelle paire.");
    }
    if (color_->header.frame_id != depth_->header.frame_id) {
      throw std::runtime_error("La profondeur doit etre alignee dans le repere optique couleur.");
    }
    if (depth_->encoding != sensor_msgs::image_encodings::TYPE_16UC1 &&
      depth_->encoding != sensor_msgs::image_encodings::TYPE_32FC1)
    {
      throw std::runtime_error("Encodage profondeur non pris en charge : utiliser 16UC1 ou 32FC1.");
    }
    const auto color = cv_bridge::toCvShare(color_, sensor_msgs::image_encodings::BGR8);
    const auto depth = cv_bridge::toCvShare(depth_);
    auto result = analyze_scene(color->image, depth_in_metres(depth->image, depth_scale_),
      *camera_info_, color_->header, detector_, geometry_);

    if (!output_frame_.empty() && output_frame_ != result.observation.header.frame_id) {
      const auto transform = tf_buffer_->lookupTransform(output_frame_,
        result.observation.header.frame_id,
        rclcpp::Time(result.observation.header.stamp, get_clock()->get_clock_type()),
        rclcpp::Duration::from_seconds(0.1));
      for (auto & piece : result.observation.pieces) {
        geometry_msgs::msg::PoseStamped transformed;
        tf2::doTransform(piece.pose, transformed, transform);
        // Conserver la date de mesure plutot que la date d'une TF statique.
        transformed.header.stamp = result.observation.header.stamp;
        piece.pose = transformed;
      }
      result.observation.header.frame_id = output_frame_;
    }
    assign_ids(result.observation);
    response.success = true;
    response.message = std::to_string(result.observation.pieces.size()) + " piece(s) detectee(s).";
    response.observation = result.observation;
    pieces_pub_->publish(result.observation);
    debug_pub_->publish(*cv_bridge::CvImage(color_->header, "bgr8", result.debug_image).toImageMsg());
    RCLCPP_INFO(get_logger(), "%s", response.message.c_str());
  } catch (const std::exception & error) {
    response.success = false;
    response.message = error.what();
  }
  return response;
}

void PerceptionNode::assign_ids(tower_interfaces::msg::PieceArray & observation)
{
  // Association simple avec l'observation precedente, meme couleur et centre proche.
  std::vector<bool> used(previous_.pieces.size(), false);
  for (auto & piece : observation.pieces) {
    std::size_t nearest = previous_.pieces.size();
    double best_distance = tracking_distance_;
    if (previous_.header.frame_id == observation.header.frame_id) {
      for (std::size_t i = 0; i < previous_.pieces.size(); ++i) {
        const auto & old = previous_.pieces[i];
        if (used[i] || old.color != piece.color) {
          continue;
        }
        const auto & a = piece.pose.pose.position;
        const auto & b = old.pose.pose.position;
        const double distance = std::hypot(std::hypot(a.x - b.x, a.y - b.y), a.z - b.z);
        if (distance < best_distance) {
          best_distance = distance;
          nearest = i;
        }
      }
    }
    if (nearest < previous_.pieces.size()) {
      piece.id = previous_.pieces[nearest].id;
      used[nearest] = true;
    } else {
      piece.id = next_id_++;
    }
  }
  previous_ = observation;
}
}  // namespace tower_perception
