#define BOOST_TEST_MODULE MyTest
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(case1)
{
    int i = 0;
    BOOST_TEST(i == 0);
    int j = 1;
    BOOST_TEST(i != j);
}
