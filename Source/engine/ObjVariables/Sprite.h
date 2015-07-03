#ifndef _SPRITE_H_
#define _SPRITE_H_

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_opengl.h"
#include "../Base/Base.h"
#include "../Base/Structures.h"

class Sprite{

public:
    Sprite(const char* image);
    ~Sprite();
    virtual void draw();
    Square getSquare();
protected:
    virtual void init(const char* image);

private:
    GLTexture self_texture;
    Square self;

};

#endif
