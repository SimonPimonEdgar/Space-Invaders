#include <iostream>

#include "read_file.h"
#include "count_ngram.h"

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

  // Produce the counts for the n-grams for n=1 to 3.
  auto count_1gram = count1gramFromText( full_text );
  // auto count_2gram = countBiGramFromText( full_text );
  // auto count_3gram = count3GramFromText( full_text );

  // Check for count of specific words and the most counted n-gram.
  std::cout << "Most used word = \"" << findMax1gram(count_1gram) <<
      "\" - count : " << getCountFor1gram( count_1gram, findMax1gram(count_1gram) ) << std::endl;
}
