#include "shot.h"

Shot::Shot(int x, int y, bool dir)
{
    this->x = x;
    this->y = y;
    this->dir = dir;
};

bool Shot::getDir()
{
    return dir;
};

int Shot::getX()
{
    return x;
};

int Shot::getY()
{
    return y;
};

bool Shot::getActive()
{
    return active;
};

void Shot::setX(int a)
{
    x = a;
};

void Shot::setY(int a)
{
    y = a;
};