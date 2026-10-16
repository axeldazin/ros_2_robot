#ifndef TOWER_MODEL__ROS_CONVERSION_HPP_
#define TOWER_MODEL__ROS_CONVERSION_HPP_

#include "geometry_msgs/msg/pose_stamped.hpp"
#include "tower_interfaces/msg/piece.hpp"
#include "tower_model/piece.hpp"

namespace tower_model
{

// Ajoute la pose mesuree du CENTRE et la confiance pour creer le message ROS.
// L'appelant fournit une pose valide, datee, dans un repere explicite.
tower_interfaces::msg::Piece to_message(
  const Piece & piece,
  const geometry_msgs::msg::PoseStamped & pose,
  float confidence);

}  // namespace tower_model

#endif  // TOWER_MODEL__ROS_CONVERSION_HPP_
