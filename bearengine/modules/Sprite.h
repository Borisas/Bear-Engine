#ifndef BEARENGINE_CMAKE_SPRITE_H
#define BEARENGINE_CMAKE_SPRITE_H

#include <string>

#include "../core/Structures.h"
#include "Node.h"
#include "Texture.h"
#include "../core/Macros.h"

namespace BearEngine {

    class Sprite : public BearEngine::Node {

    public:

        virtual bool init() override;
        virtual bool initWithFile(std::string file);

        static std::shared_ptr<BearEngine::Sprite> create();
        static std::shared_ptr<BearEngine::Sprite> create(std::string file);

        virtual ~Sprite();


        virtual void draw(BearEngine::NodeTransform) override;
        virtual void update(float dt) override;

    private:

        BearEngine::Texture _text;

    protected:

        Sprite();
        Sprite(std::string file);

    };
};

#endif //BEARENGINE_CMAKE_SPRITE_H
