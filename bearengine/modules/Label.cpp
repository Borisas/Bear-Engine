#include "Label.h"

using namespace BearEngine;


Label::Label(){};
Label::~Label(){

    if(_font != nullptr){
        TTF_CloseFont(_font);
    }

};

std::shared_ptr<BearEngine::Label> Label::create(){
    auto ptr = std::make_shared<BearEngine::Label>(Label());
    ptr->init();
    return ptr;
}

std::shared_ptr<BearEngine::Label> Label::createWithTTF(std::string txt,std::string fnt, unsigned int font_size){
    auto ptr = std::make_shared<BearEngine::Label>(Label());
    ptr->initWithTTF(txt,fnt,font_size);
    return ptr;
}

bool Label::init(){
    if(!Node::init())
        return false;
    return true;
}

bool Label::initWithTTF(std::string txt,std::string fnt, unsigned int font_size){
    if(!Node::init())
        return false;

    setFontSize(font_size);
    loadFont(fnt);
    setText(txt);

    _regenerate_texture();

    return true;
}

void Label::draw(BearEngine::NodeTransform transform){
    if(!_fresh){
        _regenerate_texture();
        _fresh = true;
    }

    float x0 = transform.position.x - transform.anchorPoint.x * (transform.contentSize.width * transform.scale.x);
    float y0 = transform.position.y - transform.anchorPoint.y * (transform.contentSize.height * transform.scale.y);
    float x1 = transform.position.x + (1-transform.anchorPoint.x) * (transform.contentSize.width * transform.scale.x);
    float y1 = transform.position.y + (1-transform.anchorPoint.y) * (transform.contentSize.height * transform.scale.y);

    glBindTexture(GL_TEXTURE_2D, _texture);

    glColor4f(getColor().r, getColor().g, getColor().b, getColor().a);


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

    glBindTexture(GL_TEXTURE_2D, 0);

}

void Label::loadFont(std::string fnt_file, bool regenerate){
    _font = TTF_OpenFont(fnt_file.c_str(), _font_size);
    if(!_font){
        std::cout << "TTF_OpenFont Error: " << TTF_GetError() << '\n';
    }
    _fresh = false;
    if(regenerate){
        _regenerate_texture();
        _fresh = true;
    }
}

void Label::setFont(TTF_Font* fnt, bool regenerate){
    _font = fnt;

    _fresh = false;
    if(regenerate){
        _regenerate_texture();
        _fresh = true;
    }
}

void Label::setFontSize(unsigned int size, bool regenerate){
    _font_size = size;

    _fresh = false;
    if(regenerate){
        _regenerate_texture();
        _fresh = true;
    }
}

void Label::setText(std::string text, bool regenerate){
    _text = text;

    _fresh = false;
    if(regenerate){
        _regenerate_texture();
        _fresh = true;
    }
}

TTF_Font* Label::getFont(){
    return _font;
}

unsigned int Label::getFontSize(){
    return _font_size;
}

std::string Label::getText(){
    return _text;
}

void Label::_regenerate_texture() {
    glGenTextures(1, &_texture);
    SDL_Surface * sdl_label = TTF_RenderText_Blended(
            _font,
            _text.c_str(),
            {
                    (int)(getColor().r*255),
                    (int)(getColor().g*255),
                    (int)(getColor().b*255),
                    (int)(getColor().a*255)
            }
    );
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, sdl_label->w, sdl_label->h, 0, GL_BGRA,
                 GL_UNSIGNED_BYTE, sdl_label->pixels);
    glBindTexture(GL_TEXTURE_2D, _texture);

    setContentSize({sdl_label->w, sdl_label->h});

    SDL_FreeSurface(sdl_label);
}