#ifndef MODEL_NGRAM_CHATBOT_H_ // header guard to prevent multiple inclusions of the same header file
#define MODEL_NGRAM_CHATBOT_H_

#include <string>
#include <cstring>
#include <map>
#include <random>
#include <vector>

// Define the ChatBotModel class
class ChatBotModel {
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
