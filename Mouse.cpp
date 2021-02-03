//
//  Mouse.cpp
//  Stranded
//
//  Created by Favian Silva on 2021-01-09.
//

#include "Mouse.hpp"
#include "LTexture.hpp"

Mouse::Mouse(LTexture& texture)
{
    mPosition.x = 0;
    mPosition.y = 0;
    
    gMouseTexture = texture;
}

void Mouse::setPosition()
{
    int x, y;
    SDL_GetMouseState( &x, &y );
    
    mPosition.x = x;
    mPosition.y = y;
}

void Mouse::handleEvent( SDL_Event* e )
{
    //If mouse event happened
    if( e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP )
    {
        //Get mouse position
        int x, y;
        SDL_GetMouseState( &x, &y );

        //Check if mouse is in button
        bool inside = true;

        //Mouse is left of the button
        if( x < mPosition.x )
        {
            inside = false;
        }
        //Mouse is right of the button
        else if( x > mPosition.x + MOUSE_WIDTH )
        {
            inside = false;
        }
        //Mouse above the button
        else if( y < mPosition.y )
        {
            inside = false;
        }
        //Mouse below the button
        else if( y > mPosition.y + MOUSE_HEIGHT )
        {
            inside = false;
        }

        //Mouse is outside button
        if( !inside )
        {
//            mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
        }
        //Mouse is inside button
        else
        {

            //Set mouse over sprite
            switch( e->type )
            {
                case SDL_MOUSEMOTION:
//                mCurrentSprite = BUTTON_SPRITE_MOUSE_OVER_MOTION;
                break;
            
                case SDL_MOUSEBUTTONDOWN:
//                mCurrentSprite = BUTTON_SPRITE_MOUSE_DOWN;
                break;
                
                case SDL_MOUSEBUTTONUP:
//                mCurrentSprite = BUTTON_SPRITE_MOUSE_UP;
                break;
            }
        }
    }
}
    
void Mouse::render()
{
    //Show current button sprite
    gMouseTexture.render( mPosition.x-5, mPosition.y-5 );
}
