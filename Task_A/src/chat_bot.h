#ifndef CHATBOT_CPP_H
#define CHATBOT_CPP_H

#include <map>
#include <string>

void giveWelcomeMessage();

std::string askChatBotForAnswer( const std::string& userInput );
std::string askChatBotForAnswer ( const std::map< std::string, std::map<std::string,int>>& count_ngram, const std::string& userInput );

#endif // CHATBOT_CPP_H