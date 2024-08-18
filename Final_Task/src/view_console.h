#pragma once  // #pragma once directive added to avoid multiple inclusions of header files

#include "observer.h"  // Include Observer header file
#include "model_simulator_game.h"  // Include GameModel header file
#include <ncurses.h>

class ConsoleView : public Observer  // Inheriting from Observer class
{
    GameModel* model;  // Pointer variable of GameModel class

public:
    ConsoleView(GameModel* model);  // Constructor of ConsoleView class

    virtual ~ConsoleView();  // Virtual destructor of ConsoleView class

    void update();  // Function to update the screen

    void drawPlayer(int y, int x);  // Function to draw the player

    void drawAliens();

private:
    // Textures
    char wallTexture = 'X';  // Wall texture character
    char alienTexture1 = 'A';
    char alienTexture2 = 'B';
    char alienTexture3 = 'C';

    void setup_view();  // Function to set up the view
};
