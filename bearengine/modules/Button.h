#ifndef BEARENGINE_CMAKE_BUTTON_H
#define BEARENGINE_CMAKE_BUTTON_H

#include <string>
#include <functional>

#include "Sprite.h"
#include "../core/EventHandlers.h"

namespace BearEngine {

    class Button : public BearEngine::Sprite {

    public:

        virtual ~Button(){};

        virtual bool init() override;
        virtual bool initWithFile(std::string file) override;

        static std::shared_ptr<BearEngine::Button> create();
        static std::shared_ptr<BearEngine::Button> create(std::string file);

        void setOnClick(std::function<void()>);

    private:

        std::function<void()> _on_click = [](){};

    protected:

        Button();
    };
};


#endif //BEARENGINE_CMAKE_BUTTON_H
