#ifndef BE_BASE_H
#define BE_BASE_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_opengl.h"
#include "SDL2/SDL_image.h"
#include "Structures.h"
#include <stdio.h>



typedef GLuint GLTexture;
namespace BearEngine{
    class Base{
    public:
        static GLuint loadImage(const char* file);
        static void draw(GLuint texture, Square pos);
        static GLuint SDLSurfaceToTexture(SDL_Surface* surface);
        static Square cSquare(float x, float y, float width, float height);
    };
}
#endif
