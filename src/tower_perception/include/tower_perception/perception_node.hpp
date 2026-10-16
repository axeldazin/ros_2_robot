#ifndef TOWER_PERCEPTION__PERCEPTION_NODE_HPP_
#define TOWER_PERCEPTION__PERCEPTION_NODE_HPP_

#include <memory>
#include <string>
#include "rclcpp/rclcpp.hpp"
#include "message_filters/subscriber.hpp"
#include "message_filters/synchronizer.hpp"
#include "message_filters/sync_policies/approximate_time.hpp"
#include "sensor_msgs/msg/image.hpp"
#include "std_msgs/msg/empty.hpp"
#include "tf2_ros/buffer.hpp"
#include "tf2_ros/transform_listener.hpp"
#include "tower_interfaces/srv/analyze_image.hpp"
#include "tower_perception/scene_analyzer.hpp"

namespace tower_perception
{
class PerceptionNode : public rclcpp::Node
{
public:
  explicit PerceptionNode(const rclcpp::NodeOptions & options = rclcpp::NodeOptions());

private:
  using Image = sensor_msgs::msg::Image;
  using AnalyzeImage = tower_interfaces::srv::AnalyzeImage;
  using SyncPolicy = message_filters::sync_policies::ApproximateTime<Image, Image>;

  // Les parametres sont charges au demarrage ; un changement exige un redemarrage.
  template<typename T>
  T startup_parameter(const std::string & name, const T & value)
  {
    rcl_interfaces::msg::ParameterDescriptor descriptor;
    descriptor.read_only = true;
    return declare_parameter<T>(name, value, descriptor);
  }

  AnalyzeImage::Response analyze();
  void on_images(const Image::ConstSharedPtr & color, const Image::ConstSharedPtr & depth);
  void assign_ids(tower_interfaces::msg::PieceArray & observation);

  DetectorConfig detector_;
  GeometryConfig geometry_;
  double depth_scale_;
  double max_age_;
  double tracking_distance_;
  std::string output_frame_;
  std::uint32_t next_id_ = 1;
  tower_interfaces::msg::PieceArray previous_;

  Image::ConstSharedPtr color_;
  Image::ConstSharedPtr depth_;
  sensor_msgs::msg::CameraInfo::ConstSharedPtr camera_info_;
  message_filters::Subscriber<Image> color_sub_;
  message_filters::Subscriber<Image> depth_sub_;
  std::shared_ptr<message_filters::Synchronizer<SyncPolicy>> synchronizer_;
  rclcpp::Subscription<sensor_msgs::msg::CameraInfo>::SharedPtr camera_info_sub_;
  rclcpp::Subscription<std_msgs::msg::Empty>::SharedPtr trigger_sub_;
  rclcpp::Publisher<tower_interfaces::msg::PieceArray>::SharedPtr pieces_pub_;
  rclcpp::Publisher<Image>::SharedPtr debug_pub_;
  rclcpp::Service<AnalyzeImage>::SharedPtr service_;
  std::unique_ptr<tf2_ros::Buffer> tf_buffer_;
  std::shared_ptr<tf2_ros::TransformListener> tf_listener_;
};
}  // namespace tower_perception
#endif
