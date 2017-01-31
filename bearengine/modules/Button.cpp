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

    std::cout << this << '\n';

    evmouse->setOnMouseClick( [this](const SDL_Event& e){
        if(e.motion.x > 10 && e.motion.y > 10) {
            this->_on_click();
        }
    });

    addEventHandler(evmouse);

    return true;
}

void Button::setOnClick(std::function<void()> action) {
    _on_click = action;
}