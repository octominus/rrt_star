//
// Created by octominus on 22.06.2022.
//

#ifndef WS_RRT_STAR_MOTIONVALIDATOR_H
#define WS_RRT_STAR_MOTIONVALIDATOR_H

#include <ompl/base/MotionValidator.h>
#include <ompl/base/spaces/RealVectorStateSpace.h>

namespace ob = ompl::base;

class MotionValidator : public ob::MotionValidator {
public:
    explicit MotionValidator(const ob::SpaceInformationPtr& si);
    // implement checkMotion()
    bool checkMotion(const ob::State *s1, const ob::State *s2, std::pair<ob::State *, double> &lastValid) const override;
};

#endif // WS_RRT_STAR_MOTIONVALIDATOR_H