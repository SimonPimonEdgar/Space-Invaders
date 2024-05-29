#include "model_ngram_chatbot.h"
#include <iostream>
#include <limits>
#include <fstream>
#include <sstream>
#include <vector>
#include "read_file.h"
#include "count_ngram.h"

// Implementing the different methods for the class.

// Constructor for class:
// Initializes the random number generator
ChatBotModel::ChatBotModel() : gen(rd()) {}

// TODO 1:
// Access functions for current word:
WHICH_TYPE? ChatBotModel::getCurrentWord() {
    return ... // TODO
}

void ChatBotModel::setCurrentWord(const std::string& new_word ) {
    // TODO
}

// Refactored from old code.
void ChatBotModel::loadTextAndComputeBigrams(const std::string& filename) {
    // Read text from file and remove punctuation
    std::vector<std::string> full_text = readTextFromFile(filename);
    // Generate bigram counts from text
    count_ngram = countBiGramNestedMapFromText(full_text);
}

// TODO 1: Refactor the code of ngram_bot.cpp into this:
std::string ChatBotModel::sampleFromMapOfProbabilities(const std::map<std::string, int>& probabilities) {
    ...
}

// TODO: Refactor the code of ngram_bot.cpp into this:
std::string ChatBotModel::returnMostProbableMapEntry(const std::map<std::string, int>& prob_map) {
    ...
}

// TODO 1: Refactor the code of ngram_bot.cpp into this:
// Important - there this was handled differently in one function
// = askChatBotForAnswer
// You can start from this function
/** 
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
} */
// and now have to consider how this uses the internal variables.
// a) getSentenceCompletion should simply set the current state 
//    and call the generateSentence function on this
std::string ChatBotModel::getSentenceCompletion(const std::string& start_word) {
    ...
}

// TODO 1:
// b) generate Sentence should deal with the second part of askChatBotForAnswer
//    and iterate in a lopp over producing the next word (by sampling)
std::string ChatBotModel::generateSentence() {
    ...
}


// TODO 2: Implement a function that produces the next word based on the current word.
// Generate the next word based on the current state
// Last: Use this method in the other calls above.
/**std::string ChatBotModel::generateNextWord()
{
    if (count_ngram.find(currentWord) == count_ngram.end()) {
        return "NO TEXT GENERATED"; // No continuation possible
    }
    currentWord = sampleFromMapOfProbabilities(count_ngram[currentWord]);
    return currentWord;
}*/

// Utility function to determine if a character is a delimiter or a stop character
bool ChatBotModel::isDelimiterOrStopChar(char c) {
	return strchr( getDefaultDelimitersAndStopChars(), c ) != NULL;
    //return ispunct(ch) || isspace(ch);
}