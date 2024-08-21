#include "model_simulator_game.h"
#include <algorithm>
#include <cstdio>
#include <ncurses.h>
#include <stdlib.h>
#include <thread>
#include <vector>
#include <random>
#include <iostream>
#include <locale>

GameModel::GameModel()
    :player(width/2,height - 4)
    {};

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

Status GameModel::getStatus()
{
    return status;
};

int GameModel::getWave()
{
    return wave;
};

Controll GameModel::getCurrent()
{
    return current;
};

wchar_t GameModel::getUp()
{
    return up;
};

wchar_t GameModel::getDown()
{
    return down;
};

wchar_t GameModel::getLeft()
{
    return left;
};

wchar_t GameModel::getRight()
{
    return right;
};

wchar_t GameModel::getShoot()
{
    return shoot;
};

void GameModel::control_player(wchar_t ch)
{
    if(invalide == '1') invalide = ch;
    switch(status)
    {
    case Status::ingame:
    {
        playerShotTimer --;
        if(ch == left)
        {
            if(player.getX() > 1) player.setX(player.getX() - 1);
        }
        else {
            if (ch == right) 
            {
                if(player.getX() < getGameWidth()-2) player.setX(player.getX() + 1);
            }
            else {
                if (ch == up) 
                {
                    if(player.getY() > 3) player.setY(player.getY()-1);
                }
                else {
                    if (ch == down) 
                    {
                        if(player.getY() < getGameHeight()-1) player.setY(player.getY()+1);
                    }
                    else {
                        if (ch == shoot) 
                        {
                            Shot newShot = Shot(player.getX(), player.getY()-1, true);
                            shots.push_back(newShot);
                            playerShotTimer = 15;
                        }
                    }
                }
            }
        }
        break;
    }
    case Status::titlescreen:
        {
            switch(ch)
            {
            case L'1':
            {
                status = Status::ingame;
                if(player.getLifes() > 0) wave ++;
                else
                {
                    wave = 1;
                    player.setScore(0);
                }
                waveCreation(wave);
                break;
            }
            case L'2':
            {
                status = Status::settings;

                break;
            }
            default:
                break;
            }
            break;
        }
    case Status::settings:
        {
            switch (ch) {
            case '1':
            {
                if(current == Controll::none)
                {
                    current = Controll::up;  
                }
                else if(ch != invalide)
                {
                    switch (current)
                    {
                        case Controll::up:
                            up = ch;
                            current = Controll::none;
                            break;
                        
                        case Controll::down:
                            down = ch;
                            current = Controll::none;
                            break;
                        
                        case Controll::left:
                            left = ch;
                            current = Controll::none;
                            break;
                        
                        case Controll::right:
                            right = ch;
                            current = Controll::none;
                            break;

                        case Controll::shoot:
                            shoot = ch;
                            current = Controll::none;
                            break;
                        
                        default:
                            break;
                    }
                }
                break;
            }
            case '2':
            {
                if(current == Controll::none)
                {
                    current = Controll::down;  
                }
                else if(ch != invalide)
                {
                    switch (current)
                    {
                        case Controll::up:
                            up = ch;
                            current = Controll::none;
                            break;
                        
                        case Controll::down:
                            down = ch;
                            current = Controll::none;
                            break;
                        
                        case Controll::left:
                            left = ch;
                            current = Controll::none;
                            break;
                        
                        case Controll::right:
                            right = ch;
                            current = Controll::none;
                            break;

                        case Controll::shoot:
                            shoot = ch;
                            current = Controll::none;
                            break;
                        
                        default:
                            break;
                    }
                }
                break;
            }
            case '3':
            {
                if(current == Controll::none)
                {
                    current = Controll::left;  
                }
                else if(ch != invalide)
                {
                    switch (current)
                    {
                        case Controll::up:
                            up = ch;
                            current = Controll::none;
                            break;
                        
                        case Controll::down:
                            down = ch;
                            current = Controll::none;
                            break;
                        
                        case Controll::left:
                            left = ch;
                            current = Controll::none;
                            break;
                        
                        case Controll::right:
                            right = ch;
                            current = Controll::none;
                            break;

                        case Controll::shoot:
                            shoot = ch;
                            current = Controll::none;
                            break;
                        
                        default:
                            break;
                    }
                }
                break;
            }
            case '4':
            {
                if(current == Controll::none)
                {
                    current = Controll::right;  
                }
                else if(ch != invalide)
                {
                    switch (current)
                    {
                        case Controll::up:
                            up = ch;
                            current = Controll::none;
                            break;
                        
                        case Controll::down:
                            down = ch;
                            current = Controll::none;
                            break;
                        
                        case Controll::left:
                            left = ch;
                            current = Controll::none;
                            break;
                        
                        case Controll::right:
                            right = ch;
                            current = Controll::none;
                            break;

                        case Controll::shoot:
                            shoot = ch;
                            current = Controll::none;
                            break;
                        
                        default:
                            break;
                    }
                }
                break;
            }
            case '5':
            {
                if(current == Controll::none)
                {
                    current = Controll::shoot;  
                }
                else if(ch != invalide)
                {
                    switch (current)
                    {
                        case Controll::up:
                            up = ch;
                            current = Controll::none;
                            break;
                        
                        case Controll::down:
                            down = ch;
                            current = Controll::none;
                            break;
                        
                        case Controll::left:
                            left = ch;
                            current = Controll::none;
                            break;
                        
                        case Controll::right:
                            right = ch;
                            current = Controll::none;
                            break;

                        case Controll::shoot:
                            shoot = ch;
                            current = Controll::none;
                            break;
                        
                        default:
                            break;
                    }
                }
                break;
            }
            case '6':
                {
                if(current == Controll::none)
                {
                    status = Status::titlescreen;
                    break;  
                }
                else if(ch != invalide)
                {
                    switch (current)
                    {
                        case Controll::up:
                            up = ch;
                            current = Controll::none;
                            break;
                        
                        case Controll::down:
                            down = ch;
                            current = Controll::none;
                            break;
                        
                        case Controll::left:
                            left = ch;
                            current = Controll::none;
                            break;
                        
                        case Controll::right:
                            right = ch;
                            current = Controll::none;
                            break;

                        case Controll::shoot:
                            shoot = ch;
                            current = Controll::none;
                            break;
                        
                        default:
                            break;
                    }
                }
                break;
            }
            default:
                {
                if(ch != invalide)
                {
                switch (current)
                    {
                        case Controll::up:
                            up = ch;
                            current = Controll::none;
                            break;
                        
                        case Controll::down:
                            down = ch;
                            current = Controll::none;
                            break;
                        
                        case Controll::left:
                            left = ch;
                            current = Controll::none;
                            break;
                        
                        case Controll::right:
                            right = ch;
                            current = Controll::none;
                            break;

                        case Controll::shoot:
                            shoot = ch;
                            current = Controll::none;
                            break;
                        
                        default:
                            break;
                    }
                }
            }
            break;
        }
    default:
        break;  
    }
    }
};

