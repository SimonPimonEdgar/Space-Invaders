#include "model_simulator_pong.h"
#include <ncurses.h>
#include <stdlib.h>

// TODO B.3: Build a common class for any object in the scene.
// - What should be the common function?
// - Derive Player and Ball from this class.

Player::Player(int y, int x)
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
    
int Player::getHeight() {
    return height;
};

void Player::setX(int a) {
    x = a;
};

void Player::setY(int a) {
    y = a;
};

Ball::Ball(double y, double x, int speed)
{
    setY(y);
    setX(x);
    setSpeed(speed);
};

double Ball::getX() { 
    return x; 
};

double Ball::getY() { 
    return y; 
};

int Ball::getSpeed() { 
    return speed; 
};
    
void Ball::setX(double a) {
    x = a;
};

void Ball::setY(double a) {
    y = a;
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

    // TODO: B.4 Introduce a logic for the left player
    // How would you implement this?
    // Hint: You also have to adapt the control_players function.

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
    notifyUpdate();
};

void PongModel::control_players(wchar_t ch)
{
    // TODO B.3: There are controls missing for going down
    // and to the left.
    // Hint: You can see the logic for checking the player position
    // for player1 below.
    switch(ch) {
        case KEY_UP:
            if(player2.getY() != 3)
                player2.setY(player2.getY() - 1);
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