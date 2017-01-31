#include "Button.h"

using namespace BearEngine;


std::shared_ptr<BearEngine::Button> Button::create(){
    return std::make_shared<Button>(Button());
}
std::shared_ptr<BearEngine::Button> Button::create(std::string file){
    return std::make_shared<Button>( Button(file) );
}

Button::Button(){}

Button::Button(std::string file){
    initWithFile(file);

    auto evmouse = MouseEventHandler::create();

    evmouse->setOnMouseClick([&](const SDL_Event& e){
        if(e.motion.x > 10 && e.motion.y > 10) {
            _on_click();
        }
    });

    evmouse->test_var = 12;

    addEventHandler(evmouse);
}

void Button::setOnClick(std::function<void()> action) {
    _on_click = action;
}