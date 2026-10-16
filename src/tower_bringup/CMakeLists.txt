cmake_minimum_required(VERSION 3.8)
project(sorting)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(sorting_msgs REQUIRED)

add_executable(sorting_node
  src/sorting_node.cpp
  src/sorting.cpp
)

target_compile_features(sorting_node PRIVATE cxx_std_17)
target_include_directories(sorting_node PRIVATE include)

ament_target_dependencies(sorting_node
  rclcpp
  std_msgs
  sorting_msgs
)

install(TARGETS sorting_node
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}
)

ament_package()
