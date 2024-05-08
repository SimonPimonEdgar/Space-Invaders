#include <iostream>

#include "chat_bot.h"

int main(int argc, const char* argv[])
{
  giveWelcomeMessage();
  std::string userInput;
  do {
    std::getline(std::cin, userInput);
    std::string botAnswer = askChatBotForAnswer( userInput );
    std::cout << botAnswer << std::endl << std::endl;
  } while (userInput != "");
  return 0;
}


