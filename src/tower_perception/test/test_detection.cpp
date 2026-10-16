#include <cmath>
#include <limits>
#include <stdexcept>
#include "gtest/gtest.h"
#include <opencv2/imgproc.hpp>
#include "tower_perception/scene_analyzer.hpp"

using namespace tower_perception;

namespace
{
cv::Mat scene()
{
  cv::Mat bgr = cv::Mat::zeros(480, 640, CV_8UC3);
  cv::rectangle(bgr, {60, 60, 40, 40}, {0, 0, 255}, cv::FILLED);
  cv::rectangle(bgr, {160, 60, 40, 40}, {0, 0, 255}, cv::FILLED);
  cv::rectangle(bgr, {260, 180, 80, 40}, {255, 0, 0}, cv::FILLED);
  cv::circle(bgr, {460, 300}, 30, {0, 255, 0}, cv::FILLED);
  return bgr;
}

sensor_msgs::msg::CameraInfo calibration()
{
  sensor_msgs::msg::CameraInfo info;
  info.header.frame_id = "camera_color_optical_frame";
  info.header.stamp.sec = 123;
  info.width = 640;
  info.height = 480;
  info.distortion_model = "plumb_bob";
  info.d = {0.0, 0.0, 0.0, 0.0, 0.0};
  info.k = {500, 0, 320, 0, 500, 240, 0, 0, 1};
  info.r = {1, 0, 0, 0, 1, 0, 0, 0, 1};
  info.p = {500, 0, 320, 0, 0, 500, 240, 0, 0, 0, 1, 0};
  return info;
}

GeometryConfig geometry()
{
  GeometryConfig config;
  config.rectangle_height = 0.02;
  config.cylinder_height = 0.05;
  return config;
}
}  // namespace

TEST(ColorDetection, FindsAllFourIncludingTwoOfSameColor)
{
  const auto detections = detect_colors(scene(), DetectorConfig{});
  ASSERT_EQ(detections.size(), 4U);
  EXPECT_EQ(detections[0].shape, Shape::Cube);
  EXPECT_EQ(detections[1].shape, Shape::Cube);
  EXPECT_LT(detections[0].box.center.x, detections[1].box.center.x);
  EXPECT_EQ(detections[2].shape, Shape::Rectangle);
  EXPECT_EQ(detections[3].shape, Shape::Cylindre);
}

TEST(ColorDetection, RedHueWrapAndNoiseFiltering)
{
  cv::Mat hsv = cv::Mat::zeros(160, 160, CV_8UC3);
  cv::rectangle(hsv, {40, 40, 40, 40}, {175, 255, 255}, cv::FILLED);
  cv::rectangle(hsv, {110, 110, 3, 3}, {175, 255, 255}, cv::FILLED);
  cv::Mat bgr;
  cv::cvtColor(hsv, bgr, cv::COLOR_HSV2BGR);
  ASSERT_EQ(detect_colors(bgr, DetectorConfig{}).size(), 1U);
}

TEST(ColorDetection, RejectsTruncatedPiecesAndWrongRedAspect)
{
  cv::Mat bgr = cv::Mat::zeros(200, 300, CV_8UC3);
  cv::rectangle(bgr, {0, 30, 40, 40}, {0, 0, 255}, cv::FILLED);
  cv::rectangle(bgr, {80, 80, 150, 20}, {0, 0, 255}, cv::FILLED);
  EXPECT_TRUE(detect_colors(bgr, DetectorConfig{}).empty());
}

TEST(ColorDetection, RoiKeepsCoordinatesInFullImage)
{
  DetectorConfig config;
  config.roi = {230, 150, 150, 120};
  const auto detections = detect_colors(scene(), config);
  ASSERT_EQ(detections.size(), 1U);
  EXPECT_EQ(detections[0].shape, Shape::Rectangle);
  EXPECT_NEAR(detections[0].box.center.x, 299.5, 1.0);
  config.roi = {600, 400, 100, 100};
  EXPECT_THROW(detect_colors(scene(), config), std::invalid_argument);
}

TEST(Depth, ConvertsMillimetresAndPreservesMetres)
{
  cv::Mat integer_depth(10, 10, CV_16UC1, cv::Scalar(1250));
  EXPECT_FLOAT_EQ(depth_in_metres(integer_depth, 0.001).at<float>(0, 0), 1.25F);
  cv::Mat float_depth(10, 10, CV_32FC1, cv::Scalar(1.25));
  EXPECT_FLOAT_EQ(depth_in_metres(float_depth, 0.001).at<float>(0, 0), 1.25F);
  EXPECT_THROW(depth_in_metres(cv::Mat(10, 10, CV_8UC1), 0.001), std::invalid_argument);
}

