# generated from rosidl_cmake/cmake/rosidl_cmake_aggregate_target-extras.cmake.in

# Create a convenience aggregate target tower_interfaces::tower_interfaces
# that links all generated interface targets, so downstream packages can use
# a single modern CMake target name instead of ${tower_interfaces_TARGETS}.
if(tower_interfaces_TARGETS AND NOT TARGET tower_interfaces::tower_interfaces)
  add_library(tower_interfaces::tower_interfaces INTERFACE IMPORTED)
  set_target_properties(tower_interfaces::tower_interfaces PROPERTIES
    INTERFACE_LINK_LIBRARIES "${tower_interfaces_TARGETS}")
endif()
