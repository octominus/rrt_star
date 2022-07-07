//
// Created by octominus on 26.06.2022.
// 

#include "CubicSpliner.h"

CubicSpliner::CubicSpliner(std::vector<float> x, std::vector<float> y) : _x(x), _y(y) {
    std::vector<float> b, d;

    auto x_array = xt::adapt(_x);
    auto y_array = xt::adapt(_y);
    
    // std::cout << x_array << std::endl;
    // std::cout << y_array << std::endl;

    _x_len = x_array.size();
    _y_len = y_array.size();
    f_array x_diff = xt::diff(x_array);

    // coefficent calc.
    _a = y_array;
    f_array A = _calc_A(x_diff);
    f_array B = xt::transpose(_calc_B(x_diff));
    _c = xt::linalg::solve(A, B);

    // std::cout << A << std::endl;
    // std::cout << B << std::endl;
    // std::cout << _c << std::endl;

    uint8_t index;
    for (index = 0; index < (_x_len-1); index++) {
        /* code */
        d.push_back((_c(index + 1) - _c(index)) / (3.0 * x_diff(index)));
        float tb = ((_a(index + 1) - _a[index]) / x_diff(index)) - (x_diff(index) * (_c(index + 1) + 2.0 * _c(index)) / 3.0);
        b.push_back(tb);
    }

    _d = xt::adapt(d);
    _b = xt::adapt(b);

    // std::cout << _d << std::endl;
    // std::cout << _b << std::endl;
}

f_array CubicSpliner::_calc_A(f_array arr) {
    f_array A = xt::zeros<float>({_x_len, _x_len});
    A(0, 0) = 1.0;
    uint8_t index;
    for (index = 0; index < (_x_len-1); index++) {
        if ( index != (_x_len-2) ) {
            A(index + 1, index + 1) = 2.0 * (arr(index) + arr(index + 1));
        }
        A(index + 1, index) = arr(index);
        A(index, index + 1) = arr(index);
    }
    A(0, 1) = 0.0;
    A(_x_len - 1, _x_len - 2) = 0.0;
    A(_x_len - 1, _x_len - 1) = 1.0;
    return A;
}

f_array CubicSpliner::_calc_B(f_array arr) {
    f_array B = xt::zeros<float>({_x_len});
    uint8_t index;
    for (index = 0; index < (_x_len-2); index++) {
        B(index + 1) = 3.0 * (_a(index + 2) - _a(index + 1)) / (arr(index + 1) - (3.0 * (_a(index + 1) - _a(index)) / arr(index)));
    }
    return B;
}

float CubicSpliner::CalculatePosition(float t) {
    // calculate position
    if (t < _x.front()) {
        return 0.0;
    } else if (t > _x.back()) {
        return 0.0;
    }
    uint8_t index = _search_index(t);
    float dx = t - _x[index];
    float result = (_a(index)) + (_b(index) * dx) + (_c(index) * pow(dx, 2)) + (_d(index) * pow(dx, 3));
    return result;
}

float CubicSpliner::CalculateFirstDerivative(float t) {
    // calculate first derivative
    if (t < _x.front()) {
        return 0.0;
    } else if (t > _x.back()) {
        return 0.0;
    }
    uint8_t index = _search_index(t);
    float dx = t - _x[index];
    float result = (_b(index)) + (2.0 * _c(index) * dx) + (3.0 * _d(index) * pow(dx, 2));
    return result;
}

float CubicSpliner::CalculateSecondDerivative(float t) {
    if (t < _x.front()) {
        return 0.0;
    } else if (t > _x.back()) {
        return 0.0;
    }
    uint8_t index = _search_index(t);
    float dx = t - _x[index];
    float result = (2.0 * _c(index)) + (6.0 * _d(index) * dx);
    return result;
}

uint8_t CubicSpliner::_search_index(float x) {
    uint8_t index = 0, arr_index = 0;
    std::vector<float> x_arr = _x;
    sort(x_arr.begin(), x_arr.end());
    for (index = 0; index < x_arr.size(); index++) {
        if (x_arr[index] > x) {
            arr_index = index - 1;
            break;
        }
    }
    return arr_index;
}
