CXX	:= c++
CXXFLAGS := -Wall -std=c++20

# Contain path for any includes (headers)
# Depending on your platform: Include a path to boost, on linux should be 
# /usr/local/include, on mac could be /opt/homebrew/include
INCLUDES := -I./include -I/opt/homebrew/include

# Contains libraries we need to (-L is directory search path, -l is lib)
LDFLAGS = -L/usr/local/lib -L/opt/homebrew/lib
LDLIBS = -lcurl -lssl -lcrypto

SRCDIR := ./src
ELIZA_OBJECTS := eliza.o main_chatbot.o

NGRAM_OBS = read_file.o count_ngram.o main_ngram.o

NGRAMBOT_OBS = read_file.o count_ngram.o ngram_bot.o main_ngrambot.o

CHATGPT_OBS = chatgpt_bot.o main_chatbot.o

TELEGRAM_OBS = main_telegram.o

eliza: $(ELIZA_OBJECTS)
	$(CXX) $^ -o $@

ngramcount: $(NGRAM_OBS)
	$(CXX) $^ -o $@ 

ngrambot: $(NGRAMBOT_OBS)
	$(CXX) $^ -o $@

chatgpt: $(CHATGPT_OBS)
	$(CXX) $^ -o $@ -lcurl

telegram: $(TELEGRAM_OBS)
	$(CXX) $^ -o $@ $(LDFLAGS) $(LDLIBS)
    
%.o: $(SRCDIR)/%.cpp
	$(CXX) $(INCLUDES) $(CXXFLAGS) -c $^ -o $@

clean:
	rm *.o eliza ngramcount ngrambot chatgpt telegram
