#include "alien.h"

Alien::Alien(int var, int x, int y)
{
    this->var = var;
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

int Alien::getVar()
{
    return var;
};

bool Alien::getDead()
{
    return dead;
};

void Alien::setX(int a)
{
    x = a;
};

void Alien::setY(int a)
{
    y = a;
};

void Alien::setDead(bool a)
{
    dead = a;
};