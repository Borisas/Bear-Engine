#ifndef BEARENGINE_CMAKE_LAYER_H
#define BEARENGINE_CMAKE_LAYER_H

#include "Node.h"
#include "../core/Structures.h"

namespace BearEngine {

    class Layer : public BearEngine::Node {

    public:

        Layer();
        Layer(BearEngine::Size);

        ~Layer();

        void draw(BearEngine::NodeTransform) override;

    private:


    };
};


#endif //BEARENGINE_CMAKE_LAYER_H
