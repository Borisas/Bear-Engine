#include "Scene.h"

using namespace BearEngine;

Scene::Scene(){};
Scene::~Scene(){};

void Scene::loopTree(float dt, std::vector<SDL_Event> & events){
    _child->_loop_tree(dt,events);
}

void Scene::addChild(BearEngine::Node * c) {
    _child = c;
    c->_parent = nullptr;
}