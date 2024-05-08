#include <iostream>

#include "read_file.h"
#include "count_ngram.h"

#include "chat_bot.h"

#include <map>
#include <random>

int main(int argc, const char* argv[])
{
  /* Parsing input arguments for main method:
   * Required:
   *  --input   Input file in which the n-grams shall be counted
   */
  // Provide help on how to call main.
  if (argc < 3) {
    std::cerr << "Usage: " << argv[0] << " --input InputFile" << std::endl;
      return 1;
  }
  // Setting up the variables.
  std::string input_file;
  // Parsing the arguments.
  for (int i = 1; i < argc; ++i) {
    std::string argument = argv[i];
    // Parsing for input file.
    if (std::string(argv[i]) == "--input") {
      if (i + 1 < argc) { // Make sure we aren't at the end of argv!
        input_file = argv[++i]; // Increment 'i' so we don't get the argument as the next argv[i].
      } else { // There was no argument to the input file option.
        std::cerr << "--input option requires one argument." << std::endl;
        return 1;
      }
    }
  }

  // Read text from file into a vector of strings (remove punctuation).
  std::vector<std::string> full_text = readTextFromFile( input_file );

  // Count unigrams in the given text.
  auto count_1gram = count1gramFromText( full_text );
  // Count Bigrams in the given text.
  auto count_2gram = countBiGramNestedMapFromText( full_text );

  // Start ChatBot Part:
  // Call Welcome Method and afterwards go to main loop.
  giveWelcomeMessage();
  std::string userInput;
  // The user will provide a prompt.
  // For the n-gram bot this is the beginning of a statement
  // which will be continued for k words as a response.
  // The userInput has to be preprocessed in the same way as the text file.
  do {
    std::getline(std::cin, userInput);
    //std::string botAnswer = askChatBotForAnswer( count_1gram, userInput );
    std::string botAnswer2 = askChatBotForAnswer( count_2gram, userInput );
    std::cout << botAnswer2 << std::endl << std::endl;
  } while (userInput != "");

  return 0;
}