bool GameModel::reachedBorder()
{
    for(Alien& alien : aliens)
    {
        if(alien.getX() == width - 3 && alienDir == false) return true;
        if(alien.getX() == 2 && alienDir == true) return true;
    }
    return false;
};

void GameModel::moveAliens()
{
    if(alienTimer == 15 || alienTimer == 30 || alienTimer == 45)
    {
        if(alienTimer==45) alienTimer = 0;
        if(!alienDir)
        {
            if(!reachedBorder())
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
            if(!reachedBorder())
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
void GameModel::eraser()
{
    shots.erase(
    std::remove_if(shots.begin(), shots.end(), [](Shot& shot)
    {
        return !shot.getActive();
    }),
    shots.end());
    aliens.erase(
    std::remove_if(aliens.begin(), aliens.end(), [](Alien& alien)
    {
        return alien.getHit();
    }),
    aliens.end());
    covers.erase(
    std::remove_if(covers.begin(), covers.end(), [](Cover& cover)
    {
        return cover.getLifes() == 0;
    }),
    covers.end());
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

void GameModel::calcScore(Alien alien)
{
    if(alien.getVar() == 1) player.setScore(player.getScore() + 50);
};

void GameModel::collision()
{
    std::transform(aliens.begin(), aliens.end(), aliens.begin(), [this](Alien alien) {
        alien.setHit(false);
        for(Shot& shot: shots)
        {
            if(shot.getX() == alien.getX() && shot.getY() == alien.getY())
            {
                 alien.setHit(true);
                 shot.setActive(false);
                 calcScore(alien);
            }
        }
        return alien;
    });
    for(Shot& shot : shots)
    {
        if(shot.getX() == player.getX() && shot.getY() == player.getY())
            {
                player.setLifes(player.getLifes()-1);
                shot.setActive(false);
                if(player.getScore()>= 100)player.setScore(player.getScore() - 100);
            }
    }
    std::transform(covers.begin(), covers.end(), covers.begin(), [this](Cover cover) {
        for(Shot& shot: shots)
        {
            if(shot.getX() == cover.getX() && shot.getY() == cover.getY() || shot.getX() == cover.getX()+1 && shot.getY() == cover.getY() 
            || shot.getX() == cover.getX()+2 && shot.getY() == cover.getY())
            {
                if(!shot.getDir())   cover.setLifes(cover.getLifes() - 1);
                shot.setActive(false);
            }
        }
        return cover;
    });
    for(Shot& shot : shots)
    {
        if(shot.getY() > height - 2 ||shot.getY() < 1) shot.setActive(false);
    }
};

void GameModel::reset()
{
    player.setLifes(3);
    player.setX(width/2);
    player.setY(height - 4);
    shots.clear();
    aliens.clear();
    covers.clear();
    alienTimer = 0;
    playerShotTimer = 0;
};

void GameModel::waveCreation(int w)
{
    switch(w)
        {
            case 1:
            {
                reset();
                for(int i = 0; i < 40; i ++){
                    aliens.push_back( Alien(1, 10 + (int) 2 * (i%10), 4 + div(i, 10).quot));
                }
                covers.push_back(Cover((width - 2)/2, height - 6));
                covers.push_back(Cover((width - 1)/4, height - 6));
                covers.push_back(Cover(3*(width - 1)/4, height - 6));
                break;
            }
            case 2:
            {
                reset();
                for(int i = 0; i < 20; i ++){
                    aliens.push_back( Alien(2, 10 + (int) 2 * (i%10), 4 + div(i, 10).quot));
                }
                for(int i = 0; i < 20; i ++){
                    aliens.push_back( Alien(1, 10 + (int) 2 * (i%10), 6 + div(i, 10).quot));
                }
                covers.push_back(Cover((2 * width/5) -8, height - 6));
                covers.push_back(Cover((4* width/5) - 4, height - 6));
                break;
            }
            case 3:
            {
                reset();
                for(int i = 0; i < 10; i ++){
                    aliens.push_back( Alien(3, 10 + (int) 2 * (i%10), 4));
                }
                for(int i = 0; i < 20; i ++){
                    aliens.push_back( Alien(2, 10 + (int) 2 * (i%10), 5 + div(i, 10).quot));
                }
                for(int i = 0; i < 10; i ++){
                    aliens.push_back( Alien(1, 10 + (int) 2 * (i%10), 7));
                }
                covers.push_back(Cover((3* width/5) - 6, height - 6));
                break;
            }
            default:
            {
                wave = 1;
                waveCreation(wave);
                break;
            }
        }
};

void GameModel::simulate_game_step()
{
    // Implement game dynamics.
    if(status == Status::ingame)
    {
    if(alienTimer == 45)aliensShoot();
    if(alienTimer%5 == 0)moveShots();
    moveAliens();
    collision();
    eraser();
    if(player.getLifes() == 0 || aliens.empty()) status = Status::titlescreen;
    }
    notifyUpdate();
    alienTimer ++;
};