#include <iostream>

#include "SDL.h"

#include "bearengine.h"

#define BE BearEngine

int main(int argc, char** argv) {

    BearEngine::Organizer::getInstance();

    bool loop = BearEngine::Organizer::getInstance().initGame();



    auto test_layer = BE::Layer::create(BE::Size(500,500));
    test_layer->setAnchorPoint({0.5f,0.5f});
    test_layer->setPosition({BE::Organizer::getInstance().getWindowSize().width/2,
                           BE::Organizer::getInstance().getWindowSize().height/2});

    test_layer->setColor({0.9f,0.9f,0.9f,1.f});

    auto ev = BE::MouseEventHandler::create();
    ev->setOnMouseClick([&](const SDL_Event & e){
        std::cout << "MOUSE CLICK" << '\n';
    });
    test_layer->addEventHandler(ev);

    auto button = BE::Button::create("res/inner/img_sec.png");
    button->setOnClick([](){
       std::cout << "LOL\n";
    });

    std::cout << button << '\n';

    test_layer->addChild(button);

    auto player = BE::Sprite::create("res/img.png");
    player->setAnchorPoint({0.5f,0.5f});
    player->setPosition({
            test_layer->getContentSize().width/2,
            test_layer->getContentSize().height/2
                       });
    test_layer->addChild(player);

    auto top = BE::Scene::create();
    top->addChild(test_layer);
    BE::Organizer::getInstance().pushScene(top);


    BE::Organizer::getInstance().runGame();
    return 0;
}