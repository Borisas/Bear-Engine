#ifndef BE_VIEWPOINT_H
#define BE_VIEWPOINT_H

class ViewPoint{
public:
    virtual void draw() = 0;
    virtual void update() = 0;
};
#endif
