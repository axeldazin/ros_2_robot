#include "sorting/sorting.hpp"

#include <algorithm>
#include <functional>

std::string sort_letters(std::string text)
{
  std::sort(text.begin(), text.end());
  return text;
}

Sorting::Sorting()
: Node("sorting")
{
    enabled_ = declare_parameter<bool>("enabled_at_startup", true);
    
  publisher_ = create_publisher<std_msgs::msg::String>("/sorted", 10);

  subscription_ = create_subscription<std_msgs::msg::String>(
    "/hello", 10,
    std::bind(&Sorting::receive_message, this, std::placeholders::_1));

  service_ = create_service<sorting_msgs::srv::ToggleSorting>(
    "/toggle_sorting",
    std::bind(
      &Sorting::toggle_sorting, this,
      std::placeholders::_1, std::placeholders::_2));
}

void Sorting::receive_message(
  const std_msgs::msg::String::SharedPtr message)
{
  if (!enabled_) {
    return;
  }

  std_msgs::msg::String result;
  result.data = sort_letters(message->data);
  publisher_->publish(result);

  RCLCPP_INFO(get_logger(), "Sorted: '%s'", result.data.c_str());
}

void Sorting::toggle_sorting(
  const std::shared_ptr<sorting_msgs::srv::ToggleSorting::Request> /* request */,
  std::shared_ptr<sorting_msgs::srv::ToggleSorting::Response> response)
{
  enabled_ = !enabled_;

  response->enabled = enabled_;
  response->message = enabled_ ? "Sorting enabled" : "Sorting disabled";

  RCLCPP_INFO(get_logger(), "%s", response->message.c_str());
}
