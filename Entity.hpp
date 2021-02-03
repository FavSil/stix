//
//  Entity.hpp
//  Stranded
//
//  Created by Favian Silva on 2021-01-09.
//

#ifndef Entity_hpp
#define Entity_hpp

#include <stdio.h>
#include <string>
#include <list>
#include <SDL2/SDL.h>
#include "LTexture.hpp"
#include "Eigen/Dense"
#include "SteeringOutput.hpp"
#include "Tile.hpp"
#include "timeController.hpp"
class Entity
{
    
public:
    //Tile constants
    const int TILE_WIDTH = 80;
    const int TILE_HEIGHT = 80;
    const int TOTAL_TILES = 192;
    const int TOTAL_TILE_SPRITES = 12;

    const int TILE_RED = 0;
    const int TILE_GREEN = 1;
    const int TILE_BLUE = 2;
    const int TILE_CENTER = 3;
    const int TILE_TOP = 4;
    const int TILE_TOPRIGHT = 5;
    const int TILE_RIGHT = 6;
    const int TILE_BOTTOMRIGHT = 7;
    const int TILE_BOTTOM = 8;
    const int TILE_BOTTOMLEFT = 9;
    const int TILE_LEFT = 10;
    const int TILE_TOPLEFT = 11;

    Eigen::Vector2d position;
    float orientation;
    
    Eigen::Vector2d velocity;
    float rotation;
    
    bool active = true;
    std::string type;
    //Box collision detector
    static bool checkCollision( SDL_Rect a, SDL_Rect b );
    static float angleBetweenTwoPoints(float cx1, float cy1, float cx2, float cy2);
    static float distanceBetweenTwoEntities(Entity *e1, Entity *e2);
    
    virtual void update(SteeringOutput steering);
    
    bool touchesWall(SDL_Rect, Tile* tiles[]);
    
    //global entities list I can refer to at anytime
    static std::list<Entity*> entities;
    static bool EntityCompare(const Entity* const &a, const Entity * const &b); //compare 2 entities in a list to help sorting (sorts based on y value)
    static void removeInactiveEntitiesFromList(std::list<Entity*> *entityList, bool deleteEntities);
    static void removeAllFromList(std::list<Entity*> *entityList, bool deleteEntities);
};
#endif /* Entity_hpp */