TEST(Scene, ProducesMetricObjectCentersAndNormalizedOrientations)
{
  const auto info = calibration();
  const auto result = analyze_scene(scene(), cv::Mat(480, 640, CV_32FC1, cv::Scalar(1.0)),
    info, info.header, DetectorConfig{}, geometry());
  ASSERT_EQ(result.observation.pieces.size(), 4U);
  const auto & cube = result.observation.pieces[0];
  EXPECT_EQ(cube.color, "red");
  EXPECT_NEAR(cube.dimensions.x, 0.078, 0.002);
  EXPECT_DOUBLE_EQ(cube.dimensions.x, cube.dimensions.z);
  EXPECT_NEAR(cube.pose.pose.position.x, (79.5 - 320.0) / 500.0, 0.001);
  EXPECT_NEAR(cube.pose.pose.position.z, 1.0 + cube.dimensions.z / 2.0, 1e-6);
  const auto & rectangle = result.observation.pieces[2];
  EXPECT_EQ(rectangle.color, "blue");
  EXPECT_NEAR(rectangle.dimensions.x, 0.158, 0.002);
  EXPECT_NEAR(rectangle.dimensions.y, 0.078, 0.002);
  EXPECT_DOUBLE_EQ(rectangle.dimensions.z, 0.02);
  EXPECT_NEAR(rectangle.pose.pose.position.z, 1.01, 1e-6);
  const auto & cylinder = result.observation.pieces[3];
  EXPECT_EQ(cylinder.color, "green");
  EXPECT_NEAR(cylinder.dimensions.x, 0.12, 0.004);
  EXPECT_DOUBLE_EQ(cylinder.dimensions.x, cylinder.dimensions.y);
  EXPECT_NEAR(cylinder.pose.pose.position.z, 1.025, 1e-6);
  for (const auto & piece : result.observation.pieces) {
    EXPECT_EQ(piece.pose.header, result.observation.header);
    const auto & q = piece.pose.pose.orientation;
    EXPECT_NEAR(q.x*q.x + q.y*q.y + q.z*q.z + q.w*q.w, 1.0, 1e-9);
    EXPECT_GE(piece.confidence, 0.0F);
    EXPECT_LE(piece.confidence, 1.0F);
  }
  EXPECT_FALSE(result.debug_image.empty());
}

TEST(Scene, EmptySceneIsSuccessfulObservation)
{
  const auto info = calibration();
  const auto result = analyze_scene(cv::Mat::zeros(480, 640, CV_8UC3),
    cv::Mat::zeros(480, 640, CV_32FC1), info, info.header, DetectorConfig{}, GeometryConfig{});
  EXPECT_TRUE(result.observation.pieces.empty());
  EXPECT_EQ(result.observation.header, info.header);
}

TEST(Scene, RejectsMissingDepthRatherThanInventingPose)
{
  const auto info = calibration();
  cv::Mat depth(480, 640, CV_32FC1, cv::Scalar(1.0));
  // Les autres pieces sont valides : aucun vecteur partiel ne doit etre retourne.
  cv::rectangle(depth, {250, 170, 100, 60}, cv::Scalar(0), cv::FILLED);
  EXPECT_THROW(analyze_scene(scene(), depth, info, info.header,
    DetectorConfig{}, geometry()), std::runtime_error);
  depth.setTo(std::numeric_limits<float>::quiet_NaN());
  EXPECT_THROW(analyze_scene(scene(), depth, info, info.header,
    DetectorConfig{}, geometry()), std::runtime_error);
}

TEST(Scene, RequiresKnownHeightsAndMatchingCalibration)
{
  auto info = calibration();
  cv::Mat depth(480, 640, CV_32FC1, cv::Scalar(1.0));
  EXPECT_THROW(analyze_scene(scene(), depth, info, info.header,
    DetectorConfig{}, GeometryConfig{}), std::runtime_error);
  const auto header = info.header;
  info.width = 320;
  EXPECT_THROW(analyze_scene(scene(), depth, info, header,
    DetectorConfig{}, geometry()), std::invalid_argument);
  info = calibration();
  info.k[0] = 0;
  EXPECT_THROW(analyze_scene(scene(), depth, info, header,
    DetectorConfig{}, geometry()), std::invalid_argument);
}
