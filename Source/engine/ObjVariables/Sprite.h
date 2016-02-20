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

    virtual bool initWithFile(const char*);

    virtual void draw();

    bool operator==(int t);
    bool operator!=(int t);
protected:


private:
    bool texture_loaded = false;
    GLTexture self_texture;

};

#endif
