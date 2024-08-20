#include "model_simulator_game.h"
#include <algorithm>
#include <ncurses.h>
#include <stdlib.h>
#include <vector>
#include <random>

GameModel::GameModel(int wave)
    :player(height,width/2)
     {
        switch(wave)
        {
            case 1:
            {
                for(int i = 0; i < 40; i ++){
                    aliens.push_back( Alien(1, 10 + (int) 2 * (i%10), 4 + div(i, 10).quot));
                }
                covers.push_back(Cover((2 * width/5) -8, height - 6));
                covers.push_back(Cover((3* width/5) - 6, height - 6));
                covers.push_back(Cover((4* width/5) - 4, height - 6));
                break;
            }
            default:
            {
                break;
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

std::vector<Alien>& GameModel::getAliens()
{
    return aliens;
};

std::vector<Cover>& GameModel::getCovers()
{
    return covers;
};

std::vector<Shot>& GameModel::getShots()
{
    return shots;
};

void GameModel::control_player(wchar_t ch)
{
    playerShotTimer --;
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
    if(ch == ' ') 
    {
        if(playerShotTimer <= 0)
        {
        Shot newShot = Shot(player.getX(), player.getY()-2, true);
        shots.push_back(newShot);
        playerShotTimer = 15;
        }
    }
};

void GameModel::moveAliens()
{
    if(alienTimer == 15 || alienTimer == 30 || alienTimer == 45)
    {
        if(alienTimer==45) alienTimer = 0;
        if(!alienDir)
        {
            if(!(aliens[9].getX() == width - 3))
            {
                for(Alien& a : aliens)
                { 
                    a.setX(a.getX() + 1);
                }
            }
            else
            {
                for(Alien& a : aliens)
                { 
                    a.setY(a.getY() + 1);
                }  
                alienDir = true;
            }
        }
        else 
        {
            if(!(aliens[0].getX() == 2))
            {
                for(Alien& a : aliens)
                { 
                    a.setX(a.getX() - 1);
                }
            }
            else
            {
                for(Alien& a : aliens)
                { 
                    a.setY(a.getY() + 1);
                }  
                alienDir = false;
            }
        }
    }
};

// Geschrieben mit Hilfe von Ki
void GameModel::eraseShotsAndAliens()
{
    std::remove_if(shots.begin(), shots.end(), [](Shot& shot)
    {
        return !shot.getActive();
    }),
    shots.end();
    std::remove_if(aliens.begin(), aliens.end(), [](Alien& alien)
    {
        return alien.getDead();
    }),
    aliens.end();
};

void GameModel::moveShots()
{
    for(Shot& s : shots)
    {
        if(s.getDir())s.setY(s.getY()- 1);
        else s.setY(s.getY()+ 1);
    }
};

std::vector<Alien> GameModel::filterBottom()
{
    std::vector<Alien> aliensBottom(aliens);
    std::remove_if(aliensBottom.begin(), aliensBottom.end(), [this](Alien& alien1)
    {
        for(Alien& alien2 : aliens)
        {
            if(alien2.getX() == alien1.getX() && alien2.getY() < alien1.getY()) return true;
        };
        return false;
    }),
    aliensBottom.end();
    return aliensBottom;
};

void GameModel::aliensShoot()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    double p = 0.025;
    std::vector<Alien> aliensBottom = filterBottom();
    for(Alien& alien : aliensBottom)
    {
        double random_value = dis(gen);
        if (random_value <= p) {
            Shot newShot = Shot(alien.getX(), alien.getY() + 1, false);
            shots.push_back(newShot);
        }
    }
};

void GameModel::simulate_game_step()
{
    // Implement game dynamics.
    // waveCreation();
    // hasWon();
    if(alienTimer == 45)aliensShoot();
    if(alienTimer%5 == 0)moveShots();
    moveAliens();
    eraseShotsAndAliens();
    notifyUpdate();
    alienTimer ++;
};