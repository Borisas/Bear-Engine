#ifndef _GAME_H_
#define _GAME_H_

#include "engine/BEngineCore.h"
#include "Entities/Player.h"
#include "Props/Room.h"
#include <iostream>

class Game : public ViewPoint{

public:
    Game();
    ~Game();

    void update();

    void draw();

private:
    Player* objPlayer = nullptr;
    Size vsize = Wizard::getInstance()->GetWindowSize();
    Room* first = nullptr;
};
#endif
