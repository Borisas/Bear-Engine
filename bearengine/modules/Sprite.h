#ifndef BEARENGINE_CMAKE_SPRITE_H
#define BEARENGINE_CMAKE_SPRITE_H

#include <string>

#include "bearengine.h"

namespace BearEngine {

    class Sprite : public BearEngine::Node {

    public:
        Sprite();
        Sprite(std::string file);
        ~Sprite();

        //TODO: REMOVE
        void test_draw();
        //---

        virtual void draw(BearEngine::NodeTransform) override;
        virtual void update(float dt) override;

    private:

        BearEngine::Texture _text;

    protected:

        bool initWithFile(std::string file);

    };
};

#endif //BEARENGINE_CMAKE_SPRITE_H
