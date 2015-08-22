#ifndef _SPRITE_H_
#define _SPRITE_H_

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_opengl.h"
#include "../Base/Base.h"
#include "../Base/Structures.h"
#include "ObjBase.h"
#include <iostream>
using namespace std;

class Sprite : public interface{

public:
    Sprite();
    ~Sprite();
    static Sprite* create(const char* file);
    virtual void draw();
protected:
    virtual bool init(const char*);

private:
    GLTexture self_texture;

};

#endif
