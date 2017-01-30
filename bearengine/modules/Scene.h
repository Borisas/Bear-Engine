#ifndef BEARENGINE_CMAKE_SCENE_H
#define BEARENGINE_CMAKE_SCENE_H

#include <iostream>

#include "Node.h"
#include "SDL.h"

namespace BearEngine {

    class Scene {

    public:

        Scene();

        ~Scene();

        void loopTree(float dt, std::vector<SDL_Event> & events);

        void addChild(BearEngine::Node*);


    private:

        BearEngine::Node* _child;
    };

};

#endif //BEARENGINE_CMAKE_SCENE_H
