cmake_minimum_required(VERSION 2.8.3)
project(database)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake-modules)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)


## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
)


find_package(MySqlClient REQUIRED)

include_directories(include ${catkin_INCLUDE_DIRS})


include_directories(${MYSQL_INCLUDE_DIRS})

add_definitions(${MYSQL_DEFINITIONS})


add_executable(first src/first.cpp)
target_link_libraries(first ${catkin_LIBRARIES})





target_link_libraries(first
   ${catkin_LIBRARIES}
   ${MYSQL_LIBRARIES}
)



