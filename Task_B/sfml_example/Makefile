CXX := c++
CXXFLAGS := -Wall -std=c++20

# Contain path for any includes (headers)
# Depending on your platform: Include a path to boost, on linux should be 
# /usr/local/include, on mac could be /opt/homebrew/include
INCLUDES := -I./include -I./SFML/include -I/opt/homebrew/include

# Contains libraries we need to (-L is directory search path, -l is lib)
LDFLAGS := -L/usr/local/lib -L./SFML/lib -L/opt/homebrew/lib
LDLIBS := -lsfml-system -lsfml-window -lsfml-graphics

SRCDIR := ./src
BUILDDIR := ./build

GFX_OBJECTS := $(addprefix $(BUILDDIR)/,main.o)

# Target executable for the sfml example
sfml_test: $(GFX_OBJECTS)
	$(CXX) $(LDFLAGS) $^ -o $@ $(LDLIBS)

# make all other obj files
%.o: $(SRCDIR)/%.cc $(INCLUDEDIR)/%.hpp
	$(CXX) $(INCLUDES) $(CXXFLAGS) -c $< -o $@

# On a Mac: "brew install sfml" will install the library.
getSFML:
	@echo "Downloading SFML"
	curl https://www.sfml-dev.org/files/SFML-2.6.0-linux-gcc-64-bit.tar.gz --output SFML.tar.gz
	@echo "Unpacking the lib"
	tar -xf SFML.tar.gz
	@echo "Removing download"
	rm SFML.tar.gz
	@echo "Renaming folder"
	mv SFML-2.6.0 SFML
	@echo "Finished!"
    
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(BUILDDIR)
	$(CXX) $(INCLUDES) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILDDIR) sfml_test
