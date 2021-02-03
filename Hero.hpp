//
//  Dot.hpp
//  Stranded
//
//  Created by Favian Silva on 2021-01-09.
//

#ifndef Dot_hpp
#define Dot_hpp

#include <stdio.h>
#include <SDL2/SDL.h>
#include "LTexture.hpp"
#include "Tile.hpp"
#include "LivingEntity.hpp"
class Hero: public LivingEntity
{
public:
    //The dimensions of the dot
    static const int DOT_WIDTH = 40;
    static const int DOT_HEIGHT = 40;
    const int SCREEN_WIDTH = 720;
    const int SCREEN_HEIGHT = 480;
    
    //The dimensions of the level
    const int LEVEL_WIDTH = 1280;
    const int LEVEL_HEIGHT = 960;

    //Maximum axis velocity of the dot
    static const int DOT_VEL = 8;
    bool isShooting;
    
    
    //Initializes the variables
    Hero(LTexture& texture);

    void getAngle(SDL_Rect& camera, SDL_Event& e);
    //Takes key presses and adjusts the dot's velocity
    void handleEvent( SDL_Event& e );

    //Moves the dot and check collision against tiles
    void move( Tile *tiles[] );

    //Centers the camera over the dot
    void setCamera( SDL_Rect& camera );

    //Shows the dot on the screen
    void render( SDL_Rect& camera );

    
    void die();
        SDL_Rect getPosition();
    
    
    private:
    
        LTexture gHeroTexture;
        //Collision box of the dot
        SDL_Rect mBox;
        float angle;
        //The velocity of the dot
        int mVelX, mVelY;

};

#endif /* Dot_hpp */
