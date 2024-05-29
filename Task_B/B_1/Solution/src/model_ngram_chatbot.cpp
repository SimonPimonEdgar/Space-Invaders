#include "model_ngram_chatbot.h"
#include <iostream>
#include <limits>
#include <fstream>
#include <sstream>
#include <vector>
#include "read_file.h"
#include "count_ngram.h"

// Constructor initializes the random number generator
ChatBotModel::ChatBotModel() : gen(rd()) {}

void ChatBotModel::loadTextAndComputeBigrams(const std::string& filename) {
    // Read text from file and remove punctuation
    std::vector<std::string> full_text = readTextFromFile(filename);
    // Generate bigram counts from text
    count_ngram = countBiGramNestedMapFromText(full_text);
}

// Initialize the chatbot with preloaded n-gram data
void ChatBotModel::initialize(const std::map<std::string, std::map<std::string, int>>& ngram_data) {
    count_ngram = ngram_data;
}

std::string ChatBotModel::getSentenceCompletion(const std::string& start_word) {
    currentWord = start_word;
    return generateSentence();
}

std::string ChatBotModel::getCurrentWord() {
    return currentWord;
}

void ChatBotModel::setCurrentWord(const std::string& new_word ) {
    currentWord = new_word;
}

// Generate the next word based on the current state
std::string ChatBotModel::generateNextWord()
{
    if (count_ngram.find(currentWord) == count_ngram.end()) {
        return "NO TEXT GENERATED"; // No continuation possible
    }
    currentWord = sampleFromMapOfProbabilities(count_ngram[currentWord]);
    return currentWord;
}

std::string ChatBotModel::generateSentence() {
    std::string returnSentence;
    std::string nextWord;
    for (int i = 0; i < 10; i++) {
        nextWord = generateNextWord();  // Get the next word using the existing function
        if (nextWord == "NO TEXT GENERATED") {
            return returnSentence.empty() ? "NO TEXT GENERATED" : returnSentence;  // Return what we have if no more text can be generated
        }
        returnSentence += nextWord + ' ';  // Add the generated word to the sentence
    }
    return returnSentence;
}

std::string ChatBotModel::sampleFromMapOfProbabilities(const std::map<std::string, int>& probabilities) {
    std::vector<int> weights;
    std::vector<std::string> choices;
    for (const auto& pair : probabilities) {
        choices.push_back(pair.first);
        weights.push_back(pair.second);
    }
    std::discrete_distribution<> dist(weights.begin(), weights.end());
    return choices[dist(gen)];
}

std::string ChatBotModel::returnMostProbableMapEntry(const std::map<std::string, int>& prob_map) {
    std::string max_ngram;
    int max_count = std::numeric_limits<int>::min();
    for (const auto& it : prob_map) {
        if (it.second > max_count) {
            max_count = it.second;
            max_ngram = it.first;
        }
    }
    return max_ngram;
}

// Utility function to determine if a character is a delimiter or a stop character
bool ChatBotModel::isDelimiterOrStopChar(char c) {
	return strchr( getDefaultDelimitersAndStopChars(), c ) != NULL;
    //return ispunct(ch) || isspace(ch);
}