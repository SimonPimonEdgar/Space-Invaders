#include <iostream>
#include <string>
#include <random>
// Need include for data structure!

// Implements chat_bot.h
#include "chat_bot.h"
// You should preprocess the user input in the same way as in the file ...
#include "read_file.h"

const int PREDICT_LENGTH = 10;

// Implementation of the interface of a chatbot.
void giveWelcomeMessage()
{
  std::cout << "Welcome to the n-gram Bot. You start a sentence and I will finish it ... " << std::endl;
}

// This function takes a map of strings and probabilities and 
// returns the string with the highest probability.
std::string returnMostProbableMapEntry( const YOUR_DATA_STRUCT& probabilities ) {
  std::string max_ngram;
  // Find the entry with highest probability (or count).
  return std::string(max_ngram);
}

// This function takes a map of strings and probabilities and returns a randomly chosen string
std::string sampleFromNGramProbabilities(const YOUR_DATA_STRUCT& probabilities) {
  // Create a random number generator
  std::random_device rd;
  std::mt19937 gen(rd());

  // You will have to build up a representation that is easy to sample
  // and somehow relates to the entries.
  return std::string("42");
}

// Call to produce answer - i.e. a sequence of #PREDICT_LENGTH words
std::string askChatBotForAnswer( const YOUR_DATA_STRUCT& probabilities, const std::string& userInput ) {
  std::string currentToken, returnSentence;
  // Take last word from user input; 
  // preprocess the word (analog as in read_file);
  // Iterate over: Predict next word / sample next word;
  // Return sentence.
  return returnSentence;
}