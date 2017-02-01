#ifndef BEARENGINE_CMAKE_LABEL_H
#define BEARENGINE_CMAKE_LABEL_H

#include <memory>
#include <string>
#include <iostream>

#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_opengl.h"

#include "Node.h"

namespace BearEngine {

    class Label : public BearEngine::Node {

    public:

        virtual ~Label();

        static std::shared_ptr<BearEngine::Label> create();
        static std::shared_ptr<BearEngine::Label> createWithTTF(std::string text, std::string font, unsigned int fontsize);

        bool init() override;
        bool initWithTTF(std::string, std::string, unsigned int);

        void draw(BearEngine::NodeTransform) override;

        void loadFont(std::string, bool regenerate = false);

        void setFont        (TTF_Font*, bool regenerate = false);
        void setFontSize    (unsigned int, bool regenerate = false);
        void setText        (std::string, bool regenerate = false);

        TTF_Font* getFont();
        unsigned int getFontSize();
        std::string getText();


    private:

        Label();

        void _regenerate_texture();

        std::string     _text       = "";
        TTF_Font *      _font       = nullptr;
        unsigned int    _font_size  = 12;

        bool            _fresh      = false;
        GLuint          _texture;

    };

};

#endif //BEARENGINE_CMAKE_LABEL_H
