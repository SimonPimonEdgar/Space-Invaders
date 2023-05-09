#pragma once  // #pragma once directive added to avoid multiple inclusions of header files

#include "observer.h"  // Include Observer header file
#include "model_simulator_pong.h"  // Include PongModel header file
#include <ncurses.h>

class ConsoleView : public Observer  // Inheriting from Observer class
{
    PongModel* model;  // Pointer variable of PongModel class

public:
    ConsoleView(PongModel* model);  // Constructor of ConsoleView class

    virtual ~ConsoleView();  // Virtual destructor of ConsoleView class

    void drawPlayer(int y, int x);  // Function to draw the player

    void drawBall(double x, double y);  // Function to draw the ball

    void update();  // Function to update the screen

private:
    // Textures
    char wallTexture = '=';  // Wall texture character

    void setup_view();  // Function to set up the view
};
