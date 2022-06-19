//
// Created by octominus on 19.06.2022.
//

#include "ValidityChecker.h"

/*
    double clearance(const ob::State* state) const
    {
        // We know we're working with a RealVectorStateSpace in this
        // example, so we downcast state into the specific type.
        const ob::RealVectorStateSpace::StateType* state2D =
            state->as<ob::RealVectorStateSpace::StateType>();
 
        // Extract the robot's (x,y) position from its state
        double x = state2D->values[0];
        double y = state2D->values[1];
 
        // Distance formula between two points, offset by the circle's
        // radius
        return sqrt((x-0.5)*(x-0.5) + (y-0.5)*(y-0.5)) - 0.25;
    }
*/

ValidityChecker::ValidityChecker(const ob::SpaceInformationPtr &si, const nav_msgs::OccupancyGrid::ConstPtr &map_data) : 
    ob::StateValidityChecker(si), _map_width(map_data->info.width), _map_height(map_data->info.height), _map_resolation(map_data->info.resolution), _map_data(map_data->data) {
       // std::cout << "Validity Function Status: Loaded!" << std::endl;
       // std::cout << "About Map\n" << "----------\n"
       // << "Height(m): " << _map_height*_map_resolation << std::endl
       // << "Width(m): " << _map_width*_map_resolation << std::endl
       // << "Res(m/px): " << _map_resolation << std::endl;
       // std::cout << "#############" << std::endl;
}

// Haritaki pixel için beyaz olup olmadığının ölçümü yapılıyor.
bool ValidityChecker::isWhite(double x, double y, int8_t threshold) const {
    int x_pixel = std::floor(x / _map_resolation);
    int y_pixel = std::floor(y / _map_resolation);
    int pixel_index = x_pixel + (y_pixel * _map_width);
    int pixel_data = _map_data[pixel_index];
   
    // std::cout << "Pixel Data of " 
    // << "(x:" << x_pixel
    // << ", y:" << y_pixel
    // << ")= "  << pixel_data
    // << std::endl;
    // Returned Value from Pixel Data: White color=0, Black color=100

    return (pixel_data < threshold);
}

bool ValidityChecker::isValid(const ob::State *state) const {
    const ob::RealVectorStateSpace::StateType *state2D =
    state->as<ob::RealVectorStateSpace::StateType>();
    // Extract the robot's (x,y) position from its state
    double x_meter = state2D->values[0];
    double y_meter = state2D->values[1];
    
    return (y_meter < _map_height) && isWhite(x_meter, y_meter, 80);
}

