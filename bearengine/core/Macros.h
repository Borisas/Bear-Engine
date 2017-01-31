#ifndef BEARENGINE_CMAKE_MACROS_H_H
#define BEARENGINE_CMAKE_MACROS_H_H

//Needed for create Func
#include <memory>
//----

#define CREATE_FUNC(classname) \
            static std::shared_ptr<classname> create(){ \
                return std::make_shared<classname>( classname() ); \
            }


#endif //BEARENGINE_CMAKE_MACROS_H_H
