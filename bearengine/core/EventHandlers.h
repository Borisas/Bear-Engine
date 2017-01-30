#ifndef BEARENGINE_CMAKE_EVENTHANDLERS_H
#define BEARENGINE_CMAKE_EVENTHANDLERS_H

#include <vector>
#include <functional>

#include "SDL.h"

namespace BearEngine {

    class EventHandler {
    public:
        virtual void handleEvents(std::vector<SDL_Event>&) = 0;
    };

    class MouseEventHandler : public BearEngine::EventHandler{

    public:

        void handleEvents(std::vector<SDL_Event>&) override;

    private:

        std::function<void(SDL_Event e)> _on_mouse_click    = [](SDL_Event e){};
        std::function<void(SDL_Event e)> _on_mouse_release  = [](SDL_Event e){};
        std::function<void(SDL_Event e)> _on_mouse_move     = [](SDL_Event e){};
    };

    class KeyboardEventHandler : public BearEngine::EventHandler{

    public:

        void handleEvents(std::vector<SDL_Event>&) override;

    private:

    };

}


#endif //BEARENGINE_CMAKE_EVENTHANDLERS_H
