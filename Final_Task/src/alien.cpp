#include "alien.h"

Alien::Alien(AlienVar var, int x, int y)
{
    this->var = var;
    if(var == AlienVar::Normal) lifes = 1;
    else lifes = 2;
    setX(x);
    setY(y);
};

int Alien::getX()
{
    return x;
};

int Alien::getY()
{
    return y;  
};

AlienVar Alien::getVar()
{
    return var;
}

int Alien::getLifes()
{
    return lifes;
};

void Alien::setX(int a)
{
    x = a;
};

void Alien::setY(int a)
{
    y = a;
};

void Alien::setLifes(int a)
{
    lifes = a;
};