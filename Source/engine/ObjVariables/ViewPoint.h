#ifndef BE_VIEWPOINT_H
#define BE_VIEWPOINT_H

#include "../Base/EventHandler.h"
#include <iostream>

class ViewPoint{
public:
    virtual ~ViewPoint(){
    };
    virtual void draw() = 0;
    virtual void update() = 0;
    void onExit(){
        delete _eventHandler;
    };
    
     void handleEvents(){
        _eventHandler->update();
    };
    
protected:
    BearEngine::EventHandler * getEventHandler(){
        if(_eventHandler == nullptr)
            _eventHandler = new BearEngine::EventHandler;
        return _eventHandler;
    };
    
private:
    BearEngine::EventHandler * _eventHandler = nullptr;
};
#endif
