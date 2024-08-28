#include <boost/test/tools/old/interface.hpp>
#define BOOST_TEST_MODULE MyTest
#include <boost/test/included/unit_test.hpp>

#include "model_simulator_game.h"
#include "alien.h"
#include "player.h"

BOOST_AUTO_TEST_SUITE(AddOneTest);

BOOST_AUTO_TEST_CASE(TestCases)
{
    GameModel* game = new GameModel();
    BOOST_CHECK_EQUAL(game->getPlayer().getLifes(), 3);
    BOOST_CHECK_EQUAL(game->getShots().empty(), true);
    game->control_player(game->getShoot());
    BOOST_CHECK_EQUAL(game->getShots().empty(), false);
    BOOST_CHECK_EQUAL(game->getStatus(), Status::titlescreen);
    
    Alien* alien = new Alien(AlienVar::Tank, 1, 1);
    BOOST_CHECK_EQUAL(alien->getX(), 1);
    alien->setX(2);
    BOOST_CHECK_EQUAL(alien->getX(), 2);
    alien->setLifes(alien->getLifes()-1);
    BOOST_CHECK_EQUAL(alien->getLifes(), 1);

    Player* player = new Player(2, 2);
    BOOST_CHECK_EQUAL(player->getX(), 2);
    player->setX(5);
    BOOST_CHECK_EQUAL(player->getX(), 5);
    player->setY(10);
    BOOST_CHECK_EQUAL(player->getY(), 10);

    Cover* cover = new Cover(1, 1);
    BOOST_CHECK_EQUAL(cover->getX(), 1);
    cover->setLifes(2);
    BOOST_CHECK_EQUAL(cover->getLifes(), 2);
    cover->setX(2);
    BOOST_CHECK_EQUAL(cover->getX(), 2);

    PowerUp* power = new PowerUp(1, 1, PowerUpVar::health);
    BOOST_CHECK_EQUAL(power->getVar(), PowerUpVar::health);
    power->setActive(false);
    BOOST_CHECK_EQUAL(power->getActive(), false);
    power->setX(2);
    BOOST_CHECK_EQUAL(power->getX(), 2);

    Shot* shot = new Shot(1, 1, false);
    BOOST_CHECK_EQUAL(shot->getDir(), false);
    shot->setActive(false);
    BOOST_CHECK_EQUAL(shot->getActive(), false);
    shot->setX(2);
    BOOST_CHECK_EQUAL(shot->getX(), 2);

}

BOOST_AUTO_TEST_SUITE_END()