# CMake generated Testfile for 
# Source directory: /net/netud/s/adazin/Bureau/ros_2_robot/src/tower_model
# Build directory: /net/netud/s/adazin/Bureau/ros_2_robot/build/tower_model
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(test_pieces "/usr/bin/python3" "-u" "/opt/ros/jazzy/share/ament_cmake_test/cmake/run_test.py" "/net/netud/s/adazin/Bureau/ros_2_robot/build/tower_model/test_results/tower_model/test_pieces.gtest.xml" "--package-name" "tower_model" "--output-file" "/net/netud/s/adazin/Bureau/ros_2_robot/build/tower_model/ament_cmake_gtest/test_pieces.txt" "--command" "/net/netud/s/adazin/Bureau/ros_2_robot/build/tower_model/test_pieces" "--gtest_output=xml:/net/netud/s/adazin/Bureau/ros_2_robot/build/tower_model/test_results/tower_model/test_pieces.gtest.xml")
set_tests_properties(test_pieces PROPERTIES  LABELS "gtest" REQUIRED_FILES "/net/netud/s/adazin/Bureau/ros_2_robot/build/tower_model/test_pieces" TIMEOUT "60" WORKING_DIRECTORY "/net/netud/s/adazin/Bureau/ros_2_robot/build/tower_model" _BACKTRACE_TRIPLES "/opt/ros/jazzy/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/jazzy/share/ament_cmake_gtest/cmake/ament_add_gtest_test.cmake;95;ament_add_test;/opt/ros/jazzy/share/ament_cmake_gtest/cmake/ament_add_gtest.cmake;93;ament_add_gtest_test;/net/netud/s/adazin/Bureau/ros_2_robot/src/tower_model/CMakeLists.txt;30;ament_add_gtest;/net/netud/s/adazin/Bureau/ros_2_robot/src/tower_model/CMakeLists.txt;0;")
subdirs("gtest")
