//
//  Droid.cpp
//  Stranded
//
//  Created by Favian Silva on 2021-01-15.
//

#include "Droid.hpp"


//TODO make proper spawning points
Droid::Droid(LTexture& texture, int xOffset, int yOffset)
{
    //Initialize the collision box
    hp = 5;
    position[0] = xOffset;
    position[1] = yOffset;
    
    velocity[0] = 0;
    velocity[1] = 0;

    alive = true;
    orientation = 0;
    gDroidTexture = texture;
}


void Droid::think(Entity *target)
{
    //found a target and its alive, lets get 'em
    
    if (target != NULL)
    {
        float dist = abs(sqrt(pow(target->position[0] - position[0], 2) + pow(target->position[1] - position[1], 2)));

        //if in range, ATTACK!
        if (dist > 500)
        {
//            SteeringOutput steering;
//            steering.angular = 0;
//            steering.linear = Vector2d(0,0);
            aiState = DROID_AI_NORMAL;
//            return steering;
        }
        else
        {
            //otherwise chase the player
            aiState = DROID_AI_CHASE;
            Arrive steerRequest(this, target);
            SteeringOutput steering = steerRequest.getSteering();
//            std::cout << "found you";

//            std::cout << "x:" << position[0] << " y:" << position[1];
            update(steering);
        }
    }
    else
    {
        //no targets, go idle
//        moving = false;
//        SteeringOutput steering;
//        steering.angular = 0;
//        steering.linear = Vector2d(0,0);
//        aiState = DROID_AI_NORMAL;
//        return steering;
    }
}



void Droid::render( SDL_Rect& camera )
{
    //Show the dot
//    std::cout << "x:" << position[0] << " y:" << position[1];

    gDroidTexture.render( position[0] - camera.x, position[1] - camera.y, NULL, orientation + 45);
}

void Droid::die()
{
    bool alive = false;
}
