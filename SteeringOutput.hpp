//
//  SteeringOutput.hpp
//  Stranded
//
//  Created by Favian Silva on 2021-01-14.
//

#ifndef SteeringOutput_h
#define SteeringOutput_h
#include "Eigen/Dense"
using namespace Eigen;
class  SteeringOutput
{
public:
    Vector2d linear;
    float angular;
};

#endif /* SteeringOutput_h */
