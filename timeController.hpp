//
//  timeController.hpp
//  Stranded
//
//  Created by Favian Silva on 2021-01-14.
//

#ifndef timeController_hpp
#define timeController_hpp

#include <stdio.h>
#include "SDL2/SDL.h"

class TimeController{
public:
    //reference values
    static const int PLAY_STATE, PAUSE_STATE;

    int timeState;
    Uint32 lastUpdate; //last time we checked how many ticks we were up to
    float dT; //delta time, in seconds (1= 1 second, 0.5 is half a second). Time since the last frame was rendered onto screen

    TimeController();
    void updateTime();//update lastUpdate and dT
    void pause();
    void resume();
    void reset();

    static TimeController timeController;
};

#endif /* timeController_hpp */
