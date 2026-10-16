cmake_minimum_required(VERSION 3.8)
project(tower_interfaces)

find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(action_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(std_msgs REQUIRED)

# ROS genere les types C++ et Python a partir de ces definitions.
# Ce package ne contient pas de noeud executable.
rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/Piece.msg"
  "msg/PieceArray.msg"
  "msg/TowerState.msg"
  "srv/SetBuildingEnabled.srv"
  "action/PickAndPlace.action"
  DEPENDENCIES action_msgs geometry_msgs std_msgs
)

install(FILES README.md
  DESTINATION share/${PROJECT_NAME}
)

ament_export_dependencies(rosidl_default_runtime)
ament_package()
