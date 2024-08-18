#include <boost/test/tools/old/interface.hpp>
#define BOOST_TEST_MODULE MyTest
#include <boost/test/included/unit_test.hpp>

#include "model_simulator_game.h"

BOOST_AUTO_TEST_SUITE(AddOneTest);

BOOST_AUTO_TEST_CASE(TestCases)
{
    GameModel* game = new GameModel();
    BOOST_CHECK_EQUAL(game->addOne(20), 21); 
    
    
    Alien* alien = new Alien(1, 1, 1);
    BOOST_CHECK_EQUAL(alien->getX(), 1);
    alien->setX(2);
    BOOST_CHECK_EQUAL(alien->getX(), 2);
    alien->setDead(false);
    BOOST_CHECK_EQUAL(alien, false);


    Player* player = new Player(2, 2);
    BOOST_CHECK_EQUAL(player->getX(), 2);
    player->setX(5);
    BOOST_CHECK_EQUAL(player, 5);
    player->setY(10);
    BOOST_CHECK_EQUAL(player->getY(), 10);
}

BOOST_AUTO_TEST_SUITE_END()