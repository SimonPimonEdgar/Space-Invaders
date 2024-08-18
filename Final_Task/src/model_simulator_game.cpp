#include "model_simulator_game.h"
#include <ncurses.h>
#include <stdlib.h>

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

void Player::setX(int a) {
    x = a;
};

void Player::setY(int a) {
    y = a;
};

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

GameModel::GameModel()
    : player(height, width/2 ) {
};

// Example function - used for simple unit tests
int GameModel::addOne(int input_value) {
    return (++input_value); 
};

int GameModel::getGameWidth() {
    return width; 
};
    
int GameModel::getGameHeight() {
    return height; 
};
    
Player& GameModel::getPlayer() {
    return player; 
};

void GameModel::control_player(wchar_t ch)
{
    switch(ch)
    {
        case KEY_LEFT:
            if(player.getX() > 1)
            {
               player.setX(player.getX() - 1); 
            }
           break;
        case KEY_RIGHT:
            if(player.getX() < getGameWidth()-2)
            {    
                player.setX(player.getX() + 1);
            }
            break;
        case KEY_UP:
            if(player.getY() > 3)
            {
                	player.setY(player.getY()-1);
            }
            break;
        case KEY_DOWN:
            if(player.getY() < getGameHeight()-1)
            {
                player.setY(player.getY()+1);
            }
            break;
        default:
            break;
    }
};

void GameModel::simulate_game_step()
{
    // Implement game dynamics.
    notifyUpdate();
};