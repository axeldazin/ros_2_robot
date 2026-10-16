#ifndef TOWER_PERCEPTION__COLOR_DETECTOR_HPP_
#define TOWER_PERCEPTION__COLOR_DETECTOR_HPP_

#include <array>
#include <vector>
#include <opencv2/core.hpp>

namespace tower_perception
{
enum class Shape {Cube, Rectangle, Cylindre};

struct HsvRange
{
  cv::Scalar low;
  cv::Scalar high;
};

struct DetectorConfig
{
  // HSV OpenCV : H de 0 a 179, S et V de 0 a 255.
  // Le rouge traverse la coupure H=0 : deux plages sont necessaires.
  std::array<HsvRange, 4> ranges{{
    {{0, 80, 50}, {10, 255, 255}},
    {{170, 80, 50}, {179, 255, 255}},
    {{95, 80, 50}, {135, 255, 255}},
    {{35, 80, 50}, {85, 255, 255}}
  }};
  double min_area = 200.0;
  double min_fill = 0.7;
  double min_circularity = 0.65;
  double max_cube_aspect = 1.4;
  int morphology_size = 3;
  cv::Rect roi;  // Rectangle vide = image entiere.
};

struct Detection2D
{
  Shape shape;
  cv::RotatedRect box;  // box.center = centre 2D (u, v) en pixels dans l'image complete.
  std::vector<cv::Point> contour;
  float shape_score;
};

// Un element par contour colore compatible avec la forme attendue.
std::vector<Detection2D> detect_colors(const cv::Mat & bgr, const DetectorConfig & config);
}  // namespace tower_perception
#endif
