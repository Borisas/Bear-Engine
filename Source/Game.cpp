#include "Game.h"

Game::Game(){
    objPlayer.init();
    objPlayer.setPosition(vsize.width/2, vsize.height/2);
    
    getEventHandler()->addEvent(SDL_SCANCODE_W, [&](){
        objPlayer.move(1);
    });
    getEventHandler()->addEvent(SDL_SCANCODE_D, [&](){
        objPlayer.move(2);
    });
    getEventHandler()->addEvent(SDL_SCANCODE_S, [&](){
        objPlayer.move(3);
    });
    getEventHandler()->addEvent(SDL_SCANCODE_A, [&](){
        objPlayer.move(4);
    });
    
}
Game::~Game(){
    ViewPoint::onExit();
}
void Game::update(){
}
void Game::draw(){
    objPlayer.draw();
}
