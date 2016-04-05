#include "ActionLocket.h"

BearEngine::ActionLocket::ActionLocket(){

}
BearEngine::ActionLocket::~ActionLocket(){

}

std::unique_ptr<BearEngine::ActionLocket> BearEngine::ActionLocket::create(std::string actioType){
    std::unique_ptr<ActionLocket> action(new ActionLocket);
}
