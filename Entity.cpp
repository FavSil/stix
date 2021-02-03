//
//  Entity.cpp
//  Stranded
//
//  Created by Favian Silva on 2021-01-09.
//

#include "Entity.hpp"



bool Entity::checkCollision( SDL_Rect a, SDL_Rect b )

{
    //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = a.x;
    rightA = a.x + a.w;
    topA = a.y;
    bottomA = a.y + a.h;

    //Calculate the sides of rect B
    leftB = b.x;
    rightB = b.x + b.w;
    topB = b.y;
    bottomB = b.y + b.h;

    //If any of the sides from A are outside of B
    if( bottomA <= topB )
    {
        return false;
    }

    if( topA >= bottomB )
    {
        return false;
    }

    if( rightA <= leftB )
    {
        return false;
    }

    if( leftA >= rightB )
    {
        return false;
    }

    //If none of the sides from A are outside B
    return true;
}

bool Entity::touchesWall( SDL_Rect box, Tile* tiles[] )
{
    //Go through the tiles
    for( int i = 0; i < TOTAL_TILES; ++i )
    {
        //If the tile is a wall type tile
        if( ( tiles[ i ]->getType() >= TILE_CENTER ) && ( tiles[ i ]->getType() <= TILE_TOPLEFT ) )
        {
            //If the collision box touches the wall tile
            if( checkCollision( box, tiles[ i ]->getBox() ) )
            {
                return true;
            }
        }
    }

    //If no wall tiles were touched
    return false;
}


void Entity::update(SteeringOutput steering)
{
    position += velocity * TimeController::timeController.dT;
    orientation += rotation * TimeController::timeController.dT;
    
    velocity += steering.linear * TimeController::timeController.dT;
    rotation += steering.angular * TimeController::timeController.dT;

}

float Entity::angleBetweenTwoPoints(float cx1, float cy1, float cx2, float cy2){
    float dx = cx2 - cx1;
    float dy = cy2 - cy1;

    return atan2(dy, dx) * 180 / 3.142;
}

float Entity::distanceBetweenTwoEntities(Entity *e1, Entity *e2){
    float d = abs(sqrt(pow(e2->position[0] - e1->position[0], 2) + pow(e2->position[1] - e1->position[1], 2)));
    return d;
}



std::list<Entity*> Entity::entities;
bool Entity::EntityCompare(const Entity* const &a, const Entity * const &b){
    if (a != 0 && b != 0)
    {
        return (a->position[1] < b->position[1]);
    }
    else
    {
        return false;
    }
}
void Entity::removeInactiveEntitiesFromList(std::list<Entity*> *entityList, bool deleteEntities){
    for (auto entity = entityList->begin(); entity != entityList->end();){
        //if entity is not active
        if (!(*entity)->active){
            if (deleteEntities)
                delete (*entity);
            entity = entityList->erase(entity);
        }
        else
        {
            entity++;
        }
    }
}
void Entity::removeAllFromList(std::list<Entity*> *entityList, bool deleteEntities){
    for (auto entity = entityList->begin(); entity != entityList->end();){
        if (deleteEntities)
            delete (*entity);
        entity = entityList->erase(entity);
    }
}
