//
// Created by octominus on 18.06.2022.
//

#include "RRTPlanning.h"

#include <iostream>

/* main.c */
int main(int argc, char *argv[]) {

    ros::init(argc, argv, "rrt_star");
    std::cout << "RRT_STAR NODE CREATED" << std::endl;

    ros::NodeHandle n("~"); // Node name "/rrt_star"

    ROSNode nodes(n);

    ros::spin();
    ros::waitForShutdown();

    return 0;
}
