#ifndef SORTING__SORTING_HPP_
#define SORTING__SORTING_HPP_

#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "sorting_msgs/srv/toggle_sorting.hpp"

// Fonction de tri indépendante de ROS.
std::string sort_letters(std::string text);

class Sorting : public rclcpp::Node
{
public:
  Sorting();

private:
  void receive_message(const std_msgs::msg::String::SharedPtr message);

  void toggle_sorting(
    const std::shared_ptr<sorting_msgs::srv::ToggleSorting::Request> request,
    std::shared_ptr<sorting_msgs::srv::ToggleSorting::Response> response);

  bool enabled_ = true;

  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
  rclcpp::Service<sorting_msgs::srv::ToggleSorting>::SharedPtr service_;
};

#endif  // SORTING__SORTING_HPP_
