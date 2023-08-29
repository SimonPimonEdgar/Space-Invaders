#define BOOST_TEST_MODULE MyTest
#include <boost/test/included/unit_test.hpp>

#include "model_simulator_breakout.h"

BOOST_AUTO_TEST_SUITE(AddOneTest);

BOOST_AUTO_TEST_CASE(TestCases)
{
    BreakoutModel* breakout = new BreakoutModel();
    BOOST_CHECK_EQUAL(breakout->addOne(20), 21); 
}

BOOST_AUTO_TEST_SUITE_END()