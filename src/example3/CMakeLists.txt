cmake_minimum_required(VERSION 2.8.3)
project(example3)

## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS roscpp rospy message_generation)

## Generate messages in the 'msg' folder
add_message_files(FILES laser.msg)

## Generate added messages and services with any dependencies listed here
generate_messages(DEPENDENCIES std_msgs)

catkin_package(CATKIN_DEPENDS message_runtime)

## Specify additional locations of header files
include_directories(${catkin_INCLUDE_DIRS})

## Declare a C++ executable
add_executable(sensor src/sensor.cpp)
add_executable(robot src/robot.cpp)

## Specify libraries to link a library or executable target against
target_link_libraries(sensor ${catkin_LIBRARIES})
target_link_libraries(robot ${catkin_LIBRARIES})