#include "Texture.h"

using namespace BearEngine;

using std::string;

Texture::Texture(){

}

Texture::Texture(string fn, bool noload){

    setFilename(fn);

    if(noload == false){
        _load();
    }
}

void Texture::draw(float x0, float y0, float x1, float y1){

    glBindTexture(GL_TEXTURE_2D, _txt);

    glColor3f(1,1,1);

    glBegin(GL_QUADS);
    glTexCoord2f(0,0);
    glVertex2f(x0,y0);

    glTexCoord2f(1,0);
    glVertex2f(x1,y0);

    glTexCoord2f(1,1);
    glVertex2f(x1,y1);

    glTexCoord2f(0,1);
    glVertex2f(x0,y1);

    glEnd();

    //UNBIND TEXTURE
    glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::setFilename(std::string fn) {
    _filename = fn;
}

string Texture::getFilename() {
    return _filename;
}

unsigned long Texture::getWidth() {
    return _width;
}
unsigned long Texture::getHeight() {
    return _height;
}

void Texture::_load(){
    if(_filename == "")
        return;

    SDL_Surface* image = IMG_Load(_filename.c_str());
    if(!image) {
        printf("IMG_Load: %s\n", IMG_GetError());
        return;
    }

    GLint nOfColors;
    GLenum texture_format;

    nOfColors = image->format->BytesPerPixel;

    if (nOfColors == 4){
        if (image->format->Rmask == 0x000000ff)
            texture_format = GL_RGBA;
        else
            texture_format = GL_BGRA;
    }
    else if (nOfColors == 3) {
        if (image->format->Rmask == 0x000000ff)
            texture_format = GL_RGB;
        else
            texture_format = GL_BGR;
    }
    else {
        printf("Picture with less than 24-bit color depth detected.\n");
        return;
    };

    // Have OpenGL generate a texture object handle for us
    glGenTextures(1, &_txt);

    // Bind the texture object
    glBindTexture(GL_TEXTURE_2D, _txt);

    // Set the texture's stretching properties
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // Edit the texture object's image data using the information SDL_Surface gives us
    glTexImage2D(GL_TEXTURE_2D, 0, nOfColors, image->w, image->h, 0,
                 texture_format, GL_UNSIGNED_BYTE, image->pixels);

    // Bind the texture to which subsequent calls refer to
    glBindTexture(GL_TEXTURE_2D, _txt);

    _width = image->w;
    _height = image->h;

    SDL_FreeSurface(image);
}

