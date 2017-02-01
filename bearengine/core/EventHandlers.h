#ifndef BEARENGINE_CMAKE_EVENTHANDLERS_H
#define BEARENGINE_CMAKE_EVENTHANDLERS_H

#include <vector>
#include <functional>
#include <map>
#include <memory>

#include "SDL.h"

#include "Macros.h"
#include "Structures.h"

namespace BearEngine {

    class EventHandler {
    public:
        virtual void handleEvents(std::vector<SDL_Event>&, BearEngine::NodeTransform) = 0;
    };

    class MouseEventHandler : public BearEngine::EventHandler{

    public:

        CREATE_FUNC(BearEngine::MouseEventHandler);

        MouseEventHandler(){};
        virtual ~MouseEventHandler(){};

        void handleEvents(std::vector<SDL_Event>&, BearEngine::NodeTransform) override;

        void setOnMouseClick(std::function<void(const SDL_Event & e, BearEngine::NodeTransform)>);
        void setOnMouseRelease(std::function<void(const SDL_Event & e, BearEngine::NodeTransform)>);
        void setOnMouseMove(std::function<void(const SDL_Event & e, BearEngine::NodeTransform)>);

    protected:

        std::function<void(const SDL_Event & e, BearEngine::NodeTransform)> _on_mouse_click    = [](const SDL_Event & e, BearEngine::NodeTransform){};
        std::function<void(const SDL_Event & e, BearEngine::NodeTransform)> _on_mouse_release  = [](const SDL_Event & e, BearEngine::NodeTransform){};
        std::function<void(const SDL_Event & e, BearEngine::NodeTransform)> _on_mouse_move     = [](const SDL_Event & e, BearEngine::NodeTransform){};
    };

    class KeyboardEventHandler : public BearEngine::EventHandler{

    public:

        CREATE_FUNC(BearEngine::KeyboardEventHandler);

        KeyboardEventHandler(){};
        virtual ~KeyboardEventHandler(){};

        void handleEvents(std::vector<SDL_Event>&, BearEngine::NodeTransform) override;

        void setKeyEvent(Uint32, std::function< void() >);
        void unsetKeyEvent(Uint32);

    private:
        std::map< Uint32, std::function< void() > > _key_map;
    };

}


#endif //BEARENGINE_CMAKE_EVENTHANDLERS_H
