#include "Sprite.h"

using namespace BearEngine;
using std::string;

Sprite::Sprite(){};
Sprite::Sprite(std::string file){
    initWithFile(file);
}

Sprite::~Sprite(){};

void Sprite::test_draw() {
    auto bb = getBoundingBox();

    _text.draw(
            bb.x,
            bb.y,
            bb.x + bb.width,
            bb.y + bb.height
    );
}

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