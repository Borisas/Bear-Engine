#include "Game.h"

Game::Game(){
    objPlayer.init();
    objPlayer.setPosition(vsize.width/2, vsize.height/2);

    Wizard::getInstance()->GetEventHandler()->onW = [&](){ objPlayer.move(1); };
    Wizard::getInstance()->GetEventHandler()->onD = [&](){ objPlayer.move(2); };
    Wizard::getInstance()->GetEventHandler()->onS = [&](){ objPlayer.move(3); };
    Wizard::getInstance()->GetEventHandler()->onA = [&](){ objPlayer.move(4); };
}
Game::~Game(){
}

void Game::update(){

}
void Game::draw(){
    objPlayer.draw();
}
