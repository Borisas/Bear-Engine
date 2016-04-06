#include "EventHandler.h"

void BearEngine::EventHandler::update(){
    keystates = SDL_GetKeyboardState(NULL);
    while(SDL_PollEvent(&e)){
        if(e.type == SDL_QUIT){
            this->onQuit();
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