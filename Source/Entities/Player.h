#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "../engine/BEngineCore.h"

class Player : public Sprite{
public:
    static Player* create(){
        auto r = new Player;
        if(r->init("assets/player.png")){
            return r;
        }
        delete r;
        return nullptr;
    }


private:


};

#endif
