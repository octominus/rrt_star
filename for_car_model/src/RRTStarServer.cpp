#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

#include "ros/ros.h"
#include "RRTPlanning.h"
#include "rrt_star/rrt_star.h"

#include <nav_msgs/OccupancyGrid.h>
#include <nav_msgs/Path.h>

uint8_t canPublish = 0;

nav_msgs::OccupancyGrid::ConstPtr map;
nav_msgs::Path exact_path;
nav_msgs::Path curved_path;

bool CheckCurvedPath(const nav_msgs::OccupancyGrid::ConstPtr &map, const nav_msgs::Path path) {
    uint path_size = path.poses.size();
    float path_x = 0.0;
    float path_y = 0.0;
    for (uint i = 0; i < path_size; i++) {
        path_x = path.poses[i].pose.position.x;
        path_y = path.poses[i].pose.position.y;
        int x_pixel = std::floor(path_x / map->info.resolution);
        int y_pixel = std::floor(path_y / map->info.resolution);
        int pixel_index = x_pixel + (y_pixel * map->info.width);
        int pixel_data = map->data[pixel_index];
        if (pixel_data > 80) {
            return 1;
        }
    }
    return 0;
}

bool RRTStarCalculator(rrt_star::rrt_star::Request  &req, rrt_star::rrt_star::Response &res) {
    float calculation_time;
    float desired_time = 0.0;

    std::vector<float> start = {req.X1, req.Y1};
    std::vector<float> goal = {req.X2, req.Y2};

    if (req.time_type == "ms") {
        desired_time = req.time / 1000;
    } else if (req.time_type == "s") {
        desired_time = req.time;
    }

    ROS_INFO("\n\033[1;37mDesired Points:\033[0m\n\t\033[1;31mStart:\033[m (%.2f, %.2f)\n\t\033[1;32mGoal:\033[m (%.2f, %.2f)\n\t\033[1;31mTime:\033[m %.1f%s", req.X1, req.Y1, req.X2, req.Y2, req.time, req.time_type.c_str());
    
    RRTPlanning planner;
    planner.setTime(desired_time);
    uint8_t isSolved = planner.FindPath(map, start, goal);

    if (isSolved) {
        exact_path = planner.GetExactPath();
        curved_path = planner.GetCurvedPath();
        calculation_time += planner.getTime();
        bool intersection = CheckCurvedPath(map, curved_path);
        while (intersection) {            
            planner.FindPath(map, start, goal);
            exact_path = planner.GetExactPath();
            curved_path = planner.GetCurvedPath();
            intersection = CheckCurvedPath(map, curved_path);
            calculation_time += planner.getTime();
            printf("\033[1;31mTrying to find best path for moving!\033[m\n");
        }
        canPublish = 1;
        res.path_result = 1;
    } else {
        canPublish = 0;
        res.path_result = 0;
        calculation_time = planner.getTime();
    }

    printf("---------\n\033[1;37mResult:\033[0m\n\tPath State: %d\n\tTime: %.2f ms\n", (uint8_t)res.path_result, calculation_time);
    return true;
}

void mapCall(const nav_msgs::OccupancyGrid::ConstPtr &map_data) {
    std::cout << "Map Loaded!" << std::endl;
    map = map_data;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "rrt_star_server");
    ros::NodeHandle n("~");
    ros::ServiceServer service = n.advertiseService("rrt_star", RRTStarCalculator);
    ros::Subscriber map = n.subscribe("/map", 1, &mapCall);
    ros::Publisher exact_path_pub =n.advertise<nav_msgs::Path>("exact_path", 1000);
    ros::Publisher curved_path_pub =n.advertise<nav_msgs::Path>("curved_path", 1000);

    ros::Rate rate(2);
    while(ros::ok()){
        if (canPublish) {
        exact_path_pub.publish(exact_path);
        curved_path_pub.publish(curved_path);
        }
        ros::spinOnce();
        rate.sleep();
    }
    return 0;
}
