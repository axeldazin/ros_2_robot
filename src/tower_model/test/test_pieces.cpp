#include <cmath>
#include <limits>
#include <memory>
#include <stdexcept>
#include <type_traits>
#include <vector>

#include "gtest/gtest.h"
#include "tower_model/cube.hpp"
#include "tower_model/cylindre.hpp"
#include "tower_model/rectangle.hpp"
#include "tower_model/ros_conversion.hpp"

using namespace tower_model;

static_assert(std::is_abstract<Piece>::value, "Piece doit rester abstraite.");
static_assert(std::has_virtual_destructor<Piece>::value, "Destruction polymorphe requise.");

TEST(Pieces, PolymorphismAndFixedColors)
{
  std::vector<std::unique_ptr<Piece>> pieces;
  pieces.push_back(std::make_unique<Cube>(1, 0.04));
  pieces.push_back(std::make_unique<Rectangle>(2, 0.06, 0.04, 0.02));
  pieces.push_back(std::make_unique<Cylindre>(3, 0.02, 0.05));

  EXPECT_EQ(pieces[0]->forme(), "cube");
  EXPECT_EQ(pieces[0]->couleur(), "red");
  EXPECT_EQ(pieces[1]->forme(), "rectangle");
  EXPECT_EQ(pieces[1]->couleur(), "blue");
  EXPECT_EQ(pieces[2]->forme(), "cylindre");
  EXPECT_EQ(pieces[2]->couleur(), "green");
  EXPECT_NEAR(pieces[0]->volume(), 0.000064, 1e-12);
  EXPECT_NEAR(pieces[1]->volume(), 0.000048, 1e-12);
  EXPECT_NEAR(pieces[2]->volume(), std::acos(-1.0) * 0.00002, 1e-12);
}

TEST(Pieces, RejectInvalidDimensions)
{
  EXPECT_THROW(Cube(1, 0.0), std::invalid_argument);
  EXPECT_THROW(Rectangle(2, 0.06, -0.04, 0.02), std::invalid_argument);
  EXPECT_THROW(Cylindre(3, -0.02, 0.05), std::invalid_argument);
  EXPECT_THROW(Cylindre(3, 0.02, 0.0), std::invalid_argument);
  EXPECT_THROW(Cube(1, std::numeric_limits<double>::infinity()), std::invalid_argument);
  EXPECT_THROW(Cube(1, std::numeric_limits<double>::quiet_NaN()), std::invalid_argument);
}

TEST(Pieces, RosConversionPreservesMeasurementsAndUsesDiameter)
{
  Cylindre cylindre(42, 0.02, 0.05);
  geometry_msgs::msg::PoseStamped pose;
  pose.header.frame_id = "camera_color_optical_frame";
  pose.header.stamp.sec = 123;
  pose.header.stamp.nanosec = 456;
  pose.pose.position.x = 0.3;
  pose.pose.position.y = -0.1;
  pose.pose.position.z = 0.8;
  pose.pose.orientation.z = std::sin(0.25);
  pose.pose.orientation.w = std::cos(0.25);

  const auto message = to_message(cylindre, pose, 0.95F);
  EXPECT_EQ(message.id, 42U);
  EXPECT_EQ(message.color, "green");
  EXPECT_EQ(message.pose, pose);
  EXPECT_DOUBLE_EQ(message.dimensions.x, 0.04);
  EXPECT_DOUBLE_EQ(message.dimensions.y, 0.04);
  EXPECT_DOUBLE_EQ(message.dimensions.z, 0.05);
  EXPECT_FLOAT_EQ(message.confidence, 0.95F);
  EXPECT_DOUBLE_EQ(cylindre.rayon(), 0.02);
}

TEST(Pieces, ConfidenceBounds)
{
  Cube cube(1, 0.04);
  geometry_msgs::msg::PoseStamped pose;
  EXPECT_NO_THROW(to_message(cube, pose, 0.0F));
  EXPECT_NO_THROW(to_message(cube, pose, 1.0F));
  EXPECT_THROW(to_message(cube, pose, -0.1F), std::invalid_argument);
  EXPECT_THROW(to_message(cube, pose, 1.1F), std::invalid_argument);
  EXPECT_THROW(to_message(cube, pose, std::numeric_limits<float>::quiet_NaN()),
    std::invalid_argument);
}
