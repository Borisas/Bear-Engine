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


#endif //BEARENGINE_CMAKE_MACROS_H_H
