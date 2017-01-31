#ifndef BEARENGINE_CMAKE_LAYER_H
#define BEARENGINE_CMAKE_LAYER_H

#include "Node.h"
#include "../core/Structures.h"
#include "../core/Macros.h"

namespace BearEngine {

    class Layer : public BearEngine::Node {

    public:

        static std::shared_ptr<BearEngine::Layer> create();
        static std::shared_ptr<BearEngine::Layer> create(BearEngine::Size);


        virtual ~Layer();

        void draw(BearEngine::NodeTransform) override;

    protected:

        Layer();
        Layer(BearEngine::Size);

    };
};


#endif //BEARENGINE_CMAKE_LAYER_H
