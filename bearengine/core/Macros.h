#ifndef BEARENGINE_CMAKE_MACROS_H_H
#define BEARENGINE_CMAKE_MACROS_H_H

//Needed for create Func
#include <memory>
//----

#define CREATE_FUNC(classname) \
            static std::shared_ptr<classname> create(){ \
                auto ptr = std::make_shared<classname>(classname()); \
                ptr->init(); \
                return ptr; \
            }

#define USING_NS_BE using namespace BearEngine

#define windowSize BearEngine::Organizer::getInstance().getWindowSize()

#define BE_VAR(var) std::shared_ptr<BearEngine::var>

#define catchError(var) \
	if(var == NULL){ \
		printf("SDL Error: %s", SDL_GetError()); \
	}

#endif //BEARENGINE_CMAKE_MACROS_H_H
