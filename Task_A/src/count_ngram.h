#include <string>
#include <vector>
//#include <tbd_type>

tbd_type count1gramFromText( const std::vector<std::string> full_text );

// ToDo: What should be the type of this function?
//tbd_type_2 countBiGramFromText( const std::vector<std::string> full_text );

// You also might want to go for trigrams.

// Access functions:
// Return the word with the highest count
std::string findMax1gram (const tbd_type& count_Ngram);
// Get a count for a string.
int getCountFor1gram(const tbd_type& count_Ngram, const std::string& str);

// Implement similar functions for bigrams and trigrams.

//void printMaxNgram (std::map<std::string,std::map<std::string,int>>& count_Ngram);
//std::string returnProbableNextWordInBiGram (std::map<std::string,std::map<std::string,int>>& count_Ngram, std::string start_word);