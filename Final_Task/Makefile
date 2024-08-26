CXX	:= c++
CXXFLAGS := -Wall -std=c++20

# Contain path for any includes (headers)
# Depending on your platform: Include a path to boost, on linux should be 
# /usr/local/include, on mac could be /opt/homebrew/include
INCLUDES := -I/home/shemkent/projects/Space-Invaders/Final_Task/include -I/opt/homebrew/include 

# Contains libraries we need to (-L is directory search path, -l is lib)
LDFLAGS = -L/usr/local/lib -L/opt/homebrew/lib
LDLIBS = -lncurses -lboost_unit_test_framework

SRCDIR := /home/shemkent/projects/Space-Invaders/Final_Task/src
GAME_OBJECTS := controller_console.o model_simulator_game.o observer.o view_console.o alien.o cover.o player.o shot.o powerUp.o 

game: $(GAME_OBJECTS) main.o
	$(CXX) $^ -o $@ $(LDFLAGS) $(LDLIBS)

tests: $(GAME_OBJECTS) test_call.o
	$(CXX) $^ -o $@ $(LDFLAGS) $(LDLIBS)
    
%.o: $(SRCDIR)/%.cpp
	$(CXX) $(INCLUDES) $(CXXFLAGS) -c $^ -o $@

controller_console.o: /home/shemkent/projects/Space-Invaders/Final_Task/src/controller_console.cpp
	$(CXX) $(INCLUDES) $(CXXFLAGS) -c $^ -o $@

clean:
	test ! -f game || rm game
	test ! -f tests || rm tests
	rm *.o