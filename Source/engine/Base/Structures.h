#ifndef BE_STRUCTURES_H
#define BE_STRUCTURES_H

namespace BearEngine{
    
    enum class MouseButton{
        LEFT,
        RIGHT,
        WHEEL
    };
    enum class EventAction{
        UP,
        DOWN,
        MOVED
    };
    
    struct Square{
        float x;
        float y;
        float width;
        float height;
    };
    struct Size{
        float width;
        float height;
    };
    struct Pos{
        float x;
        float y;
    };
    
    struct MouseEvent{
        MouseButton m;
        Pos mpos;
        EventAction me;
        
        Pos getPosition(){
            return mpos;
        }
        MouseButton getButton(){
            return m;
        }
        EventAction getAction(){
            return me;
        }
    };
}
#endif
