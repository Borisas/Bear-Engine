#include "EventHandlers.h"

using namespace BearEngine;

void MouseEventHandler::handleEvents(std::vector<SDL_Event> & events) {

    for(auto e : events){

        if(e.type == SDL_MOUSEBUTTONDOWN){
            _on_mouse_click(e);
        }
        if(e.type == SDL_MOUSEBUTTONUP){
            _on_mouse_release(e);
        }
        if(e.type == SDL_MOUSEMOTION){
            _on_mouse_move(e);
        }

    }

}

void KeyboardEventHandler::handleEvents(std::vector<SDL_Event> & events) {

}