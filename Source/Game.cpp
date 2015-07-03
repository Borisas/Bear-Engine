#include "Game.h"

Game::Game(){
    objPlayer = Player::create();
    objPlayer->setPosition(vsize.width/2, vsize.height/2);

    first = Room::create(10,10);

    Wizard::getInstance()->GetEventHandler()->onW = [&](){ objPlayer->move(1); };
    Wizard::getInstance()->GetEventHandler()->onD = [&](){ objPlayer->move(2); };
    Wizard::getInstance()->GetEventHandler()->onS = [&](){ objPlayer->move(3); };
    Wizard::getInstance()->GetEventHandler()->onA = [&](){ objPlayer->move(4); };
}
Game::~Game(){
    if(objPlayer)
	delete objPlayer;
    if(first)
	delete first;
}

void Game::update(){

}
void Game::draw(){
    if(objPlayer){
	       objPlayer->draw();
    }
}
