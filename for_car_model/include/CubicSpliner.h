//
// Created by octominus on 26.06.2022.
//

#ifndef WS_RRT_CUBICSPLINES_H
#define WS_RRT_CUBICSPLINES_H

#include <vector>
#include <iostream>
#include <cmath>

// need to install xtensor
// sudo apt-get install xtensor-dev
// https://xtensor.readthedocs.io/en/latest/numpy.html

#include <xtensor/xmath.hpp>
#include <xtensor/xarray.hpp>
#include <xtensor/xio.hpp>
#include <xtensor/xadapt.hpp>
#include <xtensor-blas/xlinalg.hpp>
#include <xtensor-blas/xblas.hpp>
#include <xtensor-blas/xlapack.hpp>
#include <xtensor-blas/xblas_utils.hpp>
#include <xtensor-blas/xblas_config.hpp>

typedef xt::xarray<float> f_array;

#define PI 3.14159265359

class CubicSpliner
{
public:
    explicit CubicSpliner(std::vector<float> x, std::vector<float> y);
    float CalculatePosition(float t);
    float CalculateFirstDerivative(float t);
    float CalculateSecondDerivative(float t);
private:
    f_array _calc_A(f_array arr);
    f_array _calc_B(f_array arr);
    uint8_t _search_index(float x);
    f_array _a;
    f_array _b;
    f_array _c;
    f_array _d;
    f_array _w;
    std::vector<float> _x;
    std::vector<float> _y;
    uint8_t _x_len;
    uint8_t _y_len;
};

class CubicSpline2D
{
public:
    explicit CubicSpline2D(std::vector<float> x, std::vector<float> y);
    std::vector<float> toVector(f_array arr);
    std::vector<float> CalculatePosition(float s);
    float CalculateCurvature(float s);
    float CalculateYaw(float s);
    f_array _s;
    ~CubicSpline2D();
private:
    f_array _calc_s(f_array x, f_array y);
    std::vector<float> _x;
    std::vector<float> _y;
    CubicSpliner *_sx;
    CubicSpliner *_sy;
    f_array _ds;
};

#endif // WS_RRT_CUBICSPLINES_H