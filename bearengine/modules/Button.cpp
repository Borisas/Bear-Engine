#include "Button.h"

using namespace BearEngine;


std::shared_ptr<BearEngine::Button> Button::create(){
    return std::make_shared<Button>(Button());
}
std::shared_ptr<BearEngine::Button> Button::create(std::string file){
//    return std::make_shared<Button>( Button(file) );
    auto ptr = std::make_shared<Button>( Button() );
    ptr->init(file);
    return ptr;
}

Button::Button(){}

bool Button::init(std::string file){
    initWithFile(file);

    test = 4;

    auto evmouse = MouseEventHandler::create();

    std::cout << this << '\n';

    evmouse->setOnMouseClick( [this](const SDL_Event& e){
        if(e.motion.x > 10 && e.motion.y > 10) {
            this->_on_click();
        }
    });

    evmouse->test_var = 12;

    addEventHandler(evmouse);
}

void Button::setOnClick(std::function<void()> action) {
    _on_click = action;
}