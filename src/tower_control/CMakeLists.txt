cmake_minimum_required(VERSION 3.8)
project(tower_control)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(tower_interfaces REQUIRED)

add_executable(tower_controller src/tower_controller.cpp)
target_compile_features(tower_controller PRIVATE cxx_std_17)
ament_target_dependencies(tower_controller rclcpp tower_interfaces)

install(TARGETS tower_controller
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}
)
install(FILES README.md DESTINATION share/${PROJECT_NAME})

ament_package()
