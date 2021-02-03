//
//  Bullet.hpp
//  Stranded
//
//  Created by Favian Silva on 2021-01-09.
//

#ifndef Bullet_hpp
#define Bullet_hpp

#include <stdio.h>
#include <SDL2/SDL.h>
#include "LTexture.hpp"
#include "Tile.hpp"
#include "Entity.hpp"
class Bullet: public Entity
{
public:
    static const int BULLET_WIDTH = 4;
    static const int BULLET_HEIGHT = 4;
    bool live;
    Bullet(int x, int y, LTexture& texture);
        
    void move(Tile *tiles[]);
    
    void render(SDL_Rect& camera);
    
private:
    //Collision box of the dot
    SDL_Rect mBox;

    LTexture gBulletTexture;
    //The velocity of the dot
    int mVelX, mVelY;

};

#endif /* Bullet_hpp */
