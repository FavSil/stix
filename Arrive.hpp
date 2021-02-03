//
//  Arrive.hpp
//  Stranded
//
//  Created by Favian Silva on 2021-01-15.
//

#ifndef Arrive_hpp
#define Arrive_hpp

#include <stdio.h>
#include "Entity.hpp"

class Arrive
{
public:
    Entity* character;
    Entity* target;
    float maxAcceleration = 10;
    float timeToTarget = 0.1;
    float targetRadius = 20;
    float slowRadius = 100;
    SteeringOutput getSteering();
    Arrive(Entity *k1, Entity *k2);
    
};
#endif /* Arrive_hpp */

