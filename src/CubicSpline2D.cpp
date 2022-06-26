//
// Created by octominus on 26.06.2022.
// The codes were created as a C++ version using AtsushiSakai's Python library. 
// For the original library: https://github.com/AtsushiSakai/PythonRobotics/blob/71de5d038f348d347d7b5dc00c914d523cd59f92/PathPlanning/CubicSpline/cubic_spline_planner.py
//

#include "CubicSpliner.h"

CubicSpline2D::CubicSpline2D(std::vector<float> x, std::vector<float> y) {
    f_array x_array = xt::adapt(x);
    f_array y_array = xt::adapt(y);
    _s = _calc_s(x_array, y_array);
    // convert array to vector 
    // global class definition (?)
    CubicSpliner _sx(_s, x);
    CubicSpliner _sy(_s, x)
}

f_array CubicSpline2D::_calc_s(f_array x, f_array y) {
    f_array dx = xt::diff(x);
    f_array dy = xt::diff(y);

    _ds = xt::hypot(dx, dy);
    _ds = xt::cumsum(_ds);

    f_array s = {0.0};
    s = xt::concatenate(xt::xtuple(s, _ds));

    return s;
}