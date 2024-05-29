#include <string>
#include <vector>
#include <map>

std::map<std::string,int> count1gramFromText( const std::vector<std::string> full_text );

// ToDo: What should be the type of this function?
std::map<std::pair<std::string,std::string>,int> countBiGramFromText( const std::vector<std::string> full_text );
std::map<std::string,std::map<std::string,int>> countBiGramNestedMapFromText( const std::vector<std::string> full_text );

std::string findMax1gram (const std::map<std::string,int>& count_Ngram);
int getCountFor1gram(const std::map<std::string, int>& count_Ngram, const std::string& str);
//void printMaxNgram (std::map<std::string,std::map<std::string,int>>& count_Ngram);
//std::string returnProbableNextWordInBiGram (std::map<std::string,std::map<std::string,int>>& count_Ngram, std::string start_word);