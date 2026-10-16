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
  // A 1 m et fx=500 : environ 25 px pour 5 cm, et 15 px pour le cylindre.
  cv::rectangle(bgr, {60, 60, 26, 26}, {0, 0, 255}, cv::FILLED);
  cv::rectangle(bgr, {160, 60, 26, 26}, {0, 0, 255}, cv::FILLED);
  cv::rectangle(bgr, {260, 180, 41, 26}, {255, 0, 0}, cv::FILLED);
  cv::circle(bgr, {460, 300}, 8, {0, 255, 0}, cv::FILLED);
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
  return GeometryConfig{};
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
  EXPECT_NEAR(detections[0].box.center.x, 280.0, 1.0);
  config.roi = {600, 400, 100, 100};
  EXPECT_THROW(detect_colors(scene(), config), std::invalid_argument);
}

TEST(ColorDetection, FindsGreenCylinderWithRoughContourAndLyingSilhouette)
{
  cv::Mat bgr = cv::Mat::zeros(400, 600, CV_8UC3);
  std::vector<cv::Point> rough_circle;
  for (int i = 0; i < 180; ++i) {
    const double angle = 2.0 * CV_PI * i / 180.0;
    const double radius = i % 2 == 0 ? 45.0 : 40.0;
    rough_circle.emplace_back(cvRound(120.0 + radius * std::cos(angle)),
      cvRound(120.0 + radius * std::sin(angle)));
  }
  cv::fillPoly(bgr, std::vector<std::vector<cv::Point>>{rough_circle}, {0, 255, 0});
  // Silhouette ovale d'un cylindre couche : la detection 2D reste possible.
  cv::rectangle(bgr, {290, 220}, {350, 280}, {0, 255, 0}, cv::FILLED);
  cv::circle(bgr, {290, 250}, 30, {0, 255, 0}, cv::FILLED);
  cv::circle(bgr, {350, 250}, 30, {0, 255, 0}, cv::FILLED);

  const DetectorConfig config;
  const auto detections = detect_colors(bgr, config);
  ASSERT_EQ(detections.size(), 2U);
  EXPECT_EQ(detections[0].shape, Shape::Cylindre);
  EXPECT_EQ(detections[1].shape, Shape::Cylindre);
  EXPECT_NEAR(detections[0].box.center.x, 120.0, 1.0);
  EXPECT_NEAR(detections[1].box.center.x, 320.0, 1.0);
  const auto & contour = detections[0].contour;
  const double perimeter = cv::arcLength(contour, true);
  // Regression : le perimetre brut rejetait cette piece. Le contour reel est conserve.
  EXPECT_LT(4.0 * CV_PI * cv::contourArea(contour) / (perimeter * perimeter),
    config.min_circularity);
}

TEST(ColorDetection, RejectsStronglyConcaveGreenShape)
{
  cv::Mat bgr = cv::Mat::zeros(240, 240, CV_8UC3);
  cv::rectangle(bgr, {60, 60}, {180, 180}, {0, 255, 0}, cv::FILLED);
  cv::rectangle(bgr, {90, 50}, {150, 150}, {0, 0, 0}, cv::FILLED);
  DetectorConfig config;
  EXPECT_TRUE(detect_colors(bgr, config).empty());
  config.min_cylinder_solidity = 0.5;
  EXPECT_EQ(detect_colors(bgr, config).size(), 1U);
}

TEST(ColorDetection, KeepsLowSaturationCylinderFace)
{
  cv::Mat hsv = cv::Mat::zeros(240, 320, CV_8UC3);
  cv::rectangle(hsv, {135, 65}, {215, 135}, {70, 110, 150}, cv::FILLED);
  cv::circle(hsv, {215, 100}, 35, {70, 110, 150}, cv::FILLED);
  // Une face claire, semblable aux photos : S=70 au lieu du seuil precedent de 80.
  cv::circle(hsv, {135, 100}, 35, {55, 70, 170}, cv::FILLED);
  // Un reflet peu sature sur le fond ne doit pas devenir une seconde piece.
  cv::circle(hsv, {60, 190}, 20, {55, 30, 170}, cv::FILLED);
  cv::Mat bgr;
  cv::cvtColor(hsv, bgr, cv::COLOR_HSV2BGR);
  const auto detections = detect_colors(bgr, DetectorConfig{});
  ASSERT_EQ(detections.size(), 1U);
  EXPECT_EQ(detections[0].shape, Shape::Cylindre);
  EXPECT_NEAR(detections[0].box.center.x, 175.0, 1.0);
  EXPECT_GE(cv::pointPolygonTest(detections[0].contour, {105, 100}, false), 0.0);
}

TEST(ColorDetection, RemovesThinBackgroundConnectionsAtHighResolution)
{
  cv::Mat bgr = cv::Mat::zeros(1440, 1920, CV_8UC3);
  cv::rectangle(bgr, {600, 600, 240, 150}, {255, 0, 0}, cv::FILLED);
  // Une trainee du fond bleute touche le pave, trop large pour un noyau de 3 pixels.
  cv::rectangle(bgr, {700, 560, 5, 45}, {255, 0, 0}, cv::FILLED);
  DetectorConfig config;
  auto detections = detect_colors(bgr, config);
  ASSERT_EQ(detections.size(), 1U);
  EXPECT_GE(cv::boundingRect(detections[0].contour).y, 598);
  EXPECT_NEAR(detections[0].box.center.y, 674.5, 2.0);
  config.scale_morphology_with_resolution = false;
  detections = detect_colors(bgr, config);
  ASSERT_EQ(detections.size(), 1U);
  EXPECT_LE(cv::boundingRect(detections[0].contour).y, 561);
}

