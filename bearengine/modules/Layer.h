#ifndef BEARENGINE_CMAKE_LAYER_H
#define BEARENGINE_CMAKE_LAYER_H

#include "Node.h"
#include "../core/Structures.h"
#include "../core/Macros.h"

namespace BearEngine {

    class Layer : public BearEngine::Node {

    public:

        virtual ~Layer();

        virtual bool init() override;
        virtual bool initWithSize(BearEngine::Size);

        static std::shared_ptr<BearEngine::Layer> create();
        static std::shared_ptr<BearEngine::Layer> create(BearEngine::Size);

        void draw(BearEngine::NodeTransform) override;

    protected:

        Layer();

    };
};


#endif //BEARENGINE_CMAKE_LAYER_H
