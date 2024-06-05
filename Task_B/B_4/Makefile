CXX	:= c++
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

CHATBOT_OBJECTS := $(addprefix $(BUILDDIR)/,main_ngram.o observer.o model_ngram_chatbot.o view_terminal.o read_file.o count_ngram.o control_chatbot.o)

# Target executable for the chatbot
chatbot: $(CHATBOT_OBJECTS)
	$(CXX) $(LDFLAGS) $^ -o $@ $(LDLIBS)
    
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(BUILDDIR)
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

clean:
	rm -rf $(BUILDDIR) chatbot