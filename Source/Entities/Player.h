#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "../engine/BEngineCore.h"

class Player : public Sprite{
public:
    static Player* create(){
        auto r = new Player;
        if(r->init("Assets/player.png")){
            return r;
        }
        delete r;
        return nullptr;
    }
    void move(int direction){
	switch(direction){
	    case 1:
		this->setPosition(getPosition().x, getPosition().y - movementSpeed);
		break;
	    case 2:
		this->setPosition(getPosition().x + movementSpeed, getPosition().y);	
		break;
	    case 3:
		this->setPosition(getPosition().x, getPosition().y + movementSpeed);
		break;
	    case 4:
		this->setPosition(getPosition().x - movementSpeed, getPosition().y);
		break;
	};
    }

private:

    float movementSpeed = 2.5f;

};

#endif
