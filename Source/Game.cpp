#include "Game.h"

Game::Game(){
    Player = Sprite::create("assets/player.png");
    Player->setPosition(vsize.width/2, vsize.height/2);
}
Game::~Game(){

}

void Game::update(){

}
void Game::draw(){
    if(Player){
	       Player->draw();
    }
}
