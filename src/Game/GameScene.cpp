#include "GameScene.h"

bool GameScene::init(){
    if(!Layer::initWithSize(windowSize))
        return false;
    setAnchorPoint({0.f,0.f});
    setColor(Color4f(1.0f,1.0f,1.0f,1.0f));

    return true;
}