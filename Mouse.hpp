//
//  Mouse.hpp
//  Stranded
//
//  Created by Favian Silva on 2021-01-09.
//

#ifndef Mouse_hpp
#define Mouse_hpp

#include <stdio.h>
#include "LTexture.hpp"
#include "Entity.hpp"
class Mouse: public Entity
{
public:
    static const int MOUSE_WIDTH = 20;
    static const int MOUSE_HEIGHT = 20;
    //Initializes internal variables
      Mouse(LTexture& texture);

      //Sets top left position
      void setPosition();

      //Handles mouse event
      void handleEvent( SDL_Event* e );
  
      //Shows button sprite
      void render();
private:
    //Top left position
    SDL_Point mPosition;

    LTexture gMouseTexture;
    //Currently used global sprite
//    LButtonSprite mCurrentSprite;

};
#endif /* Mouse_hpp */
