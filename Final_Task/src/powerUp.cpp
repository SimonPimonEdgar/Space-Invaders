#include "powerUp.h"

PowerUp:: PowerUp(int x, int y, PowerUpVar var)
{
    this->x = x;
    this->y = y;
    this->var = var;
};

int PowerUp::getX()
{
    return x;
};

int PowerUp::getY()
{
    return y;
};

PowerUpVar PowerUp::getVar()
{
    return var;
};

bool PowerUp::getActive()
{
    return active;
};

void PowerUp::setX(int a)
{
    x = a;
};

void PowerUp::setY(int a)
{
    y = a;
};

void PowerUp::setActive(bool a)
{
    active = a;
};