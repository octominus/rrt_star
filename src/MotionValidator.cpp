//
// Created by octominus on 22.06.2022.
//

#include "MotionValidator.h"

MotionValidator::MotionValidator(const ob::SpaceInformationPtr& si) : ob::MotionValidator(si) {

}

bool MotionValidator::checkMotion(const ob::State *s1, const ob::State *s2, std::pair<ob::State *, double> &lastValid) const {

}