#ifndef WIZARD_H
#define WIZARD_H


#include "SDL2/SDL.h"
#include "SDL2/SDL_opengl.h"
#include "SDL2/SDL_image.h"
#include "Structures.h"
#include "EventHandler.h"
#include "../ObjVariables/ViewPoint.h"
#include "Timer.h"
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

  EventHandler* GetEventHandler();

private:
    stack<ViewPoint*> Viewer;

    SDL_GLContext Context;
    SDL_Window* GameWindow = NULL;
    Size Window = {1024,768};
    int FPS = 62;
    int SCREEN_TICK_PER_FRAME = 1000 / FPS;
    LTimer fpsTimer;
    LTimer capTimer;


    EventHandler * ev = EventHandler::create();
};

#endif
