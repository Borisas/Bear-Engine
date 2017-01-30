#ifndef BEARENGINE_CMAKE_TEXTURE_H
#define BEARENGINE_CMAKE_TEXTURE_H

#include <string>
#include <iostream>

#include "SDL.h"
#include "SDL_opengl.h"
#include "SDL_image.h"


namespace BearEngine {

    class Texture {
    public:
        Texture();
        Texture(std::string fn, bool noload = false);

        void draw(float x0, float y0, float x1, float y1);

        void setFilename(std::string fn);

        std::string getFilename();
        unsigned long getWidth();
        unsigned long getHeight();

    private:

        void _load();

        std::string _filename;
        GLuint _txt;
        unsigned long _width;
        unsigned long _height;
    };
}


#endif //BEARENGINE_CMAKE_TEXTURE_H
