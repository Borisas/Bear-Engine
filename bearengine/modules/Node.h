#ifndef BEARENGINE_CMAKE_NODE_H
#define BEARENGINE_CMAKE_NODE_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>

#include "SDL.h"

#include "../core/Structures.h"
#include "../core/EventHandlers.h"
#include "../core/Macros.h"

namespace BearEngine {

    class Scene;

    class Node {
    public:


        static std::shared_ptr<BearEngine::Node> create();

        virtual ~Node();

        virtual bool init();
        virtual void draw(BearEngine::NodeTransform) {};
        virtual void update(float dt) {};

        void addChild(std::shared_ptr<BearEngine::Node>, int z = 0);
        void removeChild(std::shared_ptr<BearEngine::Node>);
        void removeFromParent();

        void addEventHandler(std::shared_ptr<BearEngine::EventHandler>);
        void removeEventHandler(BearEngine::EventHandler*);

        void setPosition    (BearEngine::Point2);
        void setScale       (BearEngine::Vector2);
        void setScale       (float);
        void setContentSize (BearEngine::Size);
        void setAnchorPoint (BearEngine::Point2);
        void setColor       (BearEngine::Color4f);
        void setZIndex      (int);

        BearEngine::Point2                      getPosition();
        BearEngine::Vector2                     getScale();
        BearEngine::Size                        getContentSize();
        BearEngine::Point2                      getAnchorPoint();
        BearEngine::Color4f                     getColor();
        BearEngine::Rectangle                   getBoundingBox();
        BearEngine::NodeTransform               getNodeTransform();
        int                                     getZIndex();
//        BearEngine::Rectangle                   getTransformOnScreen();
        const std::vector<std::shared_ptr<BearEngine::Node> >&   getChildren();

    protected:
        Node();

    private:



        int                 _local_z_index  = 0;
        BearEngine::Point2  _position       = BearEngine::Point2(0.f,0.f);
        BearEngine::Point2  _anchor_point   = BearEngine::Point2(0.5f,0.5f);
        BearEngine::Vector2 _scale          = BearEngine::Vector2(1.f,1.f);
        BearEngine::Size    _content_size   = BearEngine::Size(0.f,0.f);
        BearEngine::Color4f _color          = BearEngine::Color4f(1.f,1.f,1.f,1.f);

        //TODO: Smart updated bounding boxes.


        std::vector<std::shared_ptr<BearEngine::EventHandler> > _ev_handlers;

        std::vector<std::shared_ptr<BearEngine::Node> > _children;

        BearEngine::Node* _parent;

        void _loop_tree(float dt, std::vector<SDL_Event> & events);
        void _loop_tree(float dt, std::vector<SDL_Event> & events, BearEngine::NodeTransform);

        BearEngine::NodeTransform _generate_transform(BearEngine::NodeTransform);


        friend class BearEngine::Scene;
    };

};
#endif //BEARENGINE_CMAKE_NODE_H
