#include <iostream>
#include <string>
#include <random>

#include "chat_bot.h"
#include "read_file.h"

const int PREDICT_LENGTH = 10;

// This function takes a map of strings and probabilities and returns a randomly chosen string
std::string sampleFromMapOfProbabilities(const std::map<std::string, int>& probabilities) {
    // Create a random number generator
    std::random_device rd;
    std::mt19937 gen(rd());

    // Create a distribution based on the probabilities
    std::vector<int> weights;
    std::vector<std::string> choices;
    for (const auto& pair : probabilities) {
        choices.push_back(pair.first);
        weights.push_back(pair.second);
    }
    std::discrete_distribution<> dist(weights.begin(), weights.end());

    // Randomly choose a key from the map and return it
    return choices[dist(gen)];
}

// This function takes a map of strings and probabilities and 
// returns the string with the highest probability.
std::string returnMostProbableMapEntry( const std::map<std::string, int>& prob_map ) {
  std::string max_ngram;
  int max_count;
  for (auto& it : prob_map) {
    if (it.second > max_count) {
      max_count = it.second;
      max_ngram = it.first;
    }
  }
  std::cout << "MOST PROBABLE NEXT WORD: " << std::string(max_ngram) << std::endl;
  return std::string(max_ngram);
}


void giveWelcomeMessage()
{
  std::cout << "Welcome to the n-gram Bot. You start a sentence and I will finish it ... " << std::endl;
}

std::string askChatBotForAnswer( const std::map<std::string, std::map<std::string, int>>& count_ngram, const std::string& userInput ) {
  std::string currentToken;
  for (auto &ch : userInput) {
    if (!isDelimiterOrStopChar(ch)) {
      currentToken += ch;
    }
  }
  std::string returnSentence;
  for (int i=0; i < PREDICT_LENGTH; i++) {
    auto iter = count_ngram.find( currentToken );
    if (iter == count_ngram.end()) {
      std::cout << "Word was not present in training data: " << userInput << std::endl;
      return "NO TEXT GENERATED";
    } else {
      //return returnMostProbableMapEntry( iter->second );
      currentToken = sampleFromMapOfProbabilities( iter->second );
    }
    returnSentence += currentToken + ' ';
  }
  return returnSentence;
}


