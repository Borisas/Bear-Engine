#ifndef BEARENGINE_CMAKE_ORGANIZER_H
#define BEARENGINE_CMAKE_ORGANIZER_H

#include <string>
#include <iostream>
#include <vector>
#include <stack>
#include <memory>
#include <cmath>

#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_opengl.h"
#include "SDL_image.h"

#include "Structures.h"
#include "../modules/Scene.h"

namespace BearEngine {

    class Organizer {
    public:

        // ORGANIZER Singleton
        static Organizer &getInstance() {
            static Organizer instance;
            return instance;
        }

        Organizer(Organizer const &) = delete;

        void operator=(Organizer const &)  = delete;
        // ===

        Organizer();

        ~Organizer();

        bool initGame();
        void destroyGame();
        void stopGame();

        void runGame();

        void pushScene(std::shared_ptr<Scene>);
        void replaceScene(std::shared_ptr<Scene>);

        BearEngine::Size getWindowSize();

        void setWindowSize(BearEngine::Size);
        void setWindowSize(float w, float h);

        //TODO:REMOVE
        SDL_Window* getWindow(){
            return _window;
        };
        //---

    private:

        bool _gameloop = true;

        std::string _gamename = "Game";

        SDL_GLContext _context;
        SDL_Window *_window = NULL;

        BearEngine::Size _winsize = {1024, 768};

        std::stack< std::shared_ptr<BearEngine::Scene> > _scenes;

    };
};

#endif //BEARENGINE_CMAKE_ORGANIZER_H
