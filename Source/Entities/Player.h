#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "../engine/BEngineCore.h"
#include <iostream>
using namespace std;

USING_NS_BE;

class Player : public BearEngine::Sprite{
public:
    Player();
    ~Player();
    void move(int direction);

    bool init() override;

private:
    bool autoremove = false;
    float movementSpeed = 2.5f;

};

#endif
