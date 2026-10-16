cmake_minimum_required(VERSION 3.8)
project(tower_model)

find_package(ament_cmake REQUIRED)
find_package(tower_interfaces REQUIRED)
find_package(geometry_msgs REQUIRED)

add_library(${PROJECT_NAME} SHARED
  src/piece.cpp
  src/cube.cpp
  src/rectangle.cpp
  src/cylindre.cpp
  src/ros_conversion.cpp
)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
target_include_directories(${PROJECT_NAME} PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)
ament_target_dependencies(${PROJECT_NAME} tower_interfaces geometry_msgs)
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)
endif()

add_executable(demo_pieces examples/demo_pieces.cpp)
target_link_libraries(demo_pieces ${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_cmake_gtest REQUIRED)
  ament_add_gtest(test_pieces test/test_pieces.cpp)
  target_link_libraries(test_pieces ${PROJECT_NAME})
endif()

install(TARGETS ${PROJECT_NAME}
  EXPORT export_${PROJECT_NAME}
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)
install(TARGETS demo_pieces DESTINATION lib/${PROJECT_NAME})
install(DIRECTORY include/ DESTINATION include)
install(FILES README.md DESTINATION share/${PROJECT_NAME})

ament_export_targets(export_${PROJECT_NAME} HAS_LIBRARY_TARGET)
ament_export_dependencies(tower_interfaces geometry_msgs)
ament_package()
