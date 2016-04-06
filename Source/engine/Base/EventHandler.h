#ifndef BE_EVENTHANDLER_H
#define BE_EVENTHANDLER_H


#include "SDL2/SDL.h"
#include <functional>
#include <iostream>
#include <map>

typedef std::map< Uint32, std::function<void ()> > KMap;
typedef KMap::iterator itKMap;

namespace BearEngine{
    class EventHandler{
    public:
        static EventHandler* create();
        void update();
        void clearFunctions();

        std::function<void()> onQuit = [&](){};

        KMap KeyActionMap;
        
        void addEvent(Uint32 event, std::function<void()> action);

    private:
        SDL_Event e;
        const Uint8* keystates;// = SDL_GetKeyboardState( NULL );
    };
}

#endif
