#include "EventHandler.h"

void BearEngine::EventHandler::update(){
    keystates = SDL_GetKeyboardState(NULL);
    MouseEvent ce;
    while(SDL_PollEvent(&e)){
        if(e.type == SDL_QUIT){
            this->onQuit();
        }
        if(e.type == SDL_MOUSEBUTTONUP){
//            e.button
            ce.me = EventAction::UP;
        }
        if(e.type == SDL_MOUSEBUTTONDOWN){
            ce.me = EventAction::DOWN;
        }
        if(e.type == SDL_MOUSEMOTION){
            ce.me = EventAction::MOVED;
        }
    }
    for(itKMap i = KeyActionMap.begin(); i != KeyActionMap.end(); i++){
        if(keystates[i->first]){
            i->second();
        }
    }
}

void BearEngine::EventHandler::addEvent(Uint32 event, std::function<void()> action){
    KeyActionMap[event] = action;
}