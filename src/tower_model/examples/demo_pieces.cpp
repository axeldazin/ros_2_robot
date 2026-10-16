#include <iostream>
#include <memory>
#include <vector>

#include "tower_model/cube.hpp"
#include "tower_model/cylindre.hpp"
#include "tower_model/rectangle.hpp"
#include "tower_model/ros_conversion.hpp"

int main()
{
  using namespace tower_model;

  // Un seul conteneur peut contenir les trois classes grace a la classe mere.
  std::vector<std::unique_ptr<Piece>> pieces;
  pieces.push_back(std::make_unique<Cube>(1, 0.05));
  pieces.push_back(std::make_unique<Rectangle>(2, 0.08, 0.05, 0.025));
  pieces.push_back(std::make_unique<Cylindre>(3, 0.015, 0.06));  // Rayon = diametre / 2.

  // Pose illustrative uniquement : repere de table fictif et centre a mi-hauteur.
  // Dans un noeud, utiliser la pose et la date de mesure fournies par la perception.
  for (const auto & piece : pieces) {
    geometry_msgs::msg::PoseStamped pose;
    pose.header.frame_id = "table_demo";
    pose.pose.position.z = piece->dimensions().hauteur / 2.0;
    pose.pose.orientation.w = 1.0;
    const auto message = to_message(*piece, pose, 0.95F);

    std::cout << "Piece " << piece->id() << " : " << piece->forme()
              << ", couleur=" << piece->couleur()
              << ", volume=" << piece->volume() << " m3"
              << ", dimensions ROS=[" << message.dimensions.x << ", "
              << message.dimensions.y << ", " << message.dimensions.z << "] m\n";
  }
}
