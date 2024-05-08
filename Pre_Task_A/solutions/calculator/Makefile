CXX := c++
CXXFLAGS := -Wall -std=c++20

# Source directory
SRCDIR := ./

# Name of the main target program
TARGET := calculator

# Default target rule
all: $(TARGET)

# Linking the target
$(TARGET): $(SRCDIR)/calculator.o
	$(CXX) $^ -o $@

# Compiling individual object files
%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

# Cleaning build files
clean:
	rm -f *.o $(TARGET)
