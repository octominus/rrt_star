//
// Created by octominus on 22.06.2022.
//

#include "MotionValidator.h"

MotionValidator::MotionValidator(const ob::SpaceInformationPtr& si) : ob::MotionValidator(si) {

}

bool MotionValidator::checkMotion(const ob::State *s1, const ob::State *s2, std::pair<ob::State *, double> &lastValid) const {

}

/*

void ompl::base::DiscreteMotionValidator::defaultSettings()
 {
     stateSpace_ = si_->getStateSpace().get();
     if (stateSpace_ == nullptr)
         throw Exception("No state space for motion validator");
 }
  
 bool ompl::base::DiscreteMotionValidator::checkMotion(const State *s1, const State *s2, std::pair<State *, double> &lastValid) const
 {
     
  
     bool result = true;
     int nd = stateSpace_->validSegmentCount(s1, s2);
  
     if (nd > 1)
     {
         
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

 */