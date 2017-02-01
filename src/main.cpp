#include <iostream>

#include "bearengine.h"

#include "Game/GameScene.h"

#define BE BearEngine

int main(int argc, char** argv) {

    BearEngine::Organizer::getInstance();

    bool ok = BearEngine::Organizer::getInstance().initGame();

    if(ok) {

        BE::Organizer::getInstance().pushScene(GameScene::createScene());

        BE::Organizer::getInstance().runGame();

    }

    return 0;
}