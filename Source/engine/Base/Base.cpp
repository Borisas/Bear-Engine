#include "Base.h"

GLuint Base::loadImage(const char* file){
    SDL_Surface* image = SDL_LoadBMP(file);
    GLuint texture;
    glGenTextures(1,&texture);
    glBindTexture(GL_TEXTURE_2D,texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, image->format->BytesPerPixel, image->w,image->h, 0, GL_BGR, GL_UNSIGNED_BYTE,image->pixels);
    SDL_FreeSurface(image);
    return texture;
}

void Base::draw(GLuint texture, Square pos){
    glColor3f(1,1,1);
    glBindTexture(GL_TEXTURE_2D, texture);
    glBegin(GL_QUADS);
    glTexCoord2f(0,0);
    glVertex3f(pos.x,pos.y,0);
    glTexCoord2f(1,0);
    glVertex3f(pos.x + pos.width,pos.y,0);
    glTexCoord2f(1,1);
    glVertex3f(pos.x + pos.width,pos.y + pos.height,0);
    glTexCoord2f(0,1);
    glVertex3f(pos.x,pos.y+pos.height,0);
    glEnd();
}

Square Base::cSquare(float x, float y, float width, float height){
    return {x,y,width,height};
}
GLuint Base::SDLSurfaceToTexture(SDL_Surface* surface){
    GLuint texture;
    GLint nOfColors;
    GLenum texture_format;

    // get the number of channels in the SDL surface
    nOfColors = surface->format->BytesPerPixel;

    if (nOfColors == 4)     // contains an alpha channel
    {
        if (surface->format->Rmask == 0x000000ff)
            texture_format = GL_RGBA;
        else
            texture_format = GL_BGRA;
    }
    else if (nOfColors == 3)
    {
        if (surface->format->Rmask == 0x000000ff)
            texture_format = GL_RGB;
        else
            texture_format = GL_BGR;
    }
    else
    {
        printf("Picture with less than 24-bit color depth detected.\n");
        return 0;
    }

    // Have OpenGL generate a texture object handle for us
    glGenTextures(1, &texture);

    // Bind the texture object
    glBindTexture(GL_TEXTURE_2D, texture);

    // Set the texture's stretching properties
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // Edit the texture object's image data using the information SDL_Surface gives us
    glTexImage2D(GL_TEXTURE_2D, 0, nOfColors, surface->w, surface->h, 0,
    texture_format, GL_UNSIGNED_BYTE, surface->pixels);

    // Bind the texture to which subsequent calls refer to
    glBindTexture(GL_TEXTURE_2D, texture);

    return texture;
}
