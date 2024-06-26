maze: main.cpp Labyrinth.cpp MazeGenerator.cpp
	c++ -Wall -std=c++20 main.cpp Labyrinth.cpp MazeGenerator.cpp -o main

test_maze: test_maze.cpp
	c++ -Wall -std=c++20 -I/opt/homebrew/include -L/opt/homebrew/lib -lboost_unit_test_framework test_maze.cpp Labyrinth.cpp MazeGenerator.cpp -o test_maze


clean:
	test ! -f main || rm main
	test ! -f test_maze || rm test_maze