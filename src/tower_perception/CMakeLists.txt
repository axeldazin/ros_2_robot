cmake_minimum_required(VERSION 3.8)
project(tower_perception)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(image_geometry REQUIRED)
find_package(message_filters REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)
find_package(tower_interfaces REQUIRED)
find_package(tower_model REQUIRED)
find_package(OpenCV REQUIRED COMPONENTS core imgproc)

add_library(piece_detection STATIC src/color_detector.cpp src/scene_analyzer.cpp)
target_compile_features(piece_detection PUBLIC cxx_std_17)
target_include_directories(piece_detection PUBLIC include ${OpenCV_INCLUDE_DIRS})
target_link_libraries(piece_detection ${OpenCV_LIBS} tower_model::tower_model)
ament_target_dependencies(piece_detection sensor_msgs geometry_msgs image_geometry tf2)

add_executable(perception_node src/perception_node.cpp src/main.cpp)
target_link_libraries(perception_node piece_detection)
ament_target_dependencies(perception_node
  rclcpp std_msgs sensor_msgs cv_bridge message_filters tf2_ros tf2_geometry_msgs)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  target_compile_options(piece_detection PRIVATE -Wall -Wextra -Wpedantic)
  target_compile_options(perception_node PRIVATE -Wall -Wextra -Wpedantic)
endif()

if(BUILD_TESTING)
  find_package(ament_cmake_gtest REQUIRED)
  ament_add_gtest(test_detection test/test_detection.cpp)
  target_link_libraries(test_detection piece_detection)
endif()

install(TARGETS perception_node DESTINATION lib/${PROJECT_NAME})
install(PROGRAMS scripts/image_simulator.py
  DESTINATION lib/${PROJECT_NAME}
  RENAME image_simulator
)
install(DIRECTORY launch config DESTINATION share/${PROJECT_NAME})
install(FILES README.md DESTINATION share/${PROJECT_NAME})

ament_package()
