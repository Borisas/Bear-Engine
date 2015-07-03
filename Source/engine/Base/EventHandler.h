#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H


#include "SDL2/SDL.h"
#include <functional>
#include <iostream>
#include <map>

typedef std::map< Uint32, std::function<void ()> > KMap;
typedef KMap::iterator itKMap;

class EventHandler{
public:
    static EventHandler* create();
    void Update();
    void ClearFunctions();

    std::function<void()> onQuit = [&](){};
    
    std::function<void()> onW = [&](){};
    std::function<void()> onD = [&](){};
    std::function<void()> onS = [&](){};
    std::function<void()> onA = [&](){};

    KMap KeyActionMap;

private:
    SDL_Event e;
    const Uint8* keystates;// = SDL_GetKeyboardState( NULL );
};

#endif
