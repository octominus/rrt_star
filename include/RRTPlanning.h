//
// Created by octominus on 18.06.2022.
//

#ifndef RRT_STAR_WS_RRTPLANNING_H
#define RRT_STAR_WS_RRTPLANNING_H

// OMPL Files
#include <ompl/config.h>
#include <ompl/control/SimpleSetup.h>
#include <ompl/base/goals/GoalState.h>
#include <ompl/base/spaces/SE2StateSpace.h>
#include <ompl/base/spaces/DiscreteStateSpace.h>
#include <ompl/control/spaces/RealVectorControlSpace.h>
#include <ompl/base/objectives/PathLengthOptimizationObjective.h>
#include <ompl/geometric/planners/rrt/RRTstar.h>

// ROS Files
#include <ros/ros.h>
#include <nav_msgs/OccupancyGrid.h>

// C++ Files
#include <iostream>
#include <vector>

// My Files
#include "ValidityChecker.h" // DONE

namespace ob = ompl::base;
namespace oc = ompl::control;
namespace og = ompl::geometric;

class RRTPlanning {
public:
    void Callback(const nav_msgs::OccupancyGrid::ConstPtr &map_data);
    void Planner(int number, const nav_msgs::OccupancyGrid::ConstPtr &map_data);
    void DefineMap(const nav_msgs::OccupancyGrid::ConstPtr &map_data);
    void PathMarker(oc::PathControl path);
    void PlannerMarker(ob::PlannerData &data);
    
private:
    // Returns a structure representing the optimization objective to use
    // for optimal motion planning. This method returns an objective which
    // attempts to minimize the length in configuration space of computed
    // paths.
    ob::OptimizationObjectivePtr getPathLengthObjective(const ob::SpaceInformationPtr &si) {
        return ob::OptimizationObjectivePtr(new ob::PathLengthOptimizationObjective(si));
    }

    std::vector<double> _start_point = {100.0, 100.0};
    std::vector<double> _goal_point = {900.0, 900.0};
    nav_msgs::OccupancyGrid::ConstPtr _map;
    double _width = 0.0;
    double _height = 0.0;
    double _resolation = 0.0;

};

class ROSNode {
public:
    explicit ROSNode(ros::NodeHandle &nodehandle);
    RRTPlanning node_callback;
        
private:
    ros::NodeHandle &_nodehandle;
    //ros::Publisher _pub_name;
    ros::Subscriber _sub_name;
};

#endif //RRT_STAR_WS_RRTPLANNING_H
