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

catkin_package(
        CATKIN_DEPENDS
        roscpp
        geometry_msgs
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

add_executable(${PROJECT_NAME} ${sources})

target_link_libraries(
        ${PROJECT_NAME}
        ${catkin_LIBRARIES}
        ${OMPL_LIBRARIES}
        ${LAPACK_LIBRARIES}
)
