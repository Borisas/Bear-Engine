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

        virtual ~Sprite();

        virtual bool init() override;
        virtual bool initWithFile(std::string file);

        static std::shared_ptr<BearEngine::Sprite> create();
        static std::shared_ptr<BearEngine::Sprite> create(std::string file);



        virtual void draw(BearEngine::NodeTransform) override;

    private:

        BearEngine::Texture _text;

    protected:

        Sprite();

    };
};

#endif //BEARENGINE_CMAKE_SPRITE_H
