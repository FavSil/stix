//
//  Arrive.cpp
//  Stranded
//
//  Created by Favian Silva on 2021-01-15.
//

#include "Arrive.hpp"
#include "iostream"

Arrive::Arrive(Entity *k1, Entity *k2){
    character = k1;
    target = k2;
    
    float maxSpeed = character->maxSpeed;

    
}
SteeringOutput Arrive::getSteering(){
    SteeringOutput result;
    
    Vector2d direction  = target->position - character->position;


    float distance = direction.norm(); // length of vector
        result.linear = Vector2d(0,0);
        result.angular = 0;
        return result;
    }
    float targetSpeed;
    if(distance > slowRadius){
        targetSpeed = maxSpeed;
    }
    else
    {
        targetSpeed = maxSpeed * distance / slowRadius;
    }
    Vector2d targetVelocity = direction;
    targetVelocity.normalize();
    targetVelocity *= targetSpeed;
    
    result.linear = targetVelocity - character->velocity;
    std::cout << "tvelo * targetSpeed" << targetVelocity << std::endl ;

    result.linear /= timeToTarget;

    if(result.linear.norm() > maxAcceleration){
        result.linear.normalize();
        result.linear *= maxAcceleration;
    }
    result.angular = 0;

    return result;
}
