//
// Created by octominus on 18.06.2022.
//

#include "RRTPlanning.h"

RRTPlanning::RRTPlanning() {
    std::cout << "\tROS Node status: \033[1;37mOK!\033[0m\n" << std::endl;
}

void RRTPlanning::FindPath(const nav_msgs::OccupancyGrid::ConstPtr &map_data, std::vector<float> start, std::vector<float> goal) {
    std::cout << "RRT Star Function Started!" << std::endl;
    _map = map_data;
    RRTPlanning::DefineMap(_map);
    _start_point.at(0) = start[0]; // x1
    _start_point.at(1) = start[1]; // y1
    std::cout << "Start: (" << _start_point.at(0) << "," << _start_point.at(1) << ")" << std::endl;
    _goal_point.at(0) = goal[0]; // x2
    _goal_point.at(1) = goal[1]; // y2
    RRTPlanning::Planner(_map);
}

void RRTPlanning::MapCallback(const nav_msgs::OccupancyGrid::ConstPtr &map_data) {
    std::cout << "Map Loaded!" << std::endl;
    _map = map_data;
    RRTPlanning::DefineMap(_map);
}

void RRTPlanning::Planner(const nav_msgs::OccupancyGrid::ConstPtr &map_data) {
    // Construct the robot state space in which we're planning. We're planning in [X pixels]x[Y pixels], a subset of R^2.
    std::shared_ptr<ob::RealVectorStateSpace> real_vector_ss = std::make_shared<ob::RealVectorStateSpace>(2);
    // new ob::RealVectorStateSpace(2)
    ob::StateSpacePtr space(real_vector_ss);
    // Set the bounds of space to be in [0,1].
    space->as<ob::RealVectorStateSpace>()->setBounds(_resolation / 2 - 0.01, _width - _resolation / 2 + 0.01);
    // Construct a space information instance for this state space
    std::shared_ptr<ob::SpaceInformation> space_info = std::make_shared<ob::SpaceInformation>(space);
    // new ob::SpaceInformation(space)
    ob::SpaceInformationPtr si(space_info);
    // Set the object used to check which states in the space are valid
    std::shared_ptr<ValidityChecker> validity_checker = std::make_shared<ValidityChecker>(si, map_data);
    // new ValidityChecker(si, map_data)
    si->setStateValidityChecker(ob::StateValidityCheckerPtr(validity_checker)); 
    // si->setStateValidityCheckingResolution(0.01); // 3%
    si->setup();
    // Set our robot's starting state to be the bottom-left corner of
    // the environment, or (0,0).
    ob::ScopedState<> start(space); // --> BAŞLANGIÇ NOKTASI
    start->as<ob::RealVectorStateSpace::StateType>()->values[0] = _start_point.at(0); 
    start->as<ob::RealVectorStateSpace::StateType>()->values[1] = _start_point.at(1);
    // Set our robot's goal state to be the top-right corner of the
    // environment, or (1,1).
    ob::ScopedState<> goal(space); // --> BİTİŞ NOKTASI
    goal->as<ob::RealVectorStateSpace::StateType>()->values[0] = _goal_point.at(0);
    goal->as<ob::RealVectorStateSpace::StateType>()->values[1] = _goal_point.at(1); 
    // Create a problem instance
    std::shared_ptr<ob::ProblemDefinition> problem_def = std::make_shared<ob::ProblemDefinition>(si);
    // new ob::ProblemDefinition(si)
    ob::ProblemDefinitionPtr pdef(problem_def); 
    // Set the start and goal states
    pdef->setStartAndGoalStates(start, goal);
    // pdef->setOptimizationObjective(getPathLengthObjective(si));
    pdef->setOptimizationObjective(getBalancedObjective1(si));
    // Construct our optimizing planner using the RRTstar algorithm.
    std::shared_ptr<og::RRTstar> rrtstar = std::make_shared<og::RRTstar>(si);
    // new og::RRTstar(si)
    ob::PlannerPtr optimizingPlanner(rrtstar);
    // Set the problem instance for our planner to solve
    optimizingPlanner->setProblemDefinition(pdef);
    optimizingPlanner->setup();
    // attempt to solve the planning problem within one second of
    // planning time
    ob::PlannerStatus solved = optimizingPlanner->solve(0.1);

    std::cout << "Status: " << solved << std::endl;

    ob::PlannerData planner_data(si);
    optimizingPlanner->getPlannerData(planner_data);

    std::shared_ptr<oc::PathControl> solved_path = std::static_pointer_cast<oc::PathControl>(pdef->getSolutionPath());
    _solved_path = solved_path;
}

