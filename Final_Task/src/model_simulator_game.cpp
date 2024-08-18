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

GameModel::GameModel(int wave)
    :player(height,width/2)
     {
        switch(wave)
        {
            case 1:
            {
                for(int i = 0; i < 10; i ++){
                    aliens1[i] = Alien(1, 10 + (2*i), 4);
    	            aliens2[i] = Alien(1, 10 + (2*i), 5);
                    aliens3[i] = Alien(1, 10 + (2*i), 6);
                    aliens4[i] = Alien(1, 10 + (2*i), 7);
                }
                break;
            }
            default:
            {
                Alien alien = Alien(1, 1, 1);
                alien.setDead(true);
                for(int i = 0; i < 10; i ++){
                    aliens1[i] = alien;
    	            aliens2[i] = alien;
                    aliens3[i] = alien;
                    aliens4[i] = alien;
                    break;
                }
            }
        }
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

Alien& GameModel::getAliens1(int index)
{
    return aliens1[index];
};

Alien& GameModel::getAliens2(int index)
{
    return aliens2[index];
};

Alien& GameModel::getAliens3(int index)
{
    return aliens3[index];
};

Alien& GameModel::getAliens4(int index)
{
    return aliens4[index];
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