#ifndef MODEL_PONG_H_ // header guard to prevent multiple inclusions of the same header file
#define MODEL_PONG_H_

#include "observer.h" // include header file for the Observable class

class PongObject {
protected:
    double x, y; // PongObject's coordinates and height

public:
    PongObject(double y, double x); // constructor that takes in initial x and y coordinates of player
    double getX();
    double getY();
    void setX(double a);
    void setY(double a);
};

class Player : public PongObject {
private:
    int height; // player's height

public:
    Player(double y, double x, int height); // constructor that takes in initial x and y coordinates of player
    int getHeight();
};

class Ball : public PongObject {
private:
    int speed; // ball's speed
    
public:
    Ball(double y, double x, int speed); // constructor that takes in initial x and y coordinates of ball and its speed
    int getSpeed();
    void setSpeed(int a);
};

class PongModel : public Observable { // PongModel class inherits from Observable class
public:
    PongModel(); // constructor

    Ball& getBall(); // returns reference to ball object
    Player& getPlayer1(); // returns reference to player 1 object
    Player& getPlayer2(); // returns reference to player 2 object

    int getGameWidth(); // returns the game's width
    int getGameHeight(); // returns the game's height
    int getPlayer1Points(); // returns player 1's points
    int getPlayer2Points(); // returns player 2's points

    void simulate_game_step(); // simulates one step of the Pong game

    void control_players(wchar_t ch); // updates player movement direction based on keyboard input

private:
    int width = 40; // game width
    int height = 16; // game height
    int dir = 1; // ball direction
    int player1Points, player2Points = 0; // player scores
    bool player1Serve, player2Serve = false; // flags for serving
    Player player1, player2; // player objects
    Ball ball; // ball object
};

#endif // end of header file
