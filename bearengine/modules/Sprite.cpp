#include "Sprite.h"

using namespace BearEngine;
using std::string;

std::shared_ptr<BearEngine::Sprite> Sprite::create(){
    return std::make_shared<Sprite>(Sprite());
}
std::shared_ptr<BearEngine::Sprite> Sprite::create(std::string file){
    return std::make_shared<Sprite>(Sprite(file));
}

Sprite::Sprite(){};
Sprite::Sprite(std::string file){
    initWithFile(file);
}

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
void Sprite::update(float dt){

}

bool Sprite::initWithFile(std::string file) {
    _text = Texture(file);
    setContentSize(Size(_text.getWidth(), _text.getHeight()));
}