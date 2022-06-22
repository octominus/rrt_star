//
// Created by octominus on 18.06.2022.
//

#include "RRTPlanning.h"

RRTPlanning::RRTPlanning(ros::NodeHandle &nh) {
    //_pub_name = nodehandle.advertise<int>("/_pub_topic_name", 1);
    std::cout << "ROSNode status: OK!" << std::endl;
    _sub_name = nh.subscribe("/map", 1, &RRTPlanning::Callback, this);
    _pub_name = nh.advertise<nav_msgs::Path>("path", 1);
    //_sub_name = nodehandle.subscribe("_sub_topic_name", 1, &map::CallBack);
}

void RRTPlanning::Callback(const nav_msgs::OccupancyGrid::ConstPtr &map_data) {
    std::cout << "Callback Interrupted!" << std::endl;
    RRTPlanning::DefineMap(map_data);
    _start_point.at(0) = 100 * _resolation;
    _start_point.at(1) = 100 * _resolation;
    _goal_point.at(0) = 900 * _resolation;
    _goal_point.at(1) = 900 * _resolation;
    int test = 10;
    int t_index;
    for (t_index = 0; t_index < test; t_index++) {
        RRTPlanning::Planner(t_index, map_data);
    }
}

void RRTPlanning::Planner(int number, const nav_msgs::OccupancyGrid::ConstPtr &map_data) {
    std::cout << "###########\n"
    << "Test" << number << std::endl;
    // Construct the robot state space in which we're planning. We're
    // planning in [0,1]x[0,1], a subset of R^2.
    ob::StateSpacePtr space(new ob::RealVectorStateSpace(2));
    // Set the bounds of space to be in [0,1].
    space->as<ob::RealVectorStateSpace>()->setBounds(_resolation / 2 - 0.01, _width - _resolation / 2 + 0.01);
    // Construct a space information instance for this state space
    ob::SpaceInformationPtr si(new ob::SpaceInformation(space));
    // Set the object used to check which states in the space are valid
    si->setStateValidityChecker(ob::StateValidityCheckerPtr(new ValidityChecker(si, map_data))); 
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
    ob::ProblemDefinitionPtr pdef(new ob::ProblemDefinition(si)); 
    // Set the start and goal states
    pdef->setStartAndGoalStates(start, goal);
    
    // pdef->setOptimizationObjective(getPathLengthObjective(si));
    pdef->setOptimizationObjective(getBalancedObjective1(si));

    // Construct our optimizing planner using the RRTstar algorithm.
    ob::PlannerPtr optimizingPlanner(new og::RRTstar(si));
    
    // Set the problem instance for our planner to solve
    optimizingPlanner->setProblemDefinition(pdef);
    optimizingPlanner->setup();
    
    // attempt to solve the planning problem within one second of
    // planning time
    ob::PlannerStatus solved = optimizingPlanner->solve(0.1);
    std::cout << "Status: " << solved << std::endl;
    ob::PlannerData planner_data(si);
    optimizingPlanner->getPlannerData(planner_data);
    
    // uint32_t f_index_pd = planner_data.getStartIndex(0);
    // uint32_t n_pd = planner_data.numVertices();
    // std::cout << "Number of Planner Data: " << n_pd << std::endl;

    /*
    std::queue<uint32_t> vertices;
    vertices.push(f_index_pd);

    while(!vertices.empty()) {
        uint32_t p_index_vertex = vertices.front();
        vertices.pop();
        // for parent elements
        const ob::PlannerDataVertex p_vertex = planner_data.getVertex(p_index_vertex);
        const ob::RealVectorStateSpace::StateType *p_data2D = p_vertex.getState()->as<ob::RealVectorStateSpace::StateType>();
        int x_start = p_data2D->values[0];
        int y_start = p_data2D->values[1];

        // std::cout << "Vertex x_start: " << x_start << std::endl;
        // std::cout << "Vertex y_start: " << y_start << std::endl;

        std::vector<uint32_t> p_edges;
        uint32_t n_p_edge = planner_data.getEdges(p_index_vertex, p_edges), e_index;

        for (e_index = 0; e_index < n_p_edge; ++e_index) {
            // for child elements 
            uint32_t c_index_vertex = p_edges[e_index];
            const ob::PlannerDataVertex c_vertex = planner_data.getVertex(c_index_vertex);
            const ob::RealVectorStateSpace::StateType *e_data2D = c_vertex.getState()->as<ob::RealVectorStateSpace::StateType>();
            int x_end = e_data2D->values[0];
            int y_end = e_data2D->values[1];
            vertices.push(c_index_vertex);
        }
    }
    */

    std::shared_ptr<oc::PathControl> solved_path = std::static_pointer_cast<oc::PathControl>(pdef->getSolutionPath());
    std::cout << solved_path->getStateCount() << std::endl;
    
    int path_state_count = solved_path->getStateCount(), path_index;
    nav_msgs::Path path_points;
    path_points.header.frame_id = "map";
    path_points.header.seq = 0;
    path_points.header.stamp = ros::Time::now();

/*
    pose = PoseStamped()
        pose.header.frame_id = "velodyne"
        pose.pose.position.x = input_path[0]
        pose.pose.position.y = input_path[1] 
        pose.pose.position.z = 0.1 
        pose.header.seq = path.header.seq + 1
        path.header.frame_id = "velodyne"
        path.header.stamp = rospy.Time.now()
        pose.header.stamp = path.header.stamp
        path.poses.append(pose)

        #print(path)
        pub_path.publish(path)
*/

    for (path_index = 0; path_index < path_state_count; path_index++) {
        /* code */
        const ob::State *path_state = solved_path->getState(path_index);
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
        std::cout 
        << "x: " << path_x
        << " y: " << path_y
        << std::endl;
    }
    _pub_name.publish(path_points);
}

