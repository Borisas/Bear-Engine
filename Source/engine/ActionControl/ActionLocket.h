#ifndef BE_ACTION_LOCKET_H
#define BE_ACTION_LOCKET_H

#include "../ObjVariables/Node.h"
#include <string>

namespace BearEngine{

    class ActionLocket{
    public:
        ActionLocket();
        ~ActionLocket();

        static std::unique_ptr<ActionLocket> create(std::string);

        virtual void act(){};

    private:

        Node actor;

    };
}


#endif
