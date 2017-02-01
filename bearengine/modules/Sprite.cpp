#include "Sprite.h"

using namespace BearEngine;
using std::string;

std::shared_ptr<BearEngine::Sprite> Sprite::create(){
    auto ptr = std::make_shared<Sprite>(Sprite());
    ptr->init();
    return ptr;
}

std::shared_ptr<BearEngine::Sprite> Sprite::create(std::string file){
    auto ptr = std::make_shared<Sprite>(Sprite());
    ptr->initWithFile(file);
    return ptr;
}

bool Sprite::init(){
    return true;
}

bool Sprite::initWithFile(std::string file) {
    _text = Texture(file);
    setContentSize(Size(_text.getWidth(), _text.getHeight()));
    return true;
}


Sprite::Sprite(){};

Sprite::~Sprite(){};

void Sprite::draw(BearEngine::NodeTransform transform){

//    std::cout << "DRAW: {" << transform.position.x - transform.anchorPoint.x * (transform.contentSize.width * transform.scale.x) << ", "
//    << transform.position.y - transform.anchorPoint.y * (transform.contentSize.height * transform.scale.y) << ","
//    << transform.position.x + (1-transform.anchorPoint.x) * (transform.contentSize.width * transform.scale.x) << ","
//    << transform.position.y + (1-transform.anchorPoint.y) * (transform.contentSize.height * transform.scale.y) << "}"
//                                                                                                        << '\n';

    _text.draw(
            transform.position.x - transform.anchorPoint.x * (transform.contentSize.width * transform.scale.x),
            transform.position.y - transform.anchorPoint.y * (transform.contentSize.height * transform.scale.y),
            transform.position.x + (1-transform.anchorPoint.x) * (transform.contentSize.width * transform.scale.x),
            transform.position.y + (1-transform.anchorPoint.y) * (transform.contentSize.height * transform.scale.y)
    );

}

