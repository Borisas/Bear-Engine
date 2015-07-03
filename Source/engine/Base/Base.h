#ifndef BASE_H
#define BASE_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_opengl.h"
#include "SDL2/SDL_image.h"
#include "Structures.h"
#include <stdio.h>

#define FUNCTION_CREATE(__TYPE__) \
            static __TYPE__* create(){ \
             __TYPE__* temp = new __TYPE__; \
             if(temp->init()) \
             return temp; \
             delete temp; \
             return NULL; \
            };

typedef GLuint GLTexture;

class Base{
public:
    static GLuint loadImage(const char* file);
    static void draw(GLuint texture, Square pos);
    static GLuint SDLSurfaceToTexture(SDL_Surface* surface);
    static Square cSquare(float x, float y, float width, float height);
};
#endif
