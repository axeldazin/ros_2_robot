#include <exception>
#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "tower_perception/perception_node.hpp"

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  try {
    rclcpp::spin(std::make_shared<tower_perception::PerceptionNode>());
  } catch (const std::exception & error) {
    RCLCPP_ERROR(rclcpp::get_logger("perception_node"), "%s", error.what());
    rclcpp::shutdown();
    return 1;
  }
  rclcpp::shutdown();
  return 0;
}
