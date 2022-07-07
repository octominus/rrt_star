//
// Created by octominus on 26.06.2022.
// 

#include "CubicSpliner.h"

CubicSpline2D::CubicSpline2D(std::vector<float> x, std::vector<float> y) :_sx(NULL), _sy(NULL) {
    f_array x_array = xt::adapt(x);
    f_array y_array = xt::adapt(y);
    _s = _calc_s(x_array, y_array);
    // convert array to vector 
    // global class definition (?)
    std::vector<float> s = toVector(_s);
    _sx = new CubicSpliner(s, x);
    _sy = new CubicSpliner(s, y);

}

CubicSpline2D::~CubicSpline2D() {
    delete _sx;
    delete _sy;
    _sx = NULL;
    _sy = NULL;
}

std::vector<float> CubicSpline2D::CalculatePosition(float s) {
    float x = _sx->CalculatePosition(s);
    float y = _sy->CalculatePosition(s);
    std::vector<float> position = {x, y};
    return position;
}

float CubicSpline2D::CalculateCurvature(float s) {
    float dx = _sx->CalculateFirstDerivative(s);
    float ddx = _sx->CalculateSecondDerivative(s);
    float dy = _sy->CalculateFirstDerivative(s);
    float ddy = _sy->CalculateSecondDerivative(s);
    float k = ((ddy * dx) - (ddx * dy)) / pow((pow(dx, 2) + pow(dy, 2)), (3 / 2));
    return k;
}

float CubicSpline2D::CalculateYaw(float s) {
    float dx = _sx->CalculateFirstDerivative(s); 
    float dy = _sy->CalculateFirstDerivative(s);
    float yaw = atan2(dy, dx);
    return yaw;
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

std::vector<float> CubicSpline2D::toVector(f_array arr) {
    std::vector<float> vec;
    uint8_t index;
    for (index = 0; index < arr.size(); index++) {
        vec.push_back(arr(index));
    }
    return vec;
}
