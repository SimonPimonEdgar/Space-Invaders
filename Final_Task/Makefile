CXX	:= c++
CXXFLAGS := -Wall -std=c++20

# Contain path for any includes (headers)
# Depending on your platform: Include a path to boost, on linux should be 
# /usr/local/include, on mac could be /opt/homebrew/include
INCLUDES := -I./include

# Contains libraries we need to (-L is directory search path, -l is lib)
LDFLAGS = -L/usr/local/lib
LDLIBS = -lncurses -lboost_unit_test_framework

SRCDIR := ./src
BREAKOUT_OBJECTS := controller_console.o model_simulator_breakout.o observer.o view_console.o

breakout: $(BREAKOUT_OBJECTS) main.o
	$(CXX) $^ -o $@ $(LDFLAGS) $(LDLIBS)

tests: $(BREAKOUT_OBJECTS) test_call.o
	$(CXX) $^ -o $@ $(LDFLAGS) $(LDLIBS)
    
%.o: $(SRCDIR)/%.cpp
	$(CXX) $(INCLUDES) $(CXXFLAGS) -c $^ -o $@

clean:
	test ! -f breakout || rm breakout
	test ! -f tests || rm tests
	rm *.o