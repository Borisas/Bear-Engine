#ifndef BEARENGINE_CMAKE_GAMESCENE_H
#define BEARENGINE_CMAKE_GAMESCENE_H

#include "bearengine.h"

USING_NS_BE;

class GameScene : public Layer{
public:
    static std::shared_ptr<Scene> createScene(){
        auto scene = Scene::create();
        scene->addChild(GameScene::create());
        return scene;
    }

    CREATE_FUNC(GameScene);

    bool init() override;

private:

};


#endif //BEARENGINE_CMAKE_GAMESCENE_H
