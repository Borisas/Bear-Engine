#ifndef WIZARD_H
#define WIZARD_H


#include "SDL2/SDL.h"
#include "SDL2/SDL_opengl.h"
#include "Structures.h"
#include "EventHandler.h"
#include "../ObjVaribles/ViewPoint.h"
#include <iostream>
#include <memory>
#include <string>
#include <functional>
#include <vector>
#include <stack>


using namespace std;

class Wizard{

public:
    static std::shared_ptr< Wizard > getInstance();

    Wizard();
    string GameName = "BEngine";

    bool InitGame();
    void OnQuit();

    void RunGame();
    void SetFPS(int FPS);

    Size GetWindowSize();
    void SetWindowSize(Size _new);

	bool GameLoop = true;

    void SetActionOnEvent(Uint32 EventType, std::function<void ()> action);

    void ReplaceView(ViewPoint* next);
    void PushView(ViewPoint* next);
    void PopView();
private:
    stack<ViewPoint*> Viewer;

    SDL_GLContext Context;
    SDL_Window* GameWindow = NULL;
    Size Window = {1024,768};
    int FPS = 60;
	double period = 1000 / (double)FPS;
    int milliPeriod = (int)period;
    int sleep;

	Uint32 lastTick;
    Uint32 currentTick;

    EventHandler * ev = EventHandler::create();
};

#endif
