#include "view_console.h"
#include "model_simulator_game.h"
#include <charconv>
#include <ncurses.h>
#include <stdlib.h>
#include <string>


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
    if(model->getStatus() == Status::ingame)
    {
        // Show lifes of player
        mvaddch(1, (int) ((2* model->getGameWidth() / 3 ) +1), 'L');
        mvaddch(1, (int) ((2* model->getGameWidth() / 3 ) +2), ':');
        mvprintw(1, (int) (2 * model->getGameWidth() / 3 +3),"%i", model->getPlayer().getLifes());

        // Show points of player
        mvaddch(1, (int) ((model->getGameWidth() / 2 / 2) - 2), 'P');
        mvaddch(1, (int) ((model->getGameWidth() / 2 / 2) - 1), ':');
        mvprintw(1, model->getGameWidth() / 2 / 2, "%i", model->getPlayer().getScore());

        // Draw different objects. 
        drawPlayer(model->getPlayer().getY(), model->getPlayer().getX());
        drawAliens();
        drawCover();
        drawShots();
        drawPowerUp();
        }

    if(model->getStatus() == Status::titlescreen)
    {
        if(model->getWave() < 3)
        {
            if(model->getWave() > 0 )
            { 
                if(model->getPlayer().getLifes() > 0)
                {
                    mvprintw(model->getGameHeight()/2 - 4, (model->getGameWidth()-30)/2 , "You have completed the level!");
                    std::string message = "Your score is:" + std::to_string(model->getPlayer().getScore()) + " Points";
                    mvprintw(model->getGameHeight()/2 - 3, (model->getGameWidth()-30)/2 , "%s", message.c_str());
                    mvprintw(model->getGameHeight()/2, (model->getGameWidth()-20)/2 , "Press 1 to continue");
                }
                else
                {
                    mvprintw(model->getGameHeight()/2 - 4, (model->getGameWidth()-10)/2 , "You died.");
                    std::string message = "Your score was:" + std::to_string(model->getPlayer().getScore()) + " Points";
                    mvprintw(model->getGameHeight()/2 - 3, (model->getGameWidth()-30)/2 , "%s", message.c_str());
                    mvprintw(model->getGameHeight()/2, (model->getGameWidth()-19)/2 , "Press 1 to restart");
                } 
            }
            else mvprintw(model->getGameHeight()/2, (model->getGameWidth()-17)/2 , "Press 1 to start");
        }
        else {

            if(model->getPlayer().getLifes() > 0) 
            {
                mvprintw(model->getGameHeight()/2 - 4, (model->getGameWidth()-28)/2 , "You have finished the game!");
                std::string message = "Your score is: " + std::to_string(model->getPlayer().getScore())+ " Points";
                mvprintw(model->getGameHeight()/2 - 3, (model->getGameWidth()-30)/2 , "%s", message.c_str());
            }
            else 
            {
                mvprintw(model->getGameHeight()/2 - 4, (model->getGameWidth()-10)/2 , "You died.");
                std::string message = "Your score is: " + std::to_string(model->getPlayer().getScore())+ " Points";
                mvprintw(model->getGameHeight()/2 - 3, (model->getGameWidth()-30)/2 , "%s", message.c_str());
            }
            mvprintw(model->getGameHeight()/2, (model->getGameWidth()-19)/2 , "Press 1 to restart");
        }
        mvprintw(model->getGameHeight()/2 + 2, (model->getGameWidth()-31)/2 , "Press 2 to change the settings");
    }

    if(model->getStatus() == Status::settings)
    {
        if(model->getCurrent() == Controll::none)
        {
        mvprintw(model->getGameHeight()/2 - 5, (model->getGameWidth()-36)/2 , "Press 1 to change: Upwards Movement");
        //mvprintw(model->getGameHeight()/2 - 10, (model->getGameWidth()-25)/2 , "Up ist %c", model->getUp());
        mvprintw(model->getGameHeight()/2 - 3, (model->getGameWidth()-38)/2 , "Press 2 to change: Downwards Movement");
        //mvprintw(model->getGameHeight()/2 - 6, (model->getGameWidth()-25)/2 , "%s", message.c_str());
        mvprintw(model->getGameHeight()/2 - 1, (model->getGameWidth()-33)/2 , "Press 3 to change: Left Movement");
        //mvprintw(model->getGameHeight()/2 - 2, (model->getGameWidth()-25)/2 , "%s", message.c_str());
        mvprintw(model->getGameHeight()/2 + 1, (model->getGameWidth()-34)/2 , "Press 4 to change: Right Movement");
        //mvprintw(model->getGameHeight()/2 + 2, (model->getGameWidth()-25)/2 , "%s", message.c_str());
        mvprintw(model->getGameHeight()/2 + 3, (model->getGameWidth()-28)/2 , "Press 5 to change: Shooting");
        //mvprintw(model->getGameHeight()/2 + 6, (model->getGameWidth()-25)/2 , "%s", message.c_str());
        mvprintw(model->getGameHeight()/2 + 5, (model->getGameWidth()-33)/2 , "Press 6 to return to titlescreen");;
        }
        else mvprintw(model->getGameHeight()/2, (model->getGameWidth()-21)/2 , "Press the wished key");
    }
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
    mvaddch(y, x, 'M');
};

void ConsoleView::drawAliens() 
{
    for(Alien& alien : model->getAliens())
    {
        if(alien.getVar() == AlienVar::Normal) mvaddch(alien.getY(), alien.getX(), alienTexture1);
        else if(alien.getVar() == AlienVar::Tank) mvaddch(alien.getY(), alien.getX(), alienTexture2);
        else if(alien.getVar() == AlienVar::Elite) mvaddch(alien.getY(), alien.getX(), alienTexture3);

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
    }
};

void ConsoleView::drawShots()
{
    for(Shot& s: model->getShots())
    {
        mvaddch(s.getY(), s.getX(), 'I');
    }
};

void ConsoleView::drawPowerUp()
{
    for(PowerUp& p: model->getPowerUp())
    {
        mvaddch(p.getY(), p.getX(), 'H');
    }
};