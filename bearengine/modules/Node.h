#ifndef BEARENGINE_CMAKE_NODE_H
#define BEARENGINE_CMAKE_NODE_H

#include <iostream>
#include <vector>
#include <algorithm>

#include "SDL.h"

#include "../core/Structures.h"
#include "../core/EventHandlers.h"

namespace BearEngine {

    class Scene;

    class Node {
    public:

        Node();
        ~Node();

        virtual bool init() {};
        virtual void draw(BearEngine::NodeTransform) {};
        virtual void update(float dt) {};

        void addChild(BearEngine::Node*, int z = 0);
        void removeChild(BearEngine::Node*);

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
        const std::vector<BearEngine::Node*>&   getChildren();

    private:

        int                 _local_z_index  = 0;
        BearEngine::Point2  _position       = BearEngine::Point2(0.f,0.f);
        BearEngine::Point2  _anchor_point   = BearEngine::Point2(0.5f,0.5f);
        BearEngine::Vector2 _scale          = BearEngine::Vector2(1.f,1.f);
        BearEngine::Size    _content_size   = BearEngine::Size(0.f,0.f);
        BearEngine::Color4f _color          = BearEngine::Color4f(1.f,1.f,1.f,1.f);

        //TODO: Smart updated bounding boxes.
//    BearEngine::Rectangle _bounding_box;
//    bool _bounding_box_fresh = false;
        //---

        bool _mouse_events      = false;
        bool _keyboard_events   = false;

        EventHandler* _ev_handler = nullptr;


        std::vector<BearEngine::Node*> _children;

        BearEngine::Node* _parent;

        void _loop_tree(float dt, std::vector<SDL_Event> & events);
        void _loop_tree(float dt, std::vector<SDL_Event> & events, BearEngine::NodeTransform);

        BearEngine::NodeTransform _generate_transform(BearEngine::NodeTransform);


        friend class BearEngine::Scene;
    };

};
#endif //BEARENGINE_CMAKE_NODE_H
