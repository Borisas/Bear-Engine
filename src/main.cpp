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

    test_layer->setColor({0.6f,0.3f,0.3f,1.f});

    auto lbl = BE::Label::createWithTTF("TEST TEXT", "res/arial.ttf", 30);
    lbl->setPosition({
            test_layer->getContentSize().width/2,
            test_layer->getContentSize().height/2
                     });
    test_layer->addChild(lbl);

    auto sprite = BE::Sprite::create("res/img.png");
    sprite->setPosition({
            test_layer->getContentSize().width,
            test_layer->getContentSize().height
                        });
    sprite->setAnchorPoint({1.f,1.f});
    test_layer->addChild(sprite);

    auto button = BE::Button::create("res/inner/img_sec.png");
    button->setOnClick([](){
       std::cout << "LOL\n";
    });
    test_layer->addChild(button);

    auto top = BE::Scene::create();
    top->addChild(test_layer);
    BE::Organizer::getInstance().pushScene(top);


    BE::Organizer::getInstance().runGame();
    return 0;
}