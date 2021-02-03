//
//  Dot.cpp
//  Stranded
//
//  Created by Favian Silva on 2021-01-09.
//

#include "Hero.hpp"
#include "iostream"
Hero::Hero(LTexture& texture)
{
    //Initialize the collision box
    hp = 20;
    mBox.x = 0;
    mBox.y = 0;
    mBox.w = DOT_WIDTH;
    mBox.h = DOT_HEIGHT;

    //Initialize the velocity
    mVelX = 0;
    mVelY = 0;
    
    position[0] = mBox.x;
    position[1] = mBox.y;
    
    velocity[0] = mVelX;
    velocity[1] = mVelY;
    type = "dot";
    alive = true;
    gHeroTexture = texture;
}

void Hero::getAngle(SDL_Rect& camera, SDL_Event& e)
{
    //Get mouse position
    if( e.type == SDL_MOUSEMOTION ){
        int x, y;
        SDL_GetMouseState( &x, &y );
            
        angle = angleBetweenTwoPoints(mBox.x + (DOT_WIDTH / 2) - camera.x, mBox.y + (DOT_HEIGHT / 2) - camera.y, x, y);
    }

}

void Hero::handleEvent( SDL_Event& e )
{

    
    //If a key was pressed
    if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_w: mVelY -= DOT_VEL; break;
            case SDLK_s: mVelY += DOT_VEL; break;
            case SDLK_a: mVelX -= DOT_VEL; break;
            case SDLK_d: mVelX += DOT_VEL; break;
        }
    }
    
    //If a key was released
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_w: mVelY += DOT_VEL; break;
            case SDLK_s: mVelY -= DOT_VEL; break;
            case SDLK_a: mVelX += DOT_VEL; break;
            case SDLK_d: mVelX -= DOT_VEL; break;
        }
    }
    velocity[0] = mVelX;
    velocity[1] = mVelY;
}

void Hero::move( Tile *tiles[] )
{
    //Move the dot left or right
    mBox.x += mVelX;

    //If the dot went too far to the left or right or touched a wall
    if( ( mBox.x < 0 ) || ( mBox.x + DOT_WIDTH > LEVEL_WIDTH ) || touchesWall( mBox, tiles ) )
    {
        //move back
        mBox.x -= mVelX;
    }

    //Move the dot up or down
    mBox.y += mVelY;

    //If the dot went too far up or down or touched a wall
    if( ( mBox.y < 0 ) || ( mBox.y + DOT_HEIGHT > LEVEL_HEIGHT ) || touchesWall( mBox, tiles ) )
    {
        //move back
        mBox.y -= mVelY;
    }
    position[0] = mBox.x;
    position[1] = mBox.y;
    
}

void Hero::setCamera( SDL_Rect& camera )
{
    //Center the camera over the dot
    camera.x = ( mBox.x + DOT_WIDTH / 2 ) - SCREEN_WIDTH / 2;
    camera.y = ( mBox.y + DOT_HEIGHT / 2 ) - SCREEN_HEIGHT / 2;

    //Keep the camera in bounds
    if( camera.x < 0 )
    {
        camera.x = 0;
    }
    if( camera.y < 0 )
    {
        camera.y = 0;
    }
    if( camera.x > LEVEL_WIDTH - camera.w )
    {
        camera.x = LEVEL_WIDTH - camera.w;
    }
    if( camera.y > LEVEL_HEIGHT - camera.h )
    {
        camera.y = LEVEL_HEIGHT - camera.h;
    }
}

void Hero::render( SDL_Rect& camera )
{
    //Show the dot
    gHeroTexture.render( mBox.x - camera.x, mBox.y - camera.y, NULL, angle + 90 );
}

SDL_Rect Hero::getPosition()
{
    return mBox;
}

void Hero::die()
{
    bool alive = false;
}
