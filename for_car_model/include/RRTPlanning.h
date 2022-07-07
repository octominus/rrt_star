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
#include <string>
#include <chrono>

// Xtensor Files
#include <xtensor/xio.hpp>

// My Files
#include "ValidityChecker.h" 	// DONE
#include "CubicSpliner.h" 	// DONE

namespace ob = ompl::base;
namespace oc = ompl::control;
namespace og = ompl::geometric;

typedef std::chrono::high_resolution_clock::time_point time_data;
typedef std::chrono::duration<float, std::milli> time_duration;

class RRTPlanning {
public:
    explicit RRTPlanning();
    ob::OptimizationObjectivePtr getClearanceObjective(const ob::SpaceInformationPtr& si);
    ob::OptimizationObjectivePtr getBalancedObjective1(const ob::SpaceInformationPtr& si);
    ob::OptimizationObjectivePtr getBalancedObjective2(const ob::SpaceInformationPtr& si);
    ob::OptimizationObjectivePtr getPathLengthObjWithCostToGo(const ob::SpaceInformationPtr& si);
    uint8_t FindPath(const nav_msgs::OccupancyGrid::ConstPtr &map_data, std::vector<float> start, std::vector<float> goal);
    uint8_t Planner(const nav_msgs::OccupancyGrid::ConstPtr &map_data);
    void DefineMap(const nav_msgs::OccupancyGrid::ConstPtr &map_data);
    nav_msgs::Path GetExactPath();
    nav_msgs::Path GetCurvedPath();
    float getTime();
    void setTime(float time);
    std::vector<std::vector<float>> CalculateSpline(std::vector<float> x, std::vector<float> y, float dt);
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
    std::shared_ptr<oc::PathControl> _solved_path;
    std::vector<double> _start_point = {100.0, 100.0};
    std::vector<double> _goal_point = {900.0, 900.0};
    double _width = 0.0;
    double _height = 0.0;
    double _resolation = 0.0;
    float _time = 0.0;
    float _T_s = 0.1;
    float _desired_time = 0.1; // default 0.1ms
    std::vector<float> _x_points; 
    std::vector<float> _y_points;
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
