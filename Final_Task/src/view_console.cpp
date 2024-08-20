#include "view_console.h"
#include "model_simulator_game.h"
#include <ncurses.h>
#include <stdlib.h>
#include <vector>


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
    drawCover();
    drawShots();
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
    for(Alien& alien : model->getAliens())
    {
        mvaddch(alien.getY()-1, alien.getX(), alienTexture1);
    }
};

void ConsoleView::drawCover()
{
    for(Cover& cover : model->getCovers())
    {
        int x,y;
        x = cover.getX();
        y = cover.getY();
       mvaddch(y, x, coverTexture);
       mvaddch(y, x + 1, coverTexture);
       mvaddch(y, x + 2, coverTexture);
       mvaddch(y, x + 3, coverTexture);
    }
};

void ConsoleView::drawShots()
{
    for(Shot& s: model->getShots())
    {
        mvaddch(s.getY(), s.getX(), 'I');
    }
};