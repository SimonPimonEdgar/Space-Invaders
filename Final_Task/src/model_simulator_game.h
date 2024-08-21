#ifndef MODEL_GAME_H_ // header guard to prevent multiple inclusions of the same header file
#define MODEL_GAME_H_

#include "observer.h" // include header file for the Observable class
#include <cstddef>
#include "cover.h"
#include "player.h"
#include "alien.h"
#include "powerUp.h"
#include "shot.h"
#include <vector>

class GameModel : public Observable { // Game class inherits from Observable class
public:
    GameModel(); // constructor

    int getGameWidth(); // returns the game's width
    int getGameHeight(); // returns the game's height
    Player& getPlayer(); // returns reference to player object
    std::vector<Alien>& getAliens(); // returns reference to alien objects
    std::vector<Cover>& getCovers(); // returns reference to cover objects
    std::vector<Shot>& getShots();   // returns reference to shot objects
    bool getIngame(); // returns the games's status

    void simulate_game_step(); // simulates one step of the game
    void control_player(wchar_t ch); // updates player movement direction based on keyboard input

    int addOne(int input_value); // Example function - used for simple unit tests

private:
    int width = 40; // game width
    int height = 24; // game height
    int alienTimer = 0;
    bool alienDir = false; //direction of the aliens (false = right, true = left)
    int playerShotTimer = 0;
    bool inGame = false; // bool wether or not a level is aktive
    int wave = 0;
    Player player; // player object
    std::vector<Alien> aliens; // alien objects
    std::vector<Cover> covers; // cover objects
    std::vector<Shot> shots; //shot objects
    void moveAliens(); //support method for simulate_game_step to update the position of aliens
    void waveCreation(int wave); // support method for simulate_game_step to create a new level
    bool gameDone(); // support method for simlulate_game_step to update wether the game is done
    void eraser(); //support method for simulate_game_step to erase inactive objects
    void moveShots(); //support method for simulate_game_step to update the position of shots
    void aliensShoot(); // support method for simulate_game_step to creat alien shots
    std::vector<Alien> filterBottom(); // support method for aliensShoot to filter the aliens
    void collision(); // support method for simulate_game_step to add colision
    bool reachedBorder(); // support method for moveAliens()
    void calcScore(Alien alien); // support method for collision to calculate the score
    void levelFinished(); // support method for simulate_game_step to look wether the level is done
};

#endif // end of header file
