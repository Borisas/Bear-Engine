#include "Node.h"

using namespace BearEngine;
using std::cout;

Node::Node() {}
Node::~Node() {
    cout << "NODE DELETE CALLED" << '\n';
}

void Node::addChild(BearEngine::Node * ch, int z) {
    ch->setZIndex(z);
    ch->_parent = this;
    _children.push_back(ch);

    std::sort(_children.begin(), _children.end(), [](BearEngine::Node* a, BearEngine::Node* b){
        return a->getZIndex() < b->getZIndex();
    });
}
void Node::removeChild(BearEngine::Node *) {
    //TODO: WRITE CODE
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
            getContentSize(),
            getColor(),
            getZIndex()
    };
}
int Node::getZIndex() {
    return _local_z_index;
}
const std::vector<BearEngine::Node*>& Node::getChildren(){
    return _children;
}

NodeTransform Node::_generate_transform(BearEngine::NodeTransform t) {

    if(t.no_transform)
        return getNodeTransform();


    // parent (0,0) point
    Point2 parent_real_pos = {
        t.position.x - t.anchorPoint.x * t.contentSize.width,
        t.position.y - t.anchorPoint.y * t.contentSize.height
    };

    Point2 my_pos = {
            parent_real_pos.x + getPosition().x,
            parent_real_pos.y + getPosition().y
    };

    Vector2 _scale = {
            t.scale.x * getScale().x,
            t.scale.y * getScale().y
    };

    return {
        my_pos,
        getAnchorPoint(),
        _scale,
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
     *  2: get and sort children by zIndex
     *  3: loop_tree children
     *  4: draw node
     */


    BearEngine::NodeTransform my_transform = getNodeTransform();

    if(_mouse_events){
        // CATCH MOUSE EVENT
    }
    if(_keyboard_events){
        //CATCH KEYBOARD EVENT
    }

    update(dt);

    draw( my_transform );

    for(auto child : _children){
        child->_loop_tree(dt, events, my_transform);
    }

}
void Node::_loop_tree(float dt, std::vector<SDL_Event> & events, BearEngine::NodeTransform parentTransform) {

    BearEngine::NodeTransform my_transform = _generate_transform(parentTransform);

    if(_mouse_events){
        // CATCH MOUSE EVENT
    }
    if(_keyboard_events){
        //CATCH KEYBOARD EVENT
    }

    update(dt);

    draw(my_transform);

    for(auto child : _children){
        child->_loop_tree(dt, events, my_transform);
    }

}


