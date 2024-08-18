#ifndef MODEL_GAME_H_ // header guard to prevent multiple inclusions of the same header file
#define MODEL_GAME_H_

#include "observer.h" // include header file for the Observable class
#include <cstddef>

class Player {
public:
    Player(int x, int y); // constructor that takes in initial x and y coordinates of player
    int getX();
    int getY();
    int getLifes();
    void setX(int a);
    void setY(int a);
    void setLifes(int a);
private:
    int x, y, height; // player's coordinates and height
    int lifes = 3; // player's lifes
};

class Alien {
public:
    Alien(int var, int x, int y); // constructor that takes in the variant and the initial x and y coordinates of the alien
    int getVar();
    int getX();
    int getY();
    int getH();
    bool getDead();
    void setX(int a);
    void setY(int a);
    void setDead(bool a);

private:
    int x, y; // coordinates of the alien
    bool dead = false; // bool wether or not the alien got hit
    int var; // variant of the alien
};


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

enum class PowerUpVar{one};

class PowerUp{
public:
    PowerUp(int x, int y, PowerUpVar var); // constructor that takes in the variant and the initial x and y coordinates of the power up
    int getX();
    int getY();
    int getVar();
    void setX();
    void setY();

private:
    int x, y; // coordinates of the power up
    PowerUpVar var; // Variant of the power up
};

class GameModel : public Observable { // Game class inherits from Observable class
public:
    GameModel(int wave); // constructor

    int getGameWidth(); // returns the game's width
    int getGameHeight(); // returns the game's height
    Player& getPlayer(); // returns reference to player object
    Alien& getAliens(int index); //return reference to one aliens object
    
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
    void moveAliens(); //support method for simulate_game_step
    void waveCreation();
    bool hasWon();
};

#endif // end of header file
