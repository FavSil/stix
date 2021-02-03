//
//  LivingEntity.hpp
//  Stranded
//
//  Created by Favian Silva on 2021-01-18.
//

#ifndef LivingEntity_hpp
#define LivingEntity_hpp

#include <stdio.h>
#include "Entity.hpp"
class LivingEntity: public Entity
{
public:
    int hp;
    bool alive;
    virtual void die() = 0;
};
#endif /* LivingEntity_hpp */