nav_msgs::Path RRTPlanning::GetExactPath() {
    int path_state_count = _solved_path->getStateCount();
    int path_index;
    nav_msgs::Path path_points;
    std::vector<float> x_points, y_points;

    path_points.header.frame_id = "map";
    path_points.header.seq = 0;
    path_points.header.stamp = ros::Time::now(); 

    for (path_index = 0; path_index < path_state_count; path_index++) {
        const ob::State *path_state = _solved_path->getState(path_index);
        const ob::RealVectorStateSpace::StateType *state2D = path_state->as<ob::RealVectorStateSpace::StateType>();
        double path_x = state2D->values[0];
        double path_y = state2D->values[1];
        geometry_msgs::PoseStamped path_point;
        path_point.header.frame_id = "map";
        path_point.pose.position.x = path_x;
        path_point.pose.position.y = path_y;
        path_point.pose.position.z = 1.0;
        path_point.pose.orientation.w = 1.0;
        path_point.header.seq = path_index + 1;
        path_point.header.stamp = path_points.header.stamp;
        path_points.poses.push_back(path_point);
        x_points.push_back(path_x);
        y_points.push_back(path_y);
    }
    _x_points = x_points;
    _y_points = y_points;
    return path_points;
} 
nav_msgs::Path RRTPlanning::GetCurvedPath() {
    std::vector<std::vector<float>> result;
    int path_index;
    nav_msgs::Path cubic_path_points;

    result = CalculateSpline(_x_points, _y_points, _T_s);

    cubic_path_points.header.frame_id = "map";
    cubic_path_points.header.seq = 0;
    cubic_path_points.header.stamp = ros::Time::now();

    for (path_index = 0; (uint)path_index < (uint)result[4].size(); path_index++) {
        std::vector<float> path_x = result[0];
        std::vector<float> path_y = result[1];
        geometry_msgs::PoseStamped cubic_path_point;
        cubic_path_point.header.frame_id = "map";
        cubic_path_point.pose.position.x = path_x[path_index];
        cubic_path_point.pose.position.y = path_y[path_index];
        cubic_path_point.pose.position.z = 1.0;
        cubic_path_point.pose.orientation.w = 1.0;
        cubic_path_point.header.seq = path_index + 1;
        cubic_path_point.header.stamp = cubic_path_points.header.stamp;
        cubic_path_points.poses.push_back(cubic_path_point);
    }
    return cubic_path_points;
}

void RRTPlanning::DefineMap(const nav_msgs::OccupancyGrid::ConstPtr &map_data) {
    _resolation = map_data->info.resolution;
    std::cout << "Res: " << _resolation << std::endl; 
    _height = map_data->info.height * _resolation;  // unit (m)
    _width = map_data->info.width * _resolation;    // unit (m)

    // std::cout << "Height: " << RRTPlanning::Map::_height << " m" << std::endl;
    // std::cout << "Width: " << RRTPlanning::Map::_width << " m" << std::endl;
    // std::cout << "Resolation: " << RRTPlanning::Map::_resolation << " m/px" << std::endl;
}

std::vector<std::vector<float>> RRTPlanning::CalculateSpline(std::vector<float> x, std::vector<float> y, float dt) {
    std::vector<std::vector<float>> result;
    std::vector<float> rx, ry, ryaw, rk, rs;
    std::vector<float> ixy;
    uint32_t index;
    CubicSpline2D sp(x, y);
    auto s = xt::arange<float>(0.0, sp._s.back(), dt);
    for (index = 0; index < s.size(); index++) {
        ixy = sp.CalculatePosition(s(index));
        rx.push_back(ixy[0]);
        ry.push_back(ixy[1]);
        ryaw.push_back(sp.CalculateYaw(s(index)));
        rk.push_back(sp.CalculateCurvature(s(index)));
        rs.push_back(s(index));
    }
    result = {rx, ry, ryaw, rk, rs};
    return result;
}

ob::OptimizationObjectivePtr getPathLengthObjective(const ob::SpaceInformationPtr& si)
{
    return ob::OptimizationObjectivePtr(new ob::PathLengthOptimizationObjective(si));
}

ob::OptimizationObjectivePtr getThresholdPathLengthObj(const ob::SpaceInformationPtr& si)
{
    ob::OptimizationObjectivePtr obj(new ob::PathLengthOptimizationObjective(si));
    obj->setCostThreshold(ob::Cost(1.51));
    return obj;
}

ob::OptimizationObjectivePtr RRTPlanning::getClearanceObjective(const ob::SpaceInformationPtr& si)
{
    return ob::OptimizationObjectivePtr(new ClearanceObjective(si));
}

ob::OptimizationObjectivePtr RRTPlanning::getBalancedObjective1(const ob::SpaceInformationPtr& si)
{
    ob::OptimizationObjectivePtr lengthObj(new ob::PathLengthOptimizationObjective(si));
    ob::OptimizationObjectivePtr clearObj(new ClearanceObjective(si));
    ob::MultiOptimizationObjective* opt = new ob::MultiOptimizationObjective(si);
    opt->addObjective(lengthObj, 20.0);
    opt->addObjective(clearObj, 0.2);

    return ob::OptimizationObjectivePtr(opt);
}

ob::OptimizationObjectivePtr RRTPlanning::getBalancedObjective2(const ob::SpaceInformationPtr& si)
{
    ob::OptimizationObjectivePtr lengthObj(new ob::PathLengthOptimizationObjective(si));
    ob::OptimizationObjectivePtr clearObj(new ClearanceObjective(si));

    return 10.0*lengthObj + clearObj;
}

ob::OptimizationObjectivePtr RRTPlanning::getPathLengthObjWithCostToGo(const ob::SpaceInformationPtr& si)
{
    ob::OptimizationObjectivePtr obj(new ob::PathLengthOptimizationObjective(si));
    obj->setCostToGoHeuristic(&ob::goalRegionCostToGo);
    return obj;
}
