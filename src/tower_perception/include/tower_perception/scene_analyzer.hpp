#ifndef TOWER_PERCEPTION__SCENE_ANALYZER_HPP_
#define TOWER_PERCEPTION__SCENE_ANALYZER_HPP_

#include <opencv2/core.hpp>
#include "sensor_msgs/msg/camera_info.hpp"
#include "tower_interfaces/msg/piece_array.hpp"
#include "tower_perception/color_detector.hpp"

namespace tower_perception
{
struct GeometryConfig
{
  // Hauteurs reelles : 0 = inconnue, donc analyse refusee si cette forme est presente.
  double rectangle_height = 0.0;
  double cylinder_height = 0.0;
  double min_depth = 0.1;
  double max_depth = 3.0;
  double min_valid_depth_fraction = 0.5;
  // Normale du support VERS LE HAUT, dans le repere optique couleur.
  // Valeur par defaut : camera verticale au-dessus des faces superieures.
  cv::Vec3d table_normal{0.0, 0.0, -1.0};
};

struct SceneResult
{
  tower_interfaces::msg::PieceArray observation;
  cv::Mat debug_image;
};

// 16UC1 : unite configurable, normalement mm. 32FC1 : deja en metres.
cv::Mat depth_in_metres(const cv::Mat & depth, double integer_depth_scale);

// Projection des faces superieures. Les poses sont dans le repere optique.
// Toute piece reconnue sans profondeur/hauteur exploitable fait echouer l'analyse.
SceneResult analyze_scene(
  const cv::Mat & bgr, const cv::Mat & depth_metres,
  const sensor_msgs::msg::CameraInfo & camera_info,
  const std_msgs::msg::Header & header,
  const DetectorConfig & detector, const GeometryConfig & geometry);
}  // namespace tower_perception
#endif
