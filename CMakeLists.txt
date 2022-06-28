cmake_minimum_required(VERSION 3.5)
project(rrt_star)

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g -O3")
set(CMAKE_CXX_FLAGS_RELEASE "-g -O3")
set(CMAKE_BUILD_TYPE Release)

find_package(
        catkin REQUIRED COMPONENTS
        geometry_msgs
        nav_msgs
        sensor_msgs
        roscpp
        rospy
        std_msgs
)

find_package(Eigen3 REQUIRED)
find_package(ompl REQUIRED)
find_package(LAPACK REQUIRED)

set(CMAKE_CXX_STANDARD 14)

include_directories(
        include
        ${catkin_INCLUDE_DIRS}
        ${OMPL_INCLUDE_DIRS}
        ${EIGEN3_INCLUDE_DIR}
        ${LAPACK_INCLUDE_DIRS}
)

add_service_files(
  FILES
  rrt_star.srv
)

generate_messages(
  DEPENDENCIES
  std_msgs
)

catkin_package(
        CATKIN_DEPENDS
        roscpp
        geometry_msgs
        message_runtime
        nav_msgs
        rospy
        std_msgs
        DEPENDS
        EIGEN3
        LAPACK
)

set(
        sources
        src/main.cpp
        src/RRTPlanning.cpp
        src/ValidityChecker.cpp
        src/MotionValidator.cpp
        src/CubicSpliner.cpp
        src/CubicSpline2D.cpp
)

add_executable(rrt_star ${sources})

target_link_libraries(
        ${PROJECT_NAME}
        ${catkin_LIBRARIES}
        ${OMPL_LIBRARIES}
        ${LAPACK_LIBRARIES}
)

set(
        server_sources
        src/RRTStarServer.cpp
        src/RRTPlanning.cpp
        src/ValidityChecker.cpp
        src/MotionValidator.cpp
        src/CubicSpliner.cpp
        src/CubicSpline2D.cpp
)

add_executable(rrt_star_server ${server_sources})
target_link_libraries(
        rrt_star_server 
        ${catkin_LIBRARIES}
        ${OMPL_LIBRARIES}
        ${LAPACK_LIBRARIES}
)

add_executable(rrt_star_client src/RRTStarClient.cpp)
target_link_libraries(rrt_star_client ${catkin_LIBRARIES})