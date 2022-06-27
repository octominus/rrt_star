#include <iostream>
#include <vector>

#include "ros/ros.h"
#include "RRTPlanning.h"
#include "rrt_star/rrt_star.h"

bool RRTStarCalculator(rrt_star::rrt_star::Request  &req, rrt_star::rrt_star::Response &res) {
    std::vector<float> start = {req.X1, req.Y1};
    std::vector<float> goal = {req.X2, req.Y2};
    res.result = 1;
    ROS_INFO("request: Start: (%f, %f) to Goal: (%f, %f)", (float)req.X1, (float)req.Y1, (float)req.X2, (float)req.Y2);
    ROS_INFO("sending back response: [%d]", (bool)res.result);
    return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "rrt_star_server");
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("rrt_star", RRTStarCalculator);
  ROS_INFO("Ready to find path.");
  ros::spin();

  return 0;
}