#define BOOST_TEST_MODULE boost_test_sequence_per_element
#include <boost/test/included/unit_test.hpp>

#include "MazeGenerator.h"
#include "Labyrinth.h"
#include <iostream>
#include <string>

/* Change this constant to contain your name.
 *
 * WARNING: Once you've set set this constant and started exploring your maze,
 * do NOT edit the value of kYourName. Changing kYourName will change which
 * maze you get back, which might invalidate all your hard work!
 */
const std::string kYourName = "TODO: Replace this string with your name.";

/* Change these constants to contain the paths out of your mazes. */
const std::string kPathOutOfNormalMaze = "SESSWENNENSESS"; //TODO: Replace this string with your path out of the normal maze.";
const std::string kPathOutOfTwistyMaze = "ESWEESWENE"; //TODO: Replace this string with your path out of the twisty maze.";

BOOST_AUTO_TEST_CASE( test_maze )
{
    /* Generate the maze.
     */
    MazeCell* startLocation = mazeFor(kYourName);
    BOOST_TEST( isPathToFreedom(startLocation, kPathOutOfNormalMaze) );    

    /* Generate the twisty maze.
     */
    MazeCell* twistyStartLocation = twistyMazeFor(kYourName);
    
    BOOST_TEST(isPathToFreedom(twistyStartLocation, kPathOutOfTwistyMaze));

}
