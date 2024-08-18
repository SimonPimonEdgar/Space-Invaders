#ifndef MODEL_GAME_H_ // header guard to prevent multiple inclusions of the same header file
#define MODEL_GAME_H_

#include "observer.h" // include header file for the Observable class
#include <cstddef>
#include "cover.h"
#include "player.h"
#include "alien.h"
#include "powerUp.h"

class Shot {
public:
    Shot(int x, int y, bool dir); // contructor that takes in the direction and the initial x and y coordinates of the shot
    int getX();
    int getY();
    bool getDir();
    void setX(int a);
    void setY(int a);

private:
    int x, y; // coordinates of the shot
    bool dir; // direction of the shot (Upwards = True, Downwards = False)
};

class GameModel : public Observable { // Game class inherits from Observable class
public:
    GameModel(int wave); // constructor

    int getGameWidth(); // returns the game's width
    int getGameHeight(); // returns the game's height
    Player& getPlayer(); // returns reference to player object
    Alien& getAliens(int index); // returns reference to one aliens object
    Cover& getCovers(int index); // returns reference to one covers object

    void simulate_game_step(); // simulates one step of the game
    void control_player(wchar_t ch); // updates player movement direction based on keyboard input

    int addOne(int input_value); // Example function - used for simple unit tests

private:
    int width = 40; // game width
    int height = 24; // game height
    int dir = 1; // ball direction
    int alienTimer = 0;
    bool alienDir = false; //direction of the aliens (false = right, true = left)
    int playerShotTimer = 0;
    Player player; // player object
    Alien aliens[40] = {Alien(1, 1 ,1), Alien(1,1,1),Alien(1,1,1),Alien(1,1,1),Alien(1,1,1),Alien(1,1,1),Alien(1,1,1),Alien(1,1,1),
        Alien(1,1,1),Alien(1,1,1), Alien(1, 1 ,1), Alien(1,1,1),Alien(1,1,1),Alien(1,1,1),Alien(1,1,1),Alien(1,1,1),Alien(1,1,1),
        Alien(1,1,1),Alien(1,1,1),Alien(1,1,1),Alien(1, 1 ,1), Alien(1,1,1),Alien(1,1,1),Alien(1,1,1),Alien(1,1,1),Alien(1,1,1),
        Alien(1,1,1),Alien(1,1,1),Alien(1,1,1),Alien(1,1,1),Alien(1, 1 ,1), Alien(1,1,1),Alien(1,1,1),Alien(1,1,1),Alien(1,1,1),
        Alien(1,1,1),Alien(1,1,1),Alien(1,1,1),Alien(1,1,1),Alien(1,1,1)}; // alien objects
    Cover covers[3] = {Cover(1, 1), Cover(1, 1), Cover(1, 1)};
    void moveAliens(); //support method for simulate_game_step
    void waveCreation();
    bool hasWon();
};

#endif // end of header file
