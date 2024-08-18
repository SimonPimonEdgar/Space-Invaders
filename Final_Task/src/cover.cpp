#include "cover.h"

Cover::Cover(int x, int y)
{
    this->x = x;
    this->y = y;
}

int Cover::getLife()
{
    return life;
}

int Cover::getX()
{
    return x;
}

int Cover::getY()
{
    return y;
}

void Cover::setLife(int a)
{
    life = a;
}

void Cover::setX(int a)
{
    x = a;
}

void Cover::setY(int a)
{
    y = a;
}