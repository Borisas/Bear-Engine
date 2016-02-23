#ifndef BE_SPRITE_H
#define BE_SPRITE_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_opengl.h"
#include "../Base/Base.h"
#include "../Base/Structures.h"
#include "Node.h"
#include <iostream>
using namespace std;

namespace BearEngine{
    class Sprite : public Node{

    public:
        Sprite();
        ~Sprite();

        virtual bool initWithFile(const char*);

        virtual void draw();

        bool operator==(int t);
        bool operator!=(int t);
    protected:


    private:
        bool texture_loaded = false;
        GLTexture self_texture;

    };
}

#endif
