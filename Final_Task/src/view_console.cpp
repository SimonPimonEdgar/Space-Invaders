#include "view_console.h"
#include <ncurses.h>
#include <stdlib.h>


ConsoleView::ConsoleView(GameModel* model) {
	setup_view();
	this->model = model;
	this->model->addObserver(this);
};

ConsoleView::~ConsoleView() {
    endwin();
};

void ConsoleView::update() {
    // libncurses standard loop calls
    erase();
    refresh();

    // Example for building the game view
    for(int i = 0; i < model->getGameWidth(); i++) {
        mvaddch(0, i, wallTexture);
        mvaddch(23, i, wallTexture);
    }
    for(int i = 0; i < model->getGameHeight(); i++) {
        mvaddch(i, 0, wallTexture);
        mvaddch(i, model->getGameWidth() - 1, wallTexture);
    }

    // Show lifes of player
    mvaddch(1, (int) ((2* model->getGameWidth() / 3 ) +1), 'L');
    mvaddch(1, (int) ((2* model->getGameWidth() / 3 ) +2), ':');
    mvprintw(1, (int) (2 * model->getGameWidth() / 3 +3),"%i", model->getPlayer().getLifes());

    // Show points of player
    mvaddch(1, (int) ((model->getGameWidth() / 2 / 2) - 2), 'P');
    mvaddch(1, (int) ((model->getGameWidth() / 2 / 2) - 1), ':');
    mvprintw(1, model->getGameWidth() / 2 / 2, "%i", 0);

    // Draw different objects. 
    drawPlayer(model->getPlayer().getY(), model->getPlayer().getX());
    drawAliens();
};

void ConsoleView::setup_view() {
    // Init ncurses
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    timeout(30);
};

void ConsoleView::drawPlayer(int y, int x) {
    mvaddch(y-1, x, 'M');
};

void ConsoleView::drawAliens() 
{
    for(int i = 0; i < 10; i++)
    {
        mvaddch(model->getAliens1(i).getY()-1, model->getAliens1(i).getX(), alienTexture1);
        mvaddch(model->getAliens2(i).getY()-1, model->getAliens1(i).getX(), alienTexture1);
        mvaddch(model->getAliens3(i).getY()-1, model->getAliens1(i).getX(), alienTexture1);
        mvaddch(model->getAliens4(i).getY()-1, model->getAliens1(i).getX(), alienTexture1);
    }
};