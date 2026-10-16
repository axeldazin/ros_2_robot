#include "tower_model/ros_conversion.hpp"

#include <cmath>
#include <stdexcept>

namespace tower_model
{

tower_interfaces::msg::Piece to_message(
  const Piece & piece,
  const geometry_msgs::msg::PoseStamped & pose,
  float confidence)
{
  if (!std::isfinite(confidence) || confidence < 0.0F || confidence > 1.0F) {
    throw std::invalid_argument("La confiance doit etre comprise entre 0 et 1.");
  }

  tower_interfaces::msg::Piece message;
  message.id = piece.id();
  message.color = piece.couleur();
  message.pose = pose;
  message.dimensions.x = piece.dimensions().longueur;
  message.dimensions.y = piece.dimensions().largeur;
  message.dimensions.z = piece.dimensions().hauteur;
  message.confidence = confidence;
  return message;
}

}  // namespace tower_model
