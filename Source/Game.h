#ifndef _GAME_H_
#define _GAME_H_

#include "engine/BEngineCore.h"
#include <iostream>

class Game : public ViewPoint{

public:
    Game();
    ~Game();

    void update();

    void draw();

private:
    Sprite* Player;
    Size vsize = Wizard::getInstance()->GetWindowSize();

};
#endif
