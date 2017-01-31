#include "Layer.h"

using namespace BearEngine;


std::shared_ptr<BearEngine::Layer> Layer::create(){
    auto ptr = std::make_shared<Layer>(Layer());
    ptr->init();
    return ptr;
}
std::shared_ptr<BearEngine::Layer> Layer::create(BearEngine::Size container_size){
    auto ptr = std::make_shared<Layer>(Layer());
    ptr->initWithSize(container_size);
    return ptr;
}

Layer::Layer(){}


bool Layer::init(){
    if(!Node::init())
        return false;

    return true;
};
bool Layer::initWithSize(Size contsz){

    if(!Node::init())
        return false;

    setContentSize(contsz);
    return true;
}


Layer::~Layer(){}


void Layer::draw(BearEngine::NodeTransform transform) {


    float x0 = transform.position.x - transform.anchorPoint.x * (transform.contentSize.width * transform.scale.x);
    float y0 = transform.position.y - transform.anchorPoint.y * (transform.contentSize.height * transform.scale.y);
    float x1 = transform.position.x + (1-transform.anchorPoint.x) * (transform.contentSize.width * transform.scale.x);
    float y1 = transform.position.y + (1-transform.anchorPoint.y) * (transform.contentSize.height * transform.scale.y);

    glColor3f(getColor().r, getColor().g, getColor().b);

    //FAILSAFE UNBIND TEXTURE
    glBindTexture(GL_TEXTURE_2D, 0);

    glBegin(GL_QUADS);
        glTexCoord2f(0,0);
        glVertex2f(x0,y0);

        glTexCoord2f(1,0);
        glVertex2f(x1,y0);

        glTexCoord2f(1,1);
        glVertex2f(x1,y1);

        glTexCoord2f(0,1);
        glVertex2f(x0,y1);

    glEnd();
}