TEST(ColorDetection, ScalesAreaThresholdWithRoiResolution)
{
  cv::Mat bgr = cv::Mat::zeros(2000, 2000, CV_8UC3);
  cv::rectangle(bgr, {20, 20, 10, 10}, {255, 0, 0}, cv::FILLED);
  cv::rectangle(bgr, {500, 500, 80, 50}, {255, 0, 0}, cv::FILLED);
  DetectorConfig config;
  // Isoler le seuil de surface : le nettoyage adapte filtrerait aussi le carre de 10 px.
  config.scale_morphology_with_resolution = false;
  const auto detections = detect_colors(bgr, config);
  ASSERT_EQ(detections.size(), 1U);
  EXPECT_GT(detections[0].box.center.x, 500.0);
  config.min_area_fraction = 0.0;
  EXPECT_EQ(detect_colors(bgr, config).size(), 2U);
  config = DetectorConfig{};
  config.scale_morphology_with_resolution = false;
  config.roi = {10, 10, 800, 800};
  EXPECT_EQ(detect_colors(bgr, config).size(), 2U);
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
  EXPECT_DOUBLE_EQ(cube.dimensions.x, 0.05);
  EXPECT_DOUBLE_EQ(cube.dimensions.x, cube.dimensions.z);
  EXPECT_NEAR(cube.pose.pose.position.x, (72.5 - 320.0) / 500.0, 0.001);
  EXPECT_NEAR(cube.pose.pose.position.z, 1.0 + cube.dimensions.z / 2.0, 1e-6);
  const auto & rectangle = result.observation.pieces[2];
  EXPECT_EQ(rectangle.color, "blue");
  EXPECT_DOUBLE_EQ(rectangle.dimensions.x, 0.08);
  EXPECT_DOUBLE_EQ(rectangle.dimensions.y, 0.05);
  EXPECT_DOUBLE_EQ(rectangle.dimensions.z, 0.025);
  EXPECT_NEAR(rectangle.pose.pose.position.z, 1.0125, 1e-6);
  const auto & cylinder = result.observation.pieces[3];
  EXPECT_EQ(cylinder.color, "green");
  EXPECT_DOUBLE_EQ(cylinder.dimensions.x, 0.03);
  EXPECT_DOUBLE_EQ(cylinder.dimensions.x, cylinder.dimensions.y);
  EXPECT_DOUBLE_EQ(cylinder.dimensions.z, 0.06);
  EXPECT_NEAR(cylinder.pose.pose.position.z, 1.03, 1e-6);
  for (const auto & piece : result.observation.pieces) {
    EXPECT_EQ(piece.pose.header, result.observation.header);
    const auto & q = piece.pose.pose.orientation;
    EXPECT_NEAR(q.x*q.x + q.y*q.y + q.z*q.z + q.w*q.w, 1.0, 1e-9);
    EXPECT_GE(piece.confidence, 0.0F);
    EXPECT_LE(piece.confidence, 1.0F);
  }
  EXPECT_FALSE(result.debug_image.empty());
}

TEST(Scene, ConfiguredDimensionsOverrideDefaults)
{
  const auto info = calibration();
  auto config = geometry();
  config.cube_side = 0.06;
  config.rectangle_length = 0.09;
  config.rectangle_width = 0.04;
  config.rectangle_height = 0.03;
  config.cylinder_diameter = 0.04;
  config.cylinder_height = 0.07;
  const auto result = analyze_scene(scene(), cv::Mat(480, 640, CV_32FC1, cv::Scalar(1.0)),
    info, info.header, DetectorConfig{}, config);
  ASSERT_EQ(result.observation.pieces.size(), 4U);
  const auto & cube = result.observation.pieces[0];
  EXPECT_DOUBLE_EQ(cube.dimensions.x, 0.06);
  EXPECT_DOUBLE_EQ(cube.dimensions.y, 0.06);
  EXPECT_DOUBLE_EQ(cube.dimensions.z, 0.06);
  const auto & rectangle = result.observation.pieces[2];
  EXPECT_DOUBLE_EQ(rectangle.dimensions.x, 0.09);
  EXPECT_DOUBLE_EQ(rectangle.dimensions.y, 0.04);
  EXPECT_DOUBLE_EQ(rectangle.dimensions.z, 0.03);
  const auto & cylinder = result.observation.pieces[3];
  EXPECT_DOUBLE_EQ(cylinder.dimensions.x, 0.04);
  EXPECT_DOUBLE_EQ(cylinder.dimensions.y, 0.04);
  EXPECT_DOUBLE_EQ(cylinder.dimensions.z, 0.07);
  EXPECT_NEAR(cube.pose.pose.position.z, 1.03, 1e-6);
  EXPECT_NEAR(rectangle.pose.pose.position.z, 1.015, 1e-6);
  EXPECT_NEAR(cylinder.pose.pose.position.z, 1.035, 1e-6);
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

TEST(Scene, RejectsInvalidDimensionsAndCalibration)
{
  auto info = calibration();
  cv::Mat depth(480, 640, CV_32FC1, cv::Scalar(1.0));
  auto invalid_geometry = geometry();
  invalid_geometry.rectangle_height = 0.0;
  EXPECT_THROW(analyze_scene(scene(), depth, info, info.header,
    DetectorConfig{}, invalid_geometry), std::invalid_argument);
  const auto header = info.header;
  info.width = 320;
  EXPECT_THROW(analyze_scene(scene(), depth, info, header,
    DetectorConfig{}, geometry()), std::invalid_argument);
  info = calibration();
  info.k[0] = 0;
  EXPECT_THROW(analyze_scene(scene(), depth, info, header,
    DetectorConfig{}, geometry()), std::invalid_argument);
}
