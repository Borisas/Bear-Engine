#include "Button.h"

using namespace BearEngine;


std::shared_ptr<BearEngine::Button> Button::create(){
    return std::make_shared<Button>(Button());
}
std::shared_ptr<BearEngine::Button> Button::create(std::string file){
    auto ptr = std::make_shared<Button>( Button() );
    ptr->initWithFile(file);
    return ptr;
}

Button::Button(){}

bool Button::init(){
    if(!Sprite::init())
        return false;

    return true;
}

bool Button::initWithFile(std::string file){

    if(!Sprite::initWithFile(file))
        return false;

    auto evmouse = MouseEventHandler::create();

    evmouse->setOnMouseClick( [this](const SDL_Event& e, BearEngine::NodeTransform transform){

        if(     e.motion.x - transform.position.x > (this->getAnchorPoint().x -1) * transform.contentSize.width * transform.scale.x &&
                e.motion.x - transform.position.x < this->getAnchorPoint().x  * transform.contentSize.width * transform.scale.x &&
                e.motion.y - transform.position.y > (this->getAnchorPoint().y -1) * transform.contentSize.height * transform.scale.y &&
                e.motion.y - transform.position.y < this->getAnchorPoint().y * transform.contentSize.height * transform.scale.y
                ) {
            this->_on_click();
        }
    });

    addEventHandler(evmouse);

    return true;
}

void Button::setOnClick(std::function<void()> action) {
    _on_click = action;
}