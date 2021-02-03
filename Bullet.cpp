//
//  Bullet.cpp
//  Stranded
//
//  Created by Favian Silva on 2021-01-09.
//

#include <SDL2/SDL.h>
#include "Bullet.hpp"

Bullet::Bullet(int x, int y, LTexture& texture)
{

    mBox.x = x + 20;
    mBox.y = y + 20;
    mBox.w = BULLET_WIDTH;
    mBox.h = BULLET_HEIGHT;
    live = true;

    gBulletTexture = texture;
}

void Bullet::move( Tile *tiles[])



{
    //Move the dot left or right
    mBox.x += 0;

    //If the bullet went too far to the left or right or touched a wall
    if( ( mBox.x < 0 ) || ( mBox.x + BULLET_WIDTH > Tile::LEVEL_WIDTH ) || touchesWall( mBox, tiles ) )
    {
        //move back
        mBox.x -= 20;
        live = false;
    }

    //Move the bullet up or down
    mBox.y -= 20;

    //If the dot went too far up or down or touched a wall
    if( ( mBox.y < 0 ) || ( mBox.y + BULLET_HEIGHT > Tile::LEVEL_HEIGHT ) || touchesWall( mBox, tiles ) )
    {
        
        //move back
        mBox.y -= 20;
        live = false;
    }
}

void Bullet::render(SDL_Rect& camera)
{
    gBulletTexture.render( mBox.x - camera.x, mBox.y - camera.y);

}

