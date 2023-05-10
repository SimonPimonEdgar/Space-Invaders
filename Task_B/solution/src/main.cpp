#include <ncurses.h>
#include <stdlib.h>
#include <iostream>

#include "model_simulator_pong.h"
#include "view_console.h"
#include "controller_console.h"

int main() {
    PongModel* pong = new PongModel();
    ConsoleView* view = new ConsoleView(pong);
    ConsoleController* controller = new ConsoleController(pong);
    //std::cout << pong->getBallPosition() << std::endl;
    wchar_t ch = '\0';
    while(ch != 'q') {
        ch = controller->getInput();
        pong->simulate_game_step();
    }
    delete pong;
    delete view;
    return 0;
}