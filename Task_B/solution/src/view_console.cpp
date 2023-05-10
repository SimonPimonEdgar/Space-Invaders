#include "view_console.h"
#include <ncurses.h>
#include <stdlib.h>


ConsoleView::ConsoleView(PongModel* model) {
	setup_view();
	this->model = model;
	this->model->addObserver(this);
};

ConsoleView::~ConsoleView() {
    endwin();
};

void ConsoleView::drawPlayer(int y, int x) {
    mvaddch(y + 2, x, '|');
    mvaddch(y + 1, x, '|');
    mvaddch(y, x, '|');
    mvaddch(y - 1, x, '|');
    mvaddch(y - 2, x, '|');
};

void ConsoleView::drawBall(double x, double y) {
    mvaddch(x, y, 'o');
};

void ConsoleView::update() {
    erase();
    refresh();
    for(int i = 0; i < model->getGameWidth(); i++) {
        mvaddch(0, i, wallTexture);
        mvaddch(model->getGameHeight() - 1, i, wallTexture);
    }

    for(int i = 1; i < model->getGameHeight() - 1; i++)
        mvaddch(i, model->getGameWidth() / 2, ':');

    mvprintw(1, model->getGameWidth() / 2 / 2, "%i", model->getPlayer1Points());
    mvprintw(1, model->getGameWidth() / 2 + model->getGameWidth() / 2 / 2, "%i", model->getPlayer2Points());

    drawBall(model->getBall().getY(), model->getBall().getX());
    drawPlayer(model->getPlayer1().getY(), model->getPlayer1().getX());
    drawPlayer(model->getPlayer2().getY(), model->getPlayer2().getX());
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