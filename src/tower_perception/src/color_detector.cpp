#include "tower_perception/color_detector.hpp"

#include <algorithm>
#include <cmath>
#include <stdexcept>
#include <tuple>
#include <opencv2/imgproc.hpp>

namespace tower_perception
{
std::vector<Detection2D> detect_colors(const cv::Mat & bgr, const DetectorConfig & config)
{
  if (bgr.empty() || bgr.type() != CV_8UC3) {
    throw std::invalid_argument("L'image couleur doit etre BGR8 et non vide.");
  }
  const cv::Rect full(0, 0, bgr.cols, bgr.rows);
  const cv::Rect roi = config.roi.empty() ? full : config.roi;
  if ((roi & full) != roi) {
    throw std::invalid_argument("La zone d'analyse sort de l'image.");
  }

  cv::Mat hsv;
  cv::cvtColor(bgr(roi), hsv, cv::COLOR_BGR2HSV);
  const double min_area = std::max(config.min_area,
    config.min_area_fraction * static_cast<double>(roi.width) * roi.height);
  cv::Mat kernel;
  if (config.morphology_size > 1) {
    // 3 pixels a 640x480 correspondent a 19 pixels sur une photo 3024x4032.
    // Utiliser la resolution complete pour garder le meme nettoyage si la ROI change.
    const double scale = config.scale_morphology_with_resolution ?
      std::max(1.0, std::min(bgr.cols, bgr.rows) / 480.0) : 1.0;
    const int kernel_size = cvRound(config.morphology_size * scale) | 1;
    kernel = cv::getStructuringElement(cv::MORPH_ELLIPSE, {kernel_size, kernel_size});
  }
  std::vector<Detection2D> detections;
  for (int shape_index = 0; shape_index < 3; ++shape_index) {
    cv::Mat mask;
    const int range_index = shape_index == 0 ? 0 : shape_index + 1;
    const auto & range = config.ranges[range_index];
    cv::inRange(hsv, range.low, range.high, mask);
    if (shape_index == 0) {
      cv::Mat second_red;
      cv::inRange(hsv, config.ranges[1].low, config.ranges[1].high, second_red);
      cv::bitwise_or(mask, second_red, mask);
    }
    if (!kernel.empty()) {
      cv::morphologyEx(mask, mask, cv::MORPH_OPEN, kernel);
      cv::morphologyEx(mask, mask, cv::MORPH_CLOSE, kernel);
    }

    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(mask, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
    for (auto contour : contours) {
      const double area = cv::contourArea(contour);
      if (area < min_area) {
        continue;
      }
      const auto bounds = cv::boundingRect(contour);
      // Ignorer une piece coupee par le bord de la zone d'analyse.
      if (bounds.x <= 0 || bounds.y <= 0 || bounds.br().x >= roi.width ||
        bounds.br().y >= roi.height)
      {
        continue;
      }
      for (auto & point : contour) {
        point += roi.tl();
      }
      const auto box = cv::minAreaRect(contour);
      const double small = std::min(box.size.width, box.size.height);
      const double large = std::max(box.size.width, box.size.height);
      if (small <= 0.0) {
        continue;
      }
      const double fill = area / box.size.area();
      if (shape_index == 0 && (large / small > config.max_cube_aspect ||
        fill < config.min_fill))
      {
        continue;
      }
      if (shape_index == 1 && fill < config.min_fill) {
        continue;
      }
      double score = fill;
      if (shape_index == 2) {
        // Les asperites de la surface imprimee gonflent le perimetre brut.
        // L'enveloppe conserve la forme globale, ronde ou ovale, du cylindre.
        std::vector<cv::Point> hull;
        cv::convexHull(contour, hull);
        const double hull_area = cv::contourArea(hull);
        const double perimeter = cv::arcLength(hull, true);
        const double circularity = 4.0 * CV_PI * hull_area / (perimeter * perimeter);
        const double solidity = area / hull_area;
        // Une forme tres creuse ne doit pas devenir un cylindre en comblant ses creux.
        if (circularity < config.min_circularity || solidity < config.min_cylinder_solidity) {
          continue;
        }
        score = circularity * solidity;
      }
      // Garder le contour reel pour ne pas echantillonner le fond dans la profondeur.
      detections.push_back({static_cast<Shape>(shape_index), box, contour,
        static_cast<float>(std::clamp(score, 0.0, 1.0))});
    }
  }
  std::sort(detections.begin(), detections.end(), [](const auto & a, const auto & b) {
    return std::tie(a.shape, a.box.center.x, a.box.center.y) <
           std::tie(b.shape, b.box.center.x, b.box.center.y);
  });
  return detections;
}
}  // namespace tower_perception
