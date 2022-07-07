//
// Created by octominus on 19.06.2022.
//

#ifndef WS_STAR_WS_VALIDITYCHECKER_H
#define WS_STAR_WS_VALIDITYCHECKER_H

#include <ompl/base/StateValidityChecker.h>
#include <ompl/base/spaces/RealVectorStateSpace.h>
#include <nav_msgs/OccupancyGrid.h>

namespace ob = ompl::base;
//namespace oc = ompl::control;
//namespace og = ompl::geometric;

// Our collision checker. For this demo, our robot's state space
// lies in [0,1]x[0,1], with a circular obstacle of radius 0.25
// centered at (0.5,0.5). Any states lying in this circular region are
// considered "in collision".
class ValidityChecker : public ob::StateValidityChecker {
public:
    explicit ValidityChecker(const ob::SpaceInformationPtr& si, const nav_msgs::OccupancyGrid_<std::allocator<void>>::ConstPtr &map_data);

    bool isWhite(double x, double y, int8_t threshold) const;
    // Returns whether the given state's position overlaps the
    // circular obstacle
    bool isValid(const ob::State* state) const override;
    // Returns the distance from the given state's position to the
    // boundary of the circular obstacle.

private:
    double _map_width;
    double _map_height;
    double _map_resolation;
    nav_msgs::OccupancyGrid::_data_type _map_data;
};

#endif //WS_RRT_STAR_VALIDITYCHECKER_H
