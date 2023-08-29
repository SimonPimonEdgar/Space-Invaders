#include "model_simulator_breakout.h"
#include <ncurses.h>
#include <stdlib.h>

BreakoutModel::BreakoutModel() {
};

// Example function - used for simple unit tests
int BreakoutModel::addOne(int input_value) {
    return (++input_value); 
};

int BreakoutModel::getGameWidth() {
    return width; 
};
    
int BreakoutModel::getGameHeight() {
    return height; 
};
    

void BreakoutModel::simulate_game_step()
{
    // Implement game dynamics.
    notifyUpdate();
};