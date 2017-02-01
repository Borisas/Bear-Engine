#ifndef BEARENGINE_CMAKE_STRUCTURES_H
#define BEARENGINE_CMAKE_STRUCTURES_H

#include "SDL_opengl.h"

namespace BearEngine {

    struct Rectangle {
        Rectangle() : x(0), y(0), width(0), height(0) {};
        Rectangle(float _x,float _y, float _width, float _height)
                : x(_x), y(_y), width(_width), height(_height){};

        float x;
        float y;
        float width;
        float height;
    };

    struct Size {
        Size() : width(0), height(0) {};
        Size(float _width, float _height)
                : width(_width), height(_height){};

        float width;
        float height;
    };

    struct Vector2 {
        Vector2() : x(0), y(0) {};
        Vector2(float _x, float _y)
                : x(_x), y(_y){};

        float x;
        float y;
    };

    struct Point2 {
        Point2() : x(0), y(0) {};
        Point2(float _x, float _y)
                : x(_x), y(_y){};

        float x;
        float y;
    };

    struct Color3f {
        Color3f() : r(0), g(0), b(0) {};
        Color3f(float _r, float _g, float _b)
                : r(_r), g(_g), b(_b){};

        float r;
        float g;
        float b;
    };

    struct Color3b {
        Color3b() : r(0), g(0), b(0) {};
        Color3b(GLubyte _r, GLubyte _g, GLubyte _b)
                : r(_r), g(_g), b(_b){};

        GLubyte r;
        GLubyte g;
        GLubyte b;
    };

    struct Color4f {
        Color4f() : r(0), g(0), b(0), a(0) {};
        Color4f(float _r, float _g, float _b, float _a)
                : r(_r), g(_g), b(_b), a(_a){};

        float r;
        float g;
        float b;
        float a;
    };

    struct Color4b {
        Color4b() : r(0), g(0), b(0), a(0) {};
        Color4b(GLubyte _r, GLubyte _g, GLubyte _b, GLubyte _a)
                : r(_r), g(_g), b(_b), a(_a){};

        GLubyte r;
        GLubyte g;
        GLubyte b;
        GLubyte a;
    };

    struct NodeTransform {
        NodeTransform(
                BearEngine::Point2  _position,
                BearEngine::Point2  _anchorPoint,
                BearEngine::Vector2 _scale,
                BearEngine::Vector2 _pscale,
                BearEngine::Size    _contentSize,
                BearEngine::Color4f _color,
                int                 _zIndex
                ):
                position(_position),
                anchorPoint(_anchorPoint),
                scale(_scale),
                parentScale(_pscale),
                contentSize(_contentSize),
                color(_color),
                zIndex(_zIndex)
        {
            no_transform = false;
        };
        NodeTransform(){
            no_transform = true;
        };

        BearEngine::Point2  position;
        BearEngine::Point2  anchorPoint;
        BearEngine::Vector2 scale;
        BearEngine::Vector2 parentScale;
        BearEngine::Size    contentSize;
        BearEngine::Color4f color;
        int                 zIndex;

        bool no_transform;
    };
};

#endif //BEARENGINE_CMAKE_STRUCTURES_H
