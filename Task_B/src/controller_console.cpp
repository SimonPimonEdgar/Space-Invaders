#include "controller_console.h"

ConsoleController::ConsoleController(PongModel* model) {
	this->model = model;
};

wchar_t ConsoleController::getInput() {
    // TODO B.2 Direct the input key towards the model:
    // call the appropriate function of the model.
    wchar_t ch = getch();
    
    return ch;
};
