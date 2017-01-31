#ifndef BEARENGINE_CMAKE_SCENE_H
#define BEARENGINE_CMAKE_SCENE_H

#include <iostream>

#include "Node.h"
#include "../core/Macros.h"
#include "SDL.h"

namespace BearEngine {

    class Scene {

    public:

        virtual ~Scene();

        static std::shared_ptr<BearEngine::Scene> create();

        virtual bool init();

        void loopTree(float dt, std::vector<SDL_Event> & events);

        void addChild(std::shared_ptr<BearEngine::Node>);


    protected:
        Scene();

    private:

        std::shared_ptr<BearEngine::Node> _child;
    };

};

#endif //BEARENGINE_CMAKE_SCENE_H
