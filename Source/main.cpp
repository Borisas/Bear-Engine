#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <vector>
#include <iostream>
#include <memory>
#include <stdio.h>
#include <stdlib.h>
#include "engine/BEngineCore.h"
#include "Game.h"

USING_NS_BE;

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
    
    Game * startpoint = new Game;
    
    Wizard::getInstance()->ReplaceView(startpoint);

    cout << "umm i should has view" << endl;
    
    Wizard::getInstance()->RunGame();
    Wizard::getInstance()->OnQuit();

    return 0;
}
