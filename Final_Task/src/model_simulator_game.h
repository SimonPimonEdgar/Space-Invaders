#ifndef MODEL_GAME_H_ // header guard to prevent multiple inclusions of the same header file
#define MODEL_GAME_H_

#include "observer.h" // include header file for the Observable class

class Player {
public:
    Player(int x, int y); // constructor that takes in initial x and y coordinates of player
    int getX();
    int getY();
    void setX(int a);
    void setY(int a);
private:
    int x, y, height; // player's coordinates and height
};

class Alien {
public:
    Alien(AlienVar var, int x, int y); // constructor that takes in the variant and the initial x and y coordinates of the alien
    AlienVar getVar();
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
    AlienVar var; // variant of the alien
};

enum class AlienVar{1, 2, 3};


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

enum class PowerUpVar{1, 2, 3}; 

class GameModel : public Observable { // Game class inherits from Observable class
public:
    GameModel(); // constructor

    int getGameWidth(); // returns the game's width
    int getGameHeight(); // returns the game's height
    Player& getPlayer(); // returns reference to player object

    void simulate_game_step(); // simulates one step of the game
    void control_player(wchar_t ch); // updates player movement direction based on keyboard input

    int addOne(int input_value); // Example function - used for simple unit tests

private:
    int width = 40; // game width
    int height = 24; // game height
    int dir = 1; // ball direction
    Player player; // player object
    void moveAlien(Alien& alien);

};

#endif // end of header file
