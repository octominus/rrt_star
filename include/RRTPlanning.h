//
// Created by octominus on 18.06.2022.
//

#ifndef WS_RRT_STAR_RRTPLANNING_H
#define WS_RRT_STAR_RRTPLANNING_H

// OMPL Files
#include <ompl/config.h>
#include <ompl/control/SimpleSetup.h>
#include <ompl/base/goals/GoalState.h>
#include <ompl/base/SpaceInformation.h>
#include <ompl/base/spaces/SE2StateSpace.h>
#include <ompl/base/spaces/DiscreteStateSpace.h>
#include <ompl/base/spaces/RealVectorStateSpace.h>
#include <ompl/control/spaces/RealVectorControlSpace.h>
#include <ompl/base/objectives/StateCostIntegralObjective.h>
#include <ompl/base/objectives/PathLengthOptimizationObjective.h>
#include <ompl/base/objectives/MaximizeMinClearanceObjective.h>
#include <ompl/geometric/planners/rrt/RRTstar.h>
#include <ompl/base/DiscreteMotionValidator.h>
#include <ompl/util/Exception.h>

// ROS Files
#include <ros/ros.h>
#include <nav_msgs/OccupancyGrid.h>
#include <nav_msgs/Path.h>
#include <geometry_msgs/PoseStamped.h>

// C++ Files
#include <iostream>
#include <vector>
#include <queue>

#include <xtensor/xio.hpp>

// My Files
#include "ValidityChecker.h" // DONE
#include "MotionValidator.h"
#include "CubicSpliner.h"

namespace ob = ompl::base;
namespace oc = ompl::control;
namespace og = ompl::geometric;

class RRTPlanning {
public:
    explicit RRTPlanning(ros::NodeHandle &nh);
    ob::OptimizationObjectivePtr getClearanceObjective(const ob::SpaceInformationPtr& si);
    ob::OptimizationObjectivePtr getBalancedObjective1(const ob::SpaceInformationPtr& si);
    ob::OptimizationObjectivePtr getBalancedObjective2(const ob::SpaceInformationPtr& si);
    ob::OptimizationObjectivePtr getPathLengthObjWithCostToGo(const ob::SpaceInformationPtr& si);
    void Callback(const nav_msgs::OccupancyGrid::ConstPtr &map_data);
    void Planner(int number, const nav_msgs::OccupancyGrid::ConstPtr &map_data);
    void DefineMap(const nav_msgs::OccupancyGrid::ConstPtr &map_data);
    std::vector<std::vector<float>> CalculateSpline(std::vector<float> x, std::vector<float> y, float dt);
    ros::Publisher _pub_name;
    ros::Subscriber _sub_name;
    ros::Publisher _cubic_path;
    // void PathMarker(oc::PathControl path);
    // void PlannerMarker(ob::PlannerData &planner_data);
    
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
    float _T_s = 0.1;
};

class ClearanceObjective : public ob::StateCostIntegralObjective
{
public:
    ClearanceObjective(const ob::SpaceInformationPtr& si) :
        ob::StateCostIntegralObjective(si, true)
    {
    }

    ob::Cost stateCost(const ob::State* s) const
    {
        return ob::Cost(1 / si_->getStateValidityChecker()->clearance(s));
    }
};

#endif //WS_RRT_STAR_RRTPLANNING_H