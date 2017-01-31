#include "Scene.h"

using namespace BearEngine;

std::shared_ptr<BearEngine::Scene> Scene::create(){
    auto ptr = std::make_shared<BearEngine::Scene>(Scene());
    ptr->init();
    return ptr;
}

Scene::Scene(){};
Scene::~Scene(){
    //std::cout << "SCENE DELETE CALLED(" << this << ")" << '\n';
};

bool Scene::init(){
    return true;
}

void Scene::loopTree(float dt, std::vector<SDL_Event> & events){
    _child->_loop_tree(dt,events);
}

void Scene::addChild(std::shared_ptr<BearEngine::Node> c) {
    _child = c;
    c->_parent = nullptr;
}