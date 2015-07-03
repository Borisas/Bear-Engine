#include "SDL2/SDL.h"
#include "SDL2/SDL_opengl.h"
#include <vector>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "engine/BEngineCore.h"
#include "Game.h"

#define Wiz Wizard::getInstance()

int main( int argc, char* args[] )
{
    Wizard::getInstance();
    Wiz->GameName = "My Game";
    Wiz->SetFPS(60);
    Wiz->SetWindowSize({800,600});
    if(!Wizard::getInstance()->InitGame()){
        Wizard::getInstance()->OnQuit();
        return 0;
    }

    Wizard::getInstance()->SetActionOnEvent(SDL_SCANCODE_W, [&](){
                                            std::cout << "pressed W." << std::endl;});
    Wiz->SetActionOnEvent(SDL_SCANCODE_SPACE, [&](){ std::cout << "pressed spacebar." << std::endl;});

    Wizard::getInstance()->ReplaceView(new Game);

    Wizard::getInstance()->RunGame();
    Wizard::getInstance()->OnQuit();

    return 0;
}
