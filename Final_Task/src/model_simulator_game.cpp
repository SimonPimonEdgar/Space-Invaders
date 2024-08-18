#include "model_simulator_game.h"
#include <algorithm>
#include <ncurses.h>
#include <stdlib.h>

GameModel::GameModel(int wave)
    :player(height,width/2)
     {
        switch(wave)
        {
            case 1:
            {
                for(int i = 0; i < 40; i ++){
                    aliens[i] = Alien(1, 10 + (int) 2 * (i%10), 4 + div(i, 10).quot);
                }
                break;
            }
            default:
            {
                Alien alien = Alien(1, 1, 1);
                alien.setDead(true);
                for(int i = 0; i < 40; i ++){
                    aliens[i] = alien;
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

Alien& GameModel::getAliens(int index)
{
    return aliens[index];
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

void GameModel::moveAliens()
{
    if(alienTimer == 1)
    {
        alienTimer = 0;
        if(!alienDir)
        {
            if(!(aliens[9].getX() == width - 3))
            {
                for(int i = 0; i < 40; i++)
                { 
                    aliens[i].setX(aliens[i].getX() + 1);
                }
            }
            else
            {
                for(int i = 0; i < 40; i++)
                { 
                    aliens[i].setY(aliens[i].getY() + 1);
                }  
                alienDir = true;
            }
        }
        else 
        {
            if(!(aliens[0].getX() == 3))
            {
                for(int i = 0; i < 40; i++)
                { 
                    aliens[i].setX(aliens[i].getX() - 1);
                }
            }
            else
            {
                for(int i = 0; i < 40; i++)
                { 
                    aliens[i].setY(aliens[i].getY() + 1);
                }  
                alienDir = false;
            }
        }
    }
};

void GameModel::simulate_game_step()
{
    // Implement game dynamics.
    // waveCreation();
    // hasWon();
    moveAliens();
    notifyUpdate();
    alienTimer ++;
};