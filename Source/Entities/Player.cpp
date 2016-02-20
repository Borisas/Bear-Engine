#include "Player.h"

Player::Player(){
}
Player::~Player(){
}
bool Player::init(){
    if(!Sprite::initWithFile("Assets/player.png"))
        return false;
    return true;
}
void Player::move(int direction){
    switch(direction){
        case 1:
            this->setPosition(getPosition().x, getPosition().y - (movementSpeed * Wizard::getInstance()->getFPSMultiplier()));
        break;
        case 2:
            this->setPosition(getPosition().x + (movementSpeed * Wizard::getInstance()->getFPSMultiplier()), getPosition().y);
        break;
        case 3:
            this->setPosition(getPosition().x, getPosition().y + (movementSpeed * Wizard::getInstance()->getFPSMultiplier()));
        break;
        case 4:
            this->setPosition(getPosition().x - (movementSpeed * Wizard::getInstance()->getFPSMultiplier()), getPosition().y);
        break;
    };
}
