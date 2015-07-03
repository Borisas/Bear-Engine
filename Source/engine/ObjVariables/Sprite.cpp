#include "Sprite.h"

Sprite::Sprite(){
}
Sprite::~Sprite(){

}
Sprite* Sprite::create(const char* file){
    auto r = new Sprite;
    if(r->init(file)){

		return r;
    }
    delete r;
    return nullptr;
}
void Sprite::draw(){
    glColor3f(1,1,1);
    glBindTexture(GL_TEXTURE_2D, self_texture);
    glBegin(GL_QUADS);
    glTexCoord2f(0,0);
    glVertex3f(self.x - (offset.x * self.width), self.y - (offset.y * self.height),0);
    glTexCoord2f(1,0);
    glVertex3f((self.x + self.width) - (offset.x * self.width), self.y - (offset.y * self.height),0);
    glTexCoord2f(1,1);
    glVertex3f((self.x + self.width) - (offset.x * self.width), (self.y + self.height) - (offset.y * self.height),0);
    glTexCoord2f(0,1);
    glVertex3f(self.x - (offset.x * self.width), (self.y+self.height) - (offset.y * self.height),0);
    glEnd();
}
bool Sprite::init(const char* file){
  SDL_Surface* image;
  image = IMG_Load(file);
  if(image){
    GLenum texture_format;
    glGenTextures(1,&self_texture);
    glBindTexture(GL_TEXTURE_2D,self_texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    GLint nOfColors = image->format->BytesPerPixel;
    if (nOfColors == 4)     // contains an alpha channel
    {
        if (image->format->Rmask == 0x000000ff)
            texture_format = GL_RGBA;
        else
            texture_format = GL_BGRA;
    }
    else if (nOfColors == 3)
    {
        if (image->format->Rmask == 0x000000ff)
            texture_format = GL_RGB;
        else
            texture_format = GL_BGR;
    }
    glTexImage2D(GL_TEXTURE_2D, 0, image->format->BytesPerPixel, image->w,image->h, 0, texture_format, GL_UNSIGNED_BYTE,image->pixels);
    self.x = 0;
    self.y = 0;
    self.width = image->w;
    self.height = image->h;
    SDL_FreeSurface(image);
    return true;
  }
  cout << "IMG_Load error: " << IMG_GetError() << endl;
  return false;
}
