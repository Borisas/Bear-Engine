#include "Node.h"

using namespace BearEngine;
using std::cout;

std::shared_ptr<BearEngine::Node> Node::create(){
    auto ptr = std::make_shared<Node>( Node() );
    ptr->init();
    return ptr;
}


Node::Node() {}
Node::~Node() {
    //cout << "NODE DELETE CALLED(" << this << ")" << '\n';
}

bool Node::init(){
    return true;
}

void Node::addChild(std::shared_ptr<BearEngine::Node> ch, int z) {
    ch->setZIndex(z);
    ch->_parent = this;
    _children.push_back(ch);

    std::sort(_children.begin(), _children.end(), [](std::shared_ptr<Node> a, std::shared_ptr<Node> b){
        return a->getZIndex() < b->getZIndex();
    });
}

void Node::removeChild(std::shared_ptr<BearEngine::Node> ch) {

    for(unsigned int i = 0; i < _children.size(); i++){

        if(_children[i] == ch){
            _children[i]->_parent = nullptr;
            _children.erase(_children.begin()+i);
        }

    }
}

void Node::removeFromParent() {
//    _parent->removeChild(this);
}

void Node::addEventHandler(std::shared_ptr<BearEngine::EventHandler> evhandler) {

    _ev_handlers.push_back(evhandler);
}

void Node::removeEventHandler(BearEngine::EventHandler * evhandler) {

//    for(unsigned int i = 0; i < _ev_handlers.size(); i++){
//        if(_ev_handlers[i] == evhandler){
//            _ev_handlers.erase(_ev_handlers.begin()+i);
//        }
//    }
}

void Node::setPosition(Point2 p) {
    _position = p;
}

void Node::setScale(Vector2 s){
    _scale = s;
}
void Node::setScale(float s){
    _scale.x = s;
    _scale.y = s;
}

void Node::setContentSize(BearEngine::Size sz){
    _content_size = sz;
}

void Node::setAnchorPoint(Point2 a) {
    _anchor_point = a;
}

void Node::setColor(BearEngine::Color4f c) {
    _color = c;
}

void Node::setZIndex(int z) {
    _local_z_index = z;
}

Point2 Node::getPosition() {
    return _position;
}

Vector2 Node::getScale(){
    return _scale;
}

Size Node::getContentSize() {
    return _content_size;
}

Point2 Node::getAnchorPoint() {
    return _anchor_point;
}

Color4f Node::getColor() {
    return _color;
}

BearEngine::Rectangle Node::getBoundingBox() {
    return BearEngine::Rectangle(
            _position.x - _anchor_point.x * (_content_size.width * _scale.x),
            _position.y - _anchor_point.x * (_content_size.height * _scale.y),
            _content_size.width * _scale.x,
            _content_size.height * _scale.y
    );
}

NodeTransform Node::getNodeTransform() {
    return {
            getPosition(),
            getAnchorPoint(),
            getScale(),
            {1.f,1.f},
            getContentSize(),
            getColor(),
            getZIndex()
    };
}
int Node::getZIndex() {
    return _local_z_index;
}

//BearEngine::Rectangle Node::getTransformOnScreen() {
//    auto rect = BearEngine::Rectangle();
//
//
//    auto node = this;
//
//    while(node != nullptr){
//
//        rect.x += node->getPosition().x - node->getAnchorPoint().x * node->getContentSize().width * node->getScale().x;
//        rect.y += node->getPosition().y - node->getAnchorPoint().y * node->getContentSize().height * node->getScale().y;
//
//        node = node->_parent;
//    }
//
//    return rect;
//}

const std::vector<std::shared_ptr<BearEngine::Node> >& Node::getChildren(){
    return _children;
}

NodeTransform Node::_generate_transform(BearEngine::NodeTransform t) {

    if(t.no_transform)
        return getNodeTransform();


    // parent (0,0) point
    Point2 parent_real_pos = {
        t.position.x - t.anchorPoint.x * t.contentSize.width * t.scale.x,
        t.position.y - t.anchorPoint.y * t.contentSize.height * t.scale.y
    };

    Point2 my_pos = {
            parent_real_pos.x + getPosition().x *t.scale.x,
            parent_real_pos.y + getPosition().y *t.scale.y
    };

    Vector2 _scale = {
            t.scale.x * getScale().x,
            t.scale.y * getScale().y
    };

    return {
        my_pos,
        getAnchorPoint(),
        _scale,
        t.scale,
        getContentSize(),
        getColor(),
        getZIndex()
    };

}

void Node::_loop_tree(float dt, std::vector<SDL_Event> & events) {
    // ONLY CALLED IF TOP DOG OF SCENE
    if(_parent != nullptr)
        return;

    /*
     * ORDER OF ACTIONS:
     *  1: update node
     *  2: draw node
     *  3: get and sort children by zIndex
     *  4: loop_tree children
     *
     */


    BearEngine::NodeTransform my_transform = getNodeTransform();

    if(_ev_handlers.size() > 0){
        for(auto eh : _ev_handlers){
            eh->handleEvents(events,my_transform);
        }
    }

    update(dt);
    draw( my_transform );

    for(auto child : _children){
        child->_loop_tree(dt, events, my_transform);
    }

}
void Node::_loop_tree(float dt, std::vector<SDL_Event> & events, BearEngine::NodeTransform parentTransform) {

    BearEngine::NodeTransform my_transform = _generate_transform(parentTransform);

    if(_ev_handlers.size() > 0){
        for(auto eh : _ev_handlers){
            eh->handleEvents(events,my_transform);
        }
    }

    update(dt);

    draw(my_transform);

    for(auto child : _children){
        child->_loop_tree(dt, events, my_transform);
    }

}


