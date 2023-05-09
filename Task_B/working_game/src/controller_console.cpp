#include "controller_console.h"

ConsoleController::ConsoleController(PongModel* model) {
	this->model = model;
};

wchar_t ConsoleController::getInput() {
    wchar_t ch = getch();
    model->control_players(ch);
    return ch;
};
