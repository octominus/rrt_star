#include "ros/ros.h"
#include "rrt_star/rrt_star.h"

#include <cstdlib>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "rrt_star_client");
  if (argc != 5)
  {
    ROS_INFO("usage: rrt_star_client X1 Y1 X2 Y2");
    return 1;
  }

  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<rrt_star::rrt_star>("rrt_star");
  rrt_star::rrt_star srv;
  srv.request.X1 = atoll(argv[1]);
  srv.request.Y1 = atoll(argv[2]);
  srv.request.X2 = atoll(argv[3]);
  srv.request.Y2 = atoll(argv[4]);
  if (client.call(srv))
  {
    ROS_INFO("Path Finded: %d", (bool)srv.response.result);
  }
  else
  {
    ROS_ERROR("Failed to call service rrt_star");
    return 1;
  }

  return 0;
}