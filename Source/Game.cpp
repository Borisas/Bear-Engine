#include "Game.h"

Game::Game(){
    objPlayer = Player::create();
    objPlayer->setPosition(vsize.width/2, vsize.height/2);
}
Game::~Game(){

}

void Game::update(){

}
void Game::draw(){
    if(objPlayer){
	       objPlayer->draw();
    }
}
