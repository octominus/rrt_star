//
// Created by octominus on 18.06.2022.
//

#include "RRTPlanning.h"

ROSNode::ROSNode(ros::NodeHandle &nodehandle): _nodehandle(nodehandle) {
    //_pub_name = nodehandle.advertise<int>("/_pub_topic_name", 1);
    std::cout << "ROSNode status: OK!" << std::endl;
    _sub_name = nodehandle.subscribe("/map", 1, &RRTPlanning::Callback, &node_callback);
    //_pub_name = nodehandle.advertise<int>("_pub_topic_name", 1);
    //_sub_name = nodehandle.subscribe("_sub_topic_name", 1, &map::CallBack);
}

void RRTPlanning::Callback(const nav_msgs::OccupancyGrid::ConstPtr &map_data) {
    std::cout << "Callback Interrupted!" << std::endl;
    RRTPlanning::DefineMap(map_data);
    _start_point.at(0) = 100 * _resolation;
    _start_point.at(1) = 100 * _resolation;
    _goal_point.at(0) = 900 * _resolation;
    _goal_point.at(1) = 900 * _resolation;
    int test = 5;
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
    pdef->setOptimizationObjective(getPathLengthObjective(si));

    // Construct our optimizing planner using the RRTstar algorithm.
    ob::PlannerPtr optimizingPlanner(new og::RRTstar(si));
    
    // Set the problem instance for our planner to solve
    optimizingPlanner->setProblemDefinition(pdef);
    optimizingPlanner->setup();
    
    // attempt to solve the planning problem within one second of
    // planning time
    ob::PlannerStatus solved = optimizingPlanner->solve(0.1);
    std::cout << "Status: " << solved << std::endl;

    std::shared_ptr<oc::PathControl> solved_path = std::static_pointer_cast<oc::PathControl>(pdef->getSolutionPath());
    std::cout << solved_path->getStateCount() << std::endl;
    PathMarker(*solved_path);

    ob::PlannerData planner_data(si);
    optimizingPlanner->getPlannerData(planner_data);
    PlannerMarker(planner_data);

}

void RRTPlanning::DefineMap(const nav_msgs::OccupancyGrid::ConstPtr &map_data) {
    _resolation = map_data->info.resolution;
    _height = map_data->info.height * _resolation;  // unit (m)
    _width = map_data->info.width * _resolation;    // unit (m)

    // std::cout << "Height: " << RRTPlanning::Map::_height << " m" << std::endl;
    // std::cout << "Width: " << RRTPlanning::Map::_width << " m" << std::endl;
    // std::cout << "Resolation: " << RRTPlanning::Map::_resolation << " m/px" << std::endl;
}

void RRTPlanning::PathMarker(oc::PathControl path) {
    int path_state_count = path.getStateCount(), path_index;
    for (path_index = 0; path_index < path_state_count; path_index++) {
        /* code */
        const ob::State *path_state = path.getState(path_index);
        const ob::RealVectorStateSpace::StateType *state2D = path_state->as<ob::RealVectorStateSpace::StateType>();
        double path_x = state2D->values[0];
        double path_y = state2D->values[1];
        std::cout 
        << "x: " << path_x
        << " y: " << path_y
        << std::endl;
    }
}

void RRTPlanning::PlannerMarker(ob::PlannerData &data) {
    uint32_t f_index_pd = data.getStartIndex(0);
    uint32_t n_pd = data.numVertices();
    std::cout << "Number of Planner Data: " << n_pd << std::endl;

    std::queue<uint32_t> vertices;
    vertices.push(f_index_pd);

    while(!vertices.empty()) {
        uint32_t p_index_vertex = vertices.front();
        vertices.pop();
        // for parent elements
        const ob::PlannerDataVertex p_vertex = data.getVertex(p_index_vertex);
        const ob::RealVectorStateSpace::StateType *p_data2D = p_vertex.getState()->as<ob::RealVectorStateSpace::StateType>();
        int x_start = p_data2D->values[0];
        int y_start = p_data2D->values[1];

        // std::cout << "Vertex x_start: " << x_start << std::endl;
        // std::cout << "Vertex y_start: " << y_start << std::endl;

        std::vector<uint32_t> p_edges;
        uint32_t n_p_edge = data.getEdges(p_index_vertex, p_edges), e_index;

        for (e_index = 0; e_index < n_p_edge; ++e_index) {
            // for child elements 
            uint32_t c_index_vertex = p_edges[e_index];
            const ob::PlannerDataVertex c_vertex = data.getVertex(c_index_vertex);
            const ob::RealVectorStateSpace::StateType *e_data2D = c_vertex.getState()->as<ob::RealVectorStateSpace::StateType>();
            int x_end = e_data2D->values[0];
            int y_end = e_data2D->values[0];
            vertices.push(c_index_vertex);
        }
    }
}