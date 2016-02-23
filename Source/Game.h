#ifndef _GAME_H_
#define _GAME_H_

#include "engine/BEngineCore.h"
#include "Entities/Player.h"
#include <iostream>

USING_NS_BE;

class Game : public ViewPoint{

public:
    Game();
    ~Game();

    void update();

    void draw();

private:
    Player objPlayer;
    Size vsize = Wizard::getInstance()->GetWindowSize();
    // Room* first = nullptr;
};
#endif
