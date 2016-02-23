#include "Wizard.h"
#pragma mark init

std::shared_ptr< BearEngine::Wizard > sharedInstance;

std::shared_ptr< BearEngine::Wizard > BearEngine::Wizard::getInstance() {
    if (sharedInstance){
        return sharedInstance;
    }

    sharedInstance = std::make_shared< BearEngine::Wizard >();
    return sharedInstance;
}

BearEngine::Wizard::Wizard(){

}

bool BearEngine::Wizard::InitGame(){
    if(SDL_Init( SDL_INIT_EVERYTHING ) == -1){
        cout << "SDL_ERROR: " << SDL_GetError() << endl;
        GameLoop = false;
        return false;
    }
    if(IMG_Init(IMG_INIT_PNG) == -1){
        cout << "SDL_ERROR: " << SDL_GetError() << endl;
        GameLoop = false;
        return false;
    }
    cout << "Iniatialising Stage:1" << endl;
    GameWindow = SDL_CreateWindow(GameName.c_str(), SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED, Window.width, Window.height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

    if(GameWindow == NULL){
        GameLoop=false;
        cout << "SDL_ERROR: " << SDL_GetError() << endl;
        return false;
    }
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);
    Context = SDL_GL_CreateContext(GameWindow);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    cout << "Iniatialising Stage:2" << endl;
    glOrtho(0,Window.width, Window.height,0,-1,1);

    //BASE EVENTS:


    this->ev->onQuit = [&](){
        this->GameLoop = false;
    };

    //====

    return true;
}
void BearEngine::Wizard::OnQuit(){
    glDisable(GL_BLEND);
    SDL_DestroyWindow(GameWindow);
    SDL_Quit();
    IMG_Quit();
    //printf("Quit");
    cout << "Quit" << endl;
}
void BearEngine::Wizard::RunGame(){
    int countedFrames = 0;
    fpsTimer.start();
    while(GameLoop){
        capTimer.start();
        glClearColor(0,0,0,1);
        glClear(GL_COLOR_BUFFER_BIT);

        ev->Update();

        float avgFPS = countedFrames / ( fpsTimer.getTicks() / 1000.f );
        if( avgFPS > 2000000 ){
            avgFPS = 0;
        }
        if(Viewer.size() > 0){
            Viewer.top()->update();
            Viewer.top()->draw();
        }
        // cout << "Update: " << avgFPS << endl;
        ++countedFrames;
        int frameTicks = capTimer.getTicks();
        this->dt = 1/avgFPS;
        if( frameTicks < SCREEN_TICK_PER_FRAME ){
            SDL_Delay( SCREEN_TICK_PER_FRAME - frameTicks );
        }
        SDL_GL_SwapWindow(GameWindow);
    }
}
float BearEngine::Wizard::getFPSMultiplier(){
    return (dt / (1/60.f));
}
float BearEngine::Wizard::getDelayTime(){
    return dt;
}
float BearEngine::Wizard::getDefaultDelayTime(){
    return SCREEN_TICK_PER_FRAME;
}
void BearEngine::Wizard::SetFPS(int FPS){
    this->FPS = FPS;
    SCREEN_TICK_PER_FRAME = 1000 / FPS;
}
BearEngine::Size BearEngine::Wizard::GetWindowSize(){
    return Window;
}
void BearEngine::Wizard::SetWindowSize(Size _new){
    Window = _new;
}
void BearEngine::Wizard::SetActionOnEvent(Uint32 EventType, std::function<void ()> action){
    ev->KeyActionMap[EventType] = action;
}
BearEngine::EventHandler* BearEngine::Wizard::GetEventHandler(){
    return ev;
}
void BearEngine::Wizard::ReplaceView(ViewPoint * next){
    if(Viewer.size() > 0)
        Viewer.pop();
    Viewer.push(next);
}
void BearEngine::Wizard::PushView(ViewPoint * next){
    Viewer.push(next);
}
void BearEngine::Wizard::PopView(){
    Viewer.pop();
}
