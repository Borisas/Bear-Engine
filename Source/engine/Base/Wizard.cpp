#include "Wizard.h"
#pragma mark init

std::shared_ptr< Wizard > sharedInstance;

std::shared_ptr< Wizard > Wizard::getInstance() {
    if (sharedInstance){
        return sharedInstance;
    }

    sharedInstance = std::make_shared< Wizard >();
    return sharedInstance;
}

Wizard::Wizard(){

}

bool Wizard::InitGame(){
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

	if(GameWindow == NULL)
    {
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
    cout << "A" << endl;
	glOrtho(0,Window.width, Window.height,0,-1,1);

    //BASE EVENTS:


    this->ev->onQuit = [&](){
        this->GameLoop = false;
    };

    //====

    return true;
}
void Wizard::OnQuit(){
    glDisable(GL_BLEND);
	SDL_DestroyWindow(GameWindow);
    SDL_Quit();
    IMG_Quit();
    //printf("Quit");
    cout << "Quit" << endl;
}
void Wizard::RunGame(){
    while(GameLoop){
		lastTick = SDL_GetTicks();

        glClearColor(0,0,0,1);
        glClear(GL_COLOR_BUFFER_BIT);

        ev->Update();
        if(Viewer.size() > 0){
            Viewer.top()->update();
            Viewer.top()->draw();
        }


        currentTick = SDL_GetTicks();
        sleep = milliPeriod - (currentTick - lastTick);
        if(sleep < 0)  sleep = 0;
        SDL_Delay(sleep);
		SDL_GL_SwapWindow(GameWindow);

    }
}
void Wizard::SetFPS(int FPS){
    this->FPS = FPS;
    double period = 1000 / (double)FPS;
    int milliPeriod = (int)period;
}
Size Wizard::GetWindowSize(){
    return Window;
}
void Wizard::SetWindowSize(Size _new){
    Window = _new;
}
void Wizard::SetActionOnEvent(Uint32 EventType, std::function<void ()> action){
    ev->KeyActionMap[EventType] = action;
}
EventHandler* Wizard::GetEventHandler(){
    return ev;
}
void Wizard::ReplaceView(ViewPoint * next){
    if(Viewer.size() > 0)
        Viewer.pop();
    Viewer.push(next);
}
void Wizard::PushView(ViewPoint * next){
    Viewer.push(next);
}
void Wizard::PopView(){
    Viewer.pop();
}
