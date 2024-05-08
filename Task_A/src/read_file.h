#include <vector>
#include <string>

const char* getDefaultDelimitersAndStopChars();

bool isDelimiterOrStopChar ( char c );

std::vector<std::string> readTextFromFile( std::string fileName );