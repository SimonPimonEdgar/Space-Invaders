#ifndef MODEL_NGRAM_CHATBOT_H_ // header guard to prevent multiple inclusions of the same header file
#define MODEL_NGRAM_CHATBOT_H_

#include <string>
#include <cstring>
#include <map>
#include <random>
#include <vector>

/**
 * TODO
 * - refactor your code from Task A (the part for counting bigrams, ngram_bot) into this model;
 *      you can reuse your (or the example) solutions from count_ngram
 * - introduce a state into the model = what is the current word?
 *      plus access functions
 */

// Define the ChatBotModel class
class ChatBotModel {
public:
    ChatBotModel(); // constructor

    // Function provided that is using the read and the old count functions.
    void loadTextAndComputeBigrams(const std::string& filename);

    // TODO 1: Access functions for current word:
    std::string getCurrentWord();
    void setCurrentWord(const std::string& new_word);

    // TODO 2: Build a function that is generating a single next word for
    // the current set word
    // Further - introduce this method in the methods below ...
    // std::string generateNextWord();

    // Method to get a sentence completion for a given start word
    std::string getSentenceCompletion(const std::string& start_word);

    // Generate a sentence completion using the internal current word
    std::string generateSentence();

private:
    // Random number utilities
    std::random_device rd;
    std::mt19937 gen;

    // n-gram data storage
    std::map<std::string, std::map<std::string, int>> count_ngram;

    // TODO 1: Current word state
    WHICH_TYPE? currentWord;

    // Private methods for internal utility (taken from old task A)
    std::string sampleFromMapOfProbabilities(const std::map<std::string, int>& probabilities);
    std::string returnMostProbableMapEntry(const std::map<std::string, int>& prob_map);

    // Utility to check delimiters
    bool isDelimiterOrStopChar(char ch);
};

#endif // MODEL_NGRAM_CHATBOT_H_
