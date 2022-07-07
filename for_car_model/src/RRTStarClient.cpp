#include "ros/ros.h"
#include "rrt_star/rrt_star.h"

#include <cstdlib>

#include <nav_msgs/OccupancyGrid.h>
#include <nav_msgs/Path.h>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "rrt_star_client");

    std::string help = "--help";
    std::string point = "-p";
    std::string time = "-t", milisecond = "--ms", second = "--s";

    ros::NodeHandle n;
    ros::ServiceClient client = n.serviceClient<rrt_star::rrt_star>("rrt_star_server/rrt_star");
    rrt_star::rrt_star srv;

    if (argv[6] == time) {
        srv.request.time = atof(argv[7]);
        if (argv[8] == milisecond || argc == 8) {
            srv.request.time_type = "ms";
        } else if (argv[8] == second) {
            srv.request.time_type = "s";
        } else {
            ROS_INFO("usage: rrt_star_client -p X1 Y1 X2 Y2 -t TIME");
            return 1;
        }
    } else {
        if (argv[1] == help) {
            ROS_INFO("usage: rrt_star_client -p X1 Y1 X2 Y2");
            srv.request.time = 0.0;
        }
    }

    srv.request.X1 = atof(argv[2]);
    srv.request.Y1 = atof(argv[3]);
    srv.request.X2 = atof(argv[4]);
    srv.request.Y2 = atof(argv[5]);

    if (client.call(srv)) {
        ROS_INFO("Path Finded: %d", (bool)srv.response.path_result);
    }
    else {
        ROS_ERROR("Failed to call service rrt_star");
        return 1;
    }
    
    return 0;
}