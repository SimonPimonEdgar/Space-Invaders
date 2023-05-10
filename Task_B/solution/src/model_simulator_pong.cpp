#include "model_simulator_pong.h"
#include <ncurses.h>
#include <stdlib.h>

PongObject::PongObject(double _y, double _x) : x(_x), y(_y) {};

double PongObject::getX() { 
    return x;
};

double PongObject::getY() { 
    return y;
};

void PongObject::setX(double a) {
    x = a;
};

void PongObject::setY(double a) {
    y = a;
};

Player::Player(double y, double x, int _height=4) : PongObject{y,x}, height(_height) {};
    
int Player::getHeight() {
    return height;
};

Ball::Ball(double y, double x, int _speed) : PongObject {y,x}, speed(_speed) {};

int Ball::getSpeed() { 
    return speed; 
};

void Ball::setSpeed(int a){
    speed = a;
};


PongModel::PongModel()
    : player1(height / 2, 2), player2(height / 2, width - 3), ball(height / 2, 3, 1) {
};

Ball& PongModel::getBall() {
    return ball; 
};
    
Player& PongModel::getPlayer1() {
    return player1; 
};

Player& PongModel::getPlayer2() {
    return player2; 
};

int PongModel::getGameWidth() {
    return width; 
};
    
int PongModel::getGameHeight() {
    return height; 
};
    
int PongModel::getPlayer1Points() {
    return player1Points; 
};

int PongModel::getPlayer2Points() {
    return player2Points; 
};

void PongModel::simulate_game_step()
{
    /*
     * Ball directions
     *
     * 1 - Right
     * 2 - Left
     * 3 - Right Up
     * 4 - Right down
     * 5 - Left Up
     * 6 - Left down
     *
     */

    // Ball logic
    if(ball.getX() == player1.getX() + 1 || ball.getX() == player1.getX()) {
        if(ball.getY() <= player1.getY() + 2 && ball.getY() >= player1.getY() - 2) {
            if(ball.getY() >= player1.getY() - 2 && ball.getY() < player1.getY())
                dir = 3;
            else if(ball.getY() <= player1.getY() + 2 && ball.getY() > player1.getY())
                dir = 4;
            else
                dir = 1;
        }
    }
    if(ball.getX() == player2.getX() - 1  || ball.getX() == player2.getX()) {
        if(ball.getY() <= player2.getY() + 2 && ball.getY() >= player2.getY() - 2) {
            if (ball.getY() >= player2.getY() - 2 && ball.getY() < player2.getY())
                dir = 5;
            else if (ball.getY() <= player2.getY() + 2 && ball.getY() > player2.getY())
                dir = 6;
            else
                dir = 2;
        }
    }

    if(ball.getY() == height - 2) {
        if (dir == 6)
            dir = 5;
        else
            dir = 3;
    }

    if(ball.getY() == 1) {
        if(dir == 5)
            dir = 6;
        else
            dir = 4;
    }

    if(ball.getX() == 0) {
        player2Points++;
        player1Serve = true;
    }

    if(ball.getX() == width) {
        player1Points++;
        player2Serve = true;
    }

    if(player1Serve) {
        ball.setX(player1.getX() + 1);
        ball.setY(player1.getY());
    }

    if(player2Serve) {
        ball.setX(player2.getX() - 1);
        ball.setY(player2.getY());
    }

    // Ball directions
    if(!player1Serve || !player2Serve) {
        if(dir == 1)
            ball.setX(ball.getX() + 1);
        if(dir == 2)
            ball.setX(ball.getX() - 1);

        if(dir == 3) {
            ball.setX(ball.getX() + 1);
            ball.setY(ball.getY() - 0.25);
        }
        if(dir == 4) {
            ball.setX(ball.getX() + 1);
            ball.setY(ball.getY() + 0.25);
        }
        if(dir == 5) {
            ball.setX(ball.getX() - 1);
            ball.setY(ball.getY() - 0.25);
        }
        if(dir == 6) {
            ball.setX(ball.getX() - 1);
            ball.setY(ball.getY() + 0.25);
        }
    }

    if(ball.getY() > player1.getY()) {
        player1.setY(player1.getY() + 1);
    }
    else {
        player1.setY(player1.getY() -1);
    }

    notifyUpdate();
};

void PongModel::control_players(wchar_t ch)
{
    switch(ch) {
        case KEY_UP:
            if(player2.getY() != 3)
                player2.setY(player2.getY() - 1);
            break;
        case KEY_DOWN:
            if(player2.getY() != height - 4)
                player2.setY(player2.getY() + 1);
            break;
        case KEY_LEFT:
            if(player2.getX() != width / 2 + 4)
                player2.setX(player2.getX() - 1);
            break;
        case KEY_RIGHT:
            if(player2.getX() != width - 3)
                player2.setX(player2.getX() + 1);
            break;
        case 'w':
            if(player1.getY() != 3)
                player1.setY(player1.getY() - 1);
            break;
        case 's':
            if(player1.getY() != height - 4)
                player1.setY(player1.getY() + 1);
            break;
        case 'a':
            if(player1.getX() != 2)
                player1.setX(player1.getX() - 1);
            break;
        case 'd':
            if(player1.getX() != width / 2 - 4)
                player1.setX(player1.getX() + 1);
            break;
        case ' ':
            if(player1Serve) {
                player1Serve = false;
                dir = 1;
            }
            else if(player2Serve) {
                player2Serve = false;
                dir = 2;
            }
            break;
    }

};