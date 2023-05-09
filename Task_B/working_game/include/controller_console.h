#ifndef CONTROLLER_PONG_H_ // header guard to prevent multiple includes
#define CONTROLLER_PONG_H_

#include "model_simulator_pong.h" // include the Pong Model header file
#include <ncurses.h> // include the ncurses library for console input/output

class Controller
{
public:
    virtual wchar_t getInput() = 0; // declare a pure virtual function for getting user input
};

class ConsoleController : public Controller // derive ConsoleController class from the Controller base class
{
    PongModel* model; // pointer to the PongModel object

public:
    ConsoleController(PongModel* model); // constructor that takes a PongModel pointer as parameter

    wchar_t getInput(); // override the getInput() function to get input from the console
};

#endif  // end of header guard
