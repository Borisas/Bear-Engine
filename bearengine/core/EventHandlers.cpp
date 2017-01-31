#include "EventHandlers.h"

using namespace BearEngine;

// ========
// MOUSE EVENT HANDLER
// ========
void MouseEventHandler::handleEvents(std::vector<SDL_Event> & events) {

    for(auto e : events){

        if(e.type == SDL_MOUSEBUTTONDOWN){
            _on_mouse_click(e);
        }
        else if(e.type == SDL_MOUSEBUTTONUP){
            _on_mouse_release(e);
        }
        else if(e.type == SDL_MOUSEMOTION){
            _on_mouse_move(e);
        }

    }

}

void MouseEventHandler::setOnMouseClick(std::function<void(const SDL_Event &e)> action) {
    _on_mouse_click = action;
}

void MouseEventHandler::setOnMouseRelease(std::function<void(const SDL_Event &e)> action) {
    _on_mouse_release = action;
}

void MouseEventHandler::setOnMouseMove(std::function<void(const SDL_Event &e)> action) {
    _on_mouse_move = action;
}

// ========

// ========
// KEYBOARD EVENT HANDLER
// ========
void KeyboardEventHandler::handleEvents(std::vector<SDL_Event> & events) {

    for(auto e : events){
        if(e.type == SDL_KEYDOWN){
            for(auto k : _key_map){
                if(e.key.keysym.scancode == k.first){
                    k.second();
                }
            }
        }
    }

}

void KeyboardEventHandler::setKeyEvent(Uint32 keycode, std::function<void()> action) {
    _key_map[keycode] = action;
}

void KeyboardEventHandler::unsetKeyEvent(Uint32 keycode) {
    auto found = _key_map.find(keycode);

    if(found != _key_map.end())
        _key_map.erase(found);
}
// ========