void RRTPlanning::DefineMap(const nav_msgs::OccupancyGrid::ConstPtr &map_data) {
    _resolation = map_data->info.resolution;
    _height = map_data->info.height * _resolation;  // unit (m)
    _width = map_data->info.width * _resolation;    // unit (m)

    // std::cout << "Height: " << RRTPlanning::Map::_height << " m" << std::endl;
    // std::cout << "Width: " << RRTPlanning::Map::_width << " m" << std::endl;
    // std::cout << "Resolation: " << RRTPlanning::Map::_resolation << " m/px" << std::endl;
}

ob::OptimizationObjectivePtr RRTPlanning::getClearanceObjective(const ob::SpaceInformationPtr& si) {
    return ob::OptimizationObjectivePtr(new ClearanceObjective(si));
}

ob::OptimizationObjectivePtr RRTPlanning::getBalancedObjective1(const ob::SpaceInformationPtr& si) {
    ob::OptimizationObjectivePtr lengthObj(new ob::PathLengthOptimizationObjective(si));
    ob::OptimizationObjectivePtr clearObj(new ClearanceObjective(si));

    ob::MultiOptimizationObjective* opt = new ob::MultiOptimizationObjective(si);
    opt->addObjective(lengthObj, 10.0);
    opt->addObjective(clearObj, 1.0);

    return ob::OptimizationObjectivePtr(opt);
}

ob::OptimizationObjectivePtr RRTPlanning::getBalancedObjective2(const ob::SpaceInformationPtr& si)
{
    ob::OptimizationObjectivePtr lengthObj(new ob::PathLengthOptimizationObjective(si));
    ob::OptimizationObjectivePtr clearObj(new ClearanceObjective(si));

    return 10.0*lengthObj + clearObj;
}



 void ompl::base::DiscreteMotionValidator::defaultSettings()
 {
     stateSpace_ = si_->getStateSpace().get();
     if (stateSpace_ == nullptr)
         throw Exception("No state space for motion validator");
 }
  
 bool ompl::base::DiscreteMotionValidator::checkMotion(const State *s1, const State *s2, std::pair<State *, double> &lastValid) const
 {
     /* assume motion starts in a valid configuration so s1 is valid */
  
     bool result = true;
     int nd = stateSpace_->validSegmentCount(s1, s2);
  
     if (nd > 1)
     {
         /* temporary storage for the checked state */
         State *test = si_->allocState();
  
         for (int j = 1; j < nd; ++j)
         {
             stateSpace_->interpolate(s1, s2, (double)j / (double)nd, test);
             if (!si_->isValid(test))
             {
                 lastValid.second = (double)(j - 1) / (double)nd;
                 if (lastValid.first != nullptr)
                     stateSpace_->interpolate(s1, s2, lastValid.second, lastValid.first);
                 result = false;
                 break;
             }
         }
         si_->freeState(test);
     }
  
     if (result)
         if (!si_->isValid(s2))
         {
             lastValid.second = (double)(nd - 1) / (double)nd;
             if (lastValid.first != nullptr)
                 stateSpace_->interpolate(s1, s2, lastValid.second, lastValid.first);
             result = false;
         }
  
     if (result)
         valid_++;
     else
         invalid_++;
  
     return result;
 }