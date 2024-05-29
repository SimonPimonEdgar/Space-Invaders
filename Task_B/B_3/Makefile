CXX	:= c++
CXXFLAGS := -Wall -std=c++20

# Contain path for any includes (headers)
# Depending on your platform: Include a path to boost, on linux should be 
# /usr/local/include, on mac could be /opt/homebrew/include
INCLUDES := -I./include 

# Contains libraries we need to (-L is directory search path, -l is lib)
LDFLAGS = -L/usr/local/lib 
LDLIBS = #-lncurses

SRCDIR := ./src
BUILDDIR := ./build

CHATBOT_OBJECTS := $(addprefix $(BUILDDIR)/,main_ngram.o observer.o model_ngram_chatbot.o view_terminal.o read_file.o count_ngram.o control_chatbot.o)

# Target executable for the chatbot
chatbot: $(CHATBOT_OBJECTS)
	$(CXX) $(LDFLAGS) $^ -o $@ $(LDLIBS)
    
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(BUILDDIR)
	$(CXX) $(INCLUDES) $(CXXFLAGS) -c $< -o $@


clean:
	rm -rf $(BUILDDIR) chatbot