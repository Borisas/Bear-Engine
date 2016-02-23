#ifndef BE_NODE_H
#define BE_NODE_H

#include "../Base/Structures.h"
#include <functional>

namespace BearEngine{
    class Node{
    public:
        virtual void setPosition(float x, float y){
            this->self.x = x;
            this->self.y = y;
        };
        virtual Pos getPosition(){
    	       return {self.x, self.y};
        };
        virtual void setScale(float sx, float sy){
            this->scaleX = sx;
            this->scaleY = sy;
        };
        virtual void setScale(float scale){
            this->scaleX = scale;
            this->scaleY = scale;
        };
        virtual Square getSquare(){
            return self;
        };
        virtual void setAnchorPoint(float x, float y){
            offset.x = x;
            offset.y = y;
        };
        virtual void draw(){};
        virtual void update(){onUpdate();};
        virtual bool init(){return false;};
    protected:
        std::function<void()> onUpdate = [&](){};

        Square self;
        Pos offset = {0.5,0.5};
        float scaleX = 1;
        float scaleY = 1;
    };
}

#endif
