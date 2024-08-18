#include "player.h"

Player::Player(int x, int y)
{
    setX(x);
    setY(y);
};

int Player::getX() { 
    return x;
};

int Player::getY() { 
    return y;
};

int Player::getLifes()
{
    return lifes;
};

void Player::setX(int a) {
    x = a;
};

void Player::setY(int a) {
    y = a;
};

void Player::setLifes(int a)
{
    lifes =a;
};