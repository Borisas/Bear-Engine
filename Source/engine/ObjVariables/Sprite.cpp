#include "Sprite.h"

Sprite::Sprite(const char* image){
    this->init(image);
}
Sprite::~Sprite(){

}

void Sprite::draw(){
    Base::draw(self_texture, self);
}
void Sprite::init(const char* image){
    self_texture = Base::loadImage(image);
    self.x = 0;
    self.y = 0;
}



Square Sprite::getSquare(){
    return self;
}
