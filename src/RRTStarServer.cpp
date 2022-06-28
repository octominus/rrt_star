#include <iostream>
#include <vector>

#include "ros/ros.h"
#include "RRTPlanning.h"
#include "rrt_star/rrt_star.h"

#include <nav_msgs/OccupancyGrid.h>
#include <nav_msgs/Path.h>

nav_msgs::OccupancyGrid::ConstPtr map;
nav_msgs::Path exact_path;
nav_msgs::Path curved_path;

bool RRTStarCalculator(rrt_star::rrt_star::Request  &req, rrt_star::rrt_star::Response &res) {
    std::vector<float> start = {req.X1, req.Y1};
    std::vector<float> goal = {req.X2, req.Y2};
    ros::NodeHandle rrt;
    ROS_INFO("\nDesired Points:\n\t\033[1;31mStart:\033[m (%.2f, %.2f)\n\t\033[1;32mGoal:\033[m (%.2f, %.2f)", (float)req.X1, (float)req.Y1, (float)req.X2, (float)req.Y2);
    RRTPlanning planner(rrt);
    planner.FindPath(map, start, goal);
    exact_path = planner.GetExactPath();
    curved_path = planner.GetCurvedPath();
    res.result = 1;
    ROS_INFO("sending back response: [%d]", (bool)res.result);
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
  ROS_INFO("Ready to find path.");

  ros::Rate rate(2);
  while(ros::ok()){
    exact_path_pub.publish(exact_path);
    curved_path_pub.publish(curved_path);
    ros::spinOnce();
    rate.sleep();
  }

  return 0;
}