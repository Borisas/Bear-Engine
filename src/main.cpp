#include <iostream>
#include "SDL.h"

#include "bearengine.h"

#define BE BearEngine

int main(int argc, char** argv) {

    BearEngine::Organizer::getInstance();

    bool loop = BearEngine::Organizer::getInstance().initGame();



    BE::Layer test_layer = BE::Layer(BE::Size(500,500));
    test_layer.setAnchorPoint({0.5f,0.5f});
    test_layer.setPosition({BE::Organizer::getInstance().getWindowSize().width/2,
                           BE::Organizer::getInstance().getWindowSize().height/2});

    test_layer.setColor({0.9f,0.9f,0.9f,1.f});


    BE::Sprite player = BE::Sprite("res/img.png");
    player.setAnchorPoint({0.f,0.f});
    test_layer.addChild(&player);

    BE::Scene top = BE::Scene();

    top.addChild(&test_layer);

    BE::Organizer::getInstance().pushScene(top);


    BE::Organizer::getInstance().runGame();

    return 0;
}