#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "../engine/BEngineCore.h"
#include <iostream>
using namespace std;

class Player : public Sprite{
public:
    Player();
    ~Player();
    void move(int direction);

private:
    bool autoremove = false;
    float movementSpeed = 2.5f;

};

#endif
