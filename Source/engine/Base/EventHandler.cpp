#include "EventHandler.h"

BearEngine::EventHandler* BearEngine::EventHandler::create(){
    auto c = new EventHandler;
    return c;
}

void BearEngine::EventHandler::Update(){
    keystates = SDL_GetKeyboardState(NULL);
    while(SDL_PollEvent(&e)){
        if(e.type == SDL_QUIT){
            this->onQuit();
        }
        for(itKMap i = KeyActionMap.begin(); i != KeyActionMap.end(); i++){
            if(keystates[i->first]){
                i->second();
            }
        }
    }
    if(keystates[SDL_SCANCODE_W]){
	onW();
    }
    if(keystates[SDL_SCANCODE_D]){
	onD();
    }
    if(keystates[SDL_SCANCODE_S]){
	onS();
    }
    if(keystates[SDL_SCANCODE_A]){
	onA();
    }

}
