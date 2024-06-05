#ifndef MODEL_NGRAM_CHATBOT_H_ // header guard to prevent multiple inclusions of the same header file
#define MODEL_NGRAM_CHATBOT_H_

#include "observer.h"
#include <string>
#include <map>
#include <random>
#include <vector>

// Define the ChatBotModel class
// IMPORTANT: the model is now an Observable
// The observable mechanism is a simple mechanism that establishes a connection between two
// classes and standardizes this relation:
// - on the one hand is the observable class - the model is derived
//      and inherits from this: 
//          - a stack / list of so called observer objects
//          - a notifyUpdate method which informs these observers when something changes
//      Importantly, this notifyUpdate has to be called explicitly inside the Observable class.
// - on the other hand are possible observers. These have to implement an update() function
//      which is called in all connected observers when in the observable class notifyUpdate 
//      has been triggered.
// To summarize: Model is now an Observable. 
// As a consequence, observers can register to this object. 
// The new view will be an observer.
// Inside the model: we have to TODO: add the notifyUpdate function.
// Inside the view as an observer we have to implement an update function that
// defines how to update the view when the model is changed.
//
// Next: 
// - Take a look at observer.h - and at the implementation in observer.cpp
// - Take a look at view_terminal.h
// - Insert notifyUpdate in the model_ngram_chatbot.cpp implementation
// - Implement the view class.
//      
class ChatBotModel : public Observable {
public:
    ChatBotModel(); // constructor

    // Method to initialize the chatbot with n-gram data
    void initialize(const std::map<std::string, std::map<std::string, int>>& ngram_data);

    void loadTextAndComputeBigrams(const std::string& filename);

    std::string getCurrentWord();
    void setCurrentWord(const std::string& new_word);

    // Method to get a sentence completion for a given start word
    std::string getSentenceCompletion(const std::string& start_word);

    // Generate the next word as a completion using the internal current word
    std::string generateNextWord();

    // Generate a sentence completion using the internal current word
    std::string generateSentence();

    // Method to load n-gram data (if loading dynamically)
    void loadNgramData(const std::string& filename);

private:
    // Random number utilities
    std::random_device rd;
    std::mt19937 gen;

    // n-gram data storage
    std::map<std::string, std::map<std::string, int>> count_ngram;

    // Current word state
    std::string currentWord;

    // Private methods for internal utility
    std::string sampleFromMapOfProbabilities(const std::map<std::string, int>& probabilities);
    std::string returnMostProbableMapEntry(const std::map<std::string, int>& prob_map);

    // Utility to check delimiters
    bool isDelimiterOrStopChar(char ch);
};

#endif // MODEL_NGRAM_CHATBOT_H_
