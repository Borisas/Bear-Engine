#include "Organizer.h"

using namespace BearEngine;
using std::cout;

Organizer::Organizer(){}
Organizer::~Organizer() {
    if(_gameloop != false && _window != NULL)
        destroyGame();
}

bool Organizer::initGame() {
    if(SDL_Init(SDL_INIT_EVERYTHING) == -1){
        cout << "SDL Error: " << SDL_GetError() << '\n';
        _gameloop = false;
        return false;
    }
    if(IMG_Init(IMG_INIT_PNG) == -1){
        cout << "SDL Error: " << SDL_GetError() << '\n';
        _gameloop = false;
        return false;
    }

    _window = SDL_CreateWindow(
            _gamename.c_str(),
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            _winsize.width,
            _winsize.height,
            SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN
    );

    if(_window == NULL){
        _gameloop = false;
        cout << "SDL Error: " << SDL_GetError() << '\n';
        return false;
    }

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    _context = SDL_GL_CreateContext(_window);

    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glOrtho(0, _winsize.width, _winsize.height, 0, -1,1);

    return true;
}

void Organizer::destroyGame() {
//    while(_scenes.size() > 0)
//        _scenes.pop();
    glDisable(GL_BLEND);
    SDL_DestroyWindow(_window);
    SDL_Quit();
    IMG_Quit();
}

void Organizer::runGame() {

    while(_gameloop){

        SDL_Event e;

        std::vector<SDL_Event> events;

        while(SDL_PollEvent(&e)){
            events.push_back(e);
            if(e.type == SDL_QUIT){
                _gameloop = false;
            }
        }

        glClearColor(0,0,0,1);
        glClear(GL_COLOR_BUFFER_BIT);

        if(_scenes.size() > 0)
            _scenes.top()->loopTree(0.0167f, events);

        SDL_GL_SwapWindow(_window);
    }
}

void Organizer::pushScene(std::shared_ptr<Scene> n){
    _scenes.push(n);
}


Size Organizer::getWindowSize(){
    return _winsize;
}

void Organizer::setWindowSize(Size ws){
    _winsize = ws;
}
void Organizer::setWindowSize(float w, float h){
    _winsize.width = w;
    _winsize.height = h;
}