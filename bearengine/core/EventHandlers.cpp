#include "EventHandlers.h"

using namespace BearEngine;

// ========
// MOUSE EVENT HANDLER
// ========
void MouseEventHandler::handleEvents(std::vector<SDL_Event> & events, BearEngine::NodeTransform transform) {

    for(auto e : events){

        if(e.type == SDL_MOUSEBUTTONDOWN){
            _on_mouse_click(e, transform);
        }
        else if(e.type == SDL_MOUSEBUTTONUP){
            _on_mouse_release(e, transform);
        }
        else if(e.type == SDL_MOUSEMOTION){
            _on_mouse_move(e, transform);
        }

    }

}

void MouseEventHandler::setOnMouseClick(std::function<void(const SDL_Event &e, BearEngine::NodeTransform transform)> action) {
    _on_mouse_click = action;
}

void MouseEventHandler::setOnMouseRelease(std::function<void(const SDL_Event &e, BearEngine::NodeTransform transform)> action) {
    _on_mouse_release = action;
}

void MouseEventHandler::setOnMouseMove(std::function<void(const SDL_Event &e, BearEngine::NodeTransform transform)> action) {
    _on_mouse_move = action;
}

// ========

// ========
// KEYBOARD EVENT HANDLER
// ========
void KeyboardEventHandler::handleEvents(std::vector<SDL_Event> & events, BearEngine::NodeTransform) {

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



SimpleKeyboardEventHandler::SimpleKeyboardEventHandler(){

}
SimpleKeyboardEventHandler::~SimpleKeyboardEventHandler(){

}

void SimpleKeyboardEventHandler::handleEvents(std::vector<SDL_Event>& events, BearEngine::NodeTransform){
    for ( auto e : events) {
        if ( e.type == SDL_KEYDOWN ) {
            auto k = e.key.keysym.scancode;

            if ( k == 225 || k == 229 ) {
                _shift = true;
            }
            if ( k == 224 || k == 228 ) {
                _ctrl = true;
            }
            if ( k == 226 || k == 230 ) {
                _alt = true;
            }

            const char* scanCodeName = SDL_GetScancodeName(k);

            auto keydata = Key(k,Util::KeycodeToChar(k, _shift),_shift,_ctrl,_alt,SDL_GetScancodeName(k));

            onKeyDown(keydata);

        }
        else if ( e.type == SDL_KEYUP ) {
            auto k = e.key.keysym.scancode;


            if ( k == 225 || k == 229 ) {
                _shift = false;
            }
            if ( k == 224 || k == 228 ) {
                _ctrl = false;
            }
            if ( k == 226 || k == 230 ) {
                _alt = false;
            }

            auto keydata = Key(k,Util::KeycodeToChar(k, _shift),_shift,_ctrl,_alt,SDL_GetScancodeName(k));

            onKeyUp(keydata);
        }
    }
}