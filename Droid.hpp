//
//  Droid.hpp
//  Stranded
//
//  Created by Favian Silva on 2021-01-15.
//

#ifndef Droid_hpp
#define Droid_hpp

#include <stdio.h>
#include "LivingEntity.hpp"
#include "Arrive.hpp"
#include <iostream>

class Droid: public LivingEntity{
    
public:
    static const int DROID_HEIGHT = 25;
    static const int DROID_WIDTH = 25;
    static const int DROID_STATE_IDLE = 0;
    static const int DROID_STATE_MOVE = 1;
    static const int DROID_STATE_DEAD = 2;

    static const int DROID_AI_NORMAL = 0;
    static const int DROID_AI_CHASE = 1;
    const float maxSpeed = 20;
    
    LivingEntity* target = NULL;

    int aiState = DROID_AI_NORMAL;
    void die();
    void think(Entity* target);
    void render( SDL_Rect& camera );
    Droid(LTexture& texture, int xOffset, int yOffset);
    LTexture gDroidTexture;
};

#endif /* Droid_hpp */
