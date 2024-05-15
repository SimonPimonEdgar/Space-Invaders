#include "chat_bot.h"

#include <openai/openai.hpp>

void giveWelcomeMessage()
{
  // GPT Anfrage
  // export OPENAI_API_KEY='sk- ... for OPENAI calls: export in shell
  openai::start();
  std::cout << "Welcome to ChatGPT. How can I help you (this message will be passed to ChatGPT)?" << std::endl;
}

std::string askChatBotForAnswer( const std::string& userInput ) {
  // TODO: ADAPT THE FOLLOWING CODE - the call to OpenAI is already given.

  // You create a query object (there are other possibilies)
  // You access this object and can set an entry for the Json object as query["key"] = "value"; 
  openai::Json query;
  
  // You have to fill the "model" entry, e.g. as "gpt-3.5-turbo"
  // and the "max_tokens" with a number of allowed tokens for the answer as an int, plus the "temperature" as an int
  // The messages has to be a complex openai::Json::array that has two tupels as entries
  // - one for "role" which is "user"
  // - one for "content" which is the userInput
  query["model"] = "gpt-3.5-turbo";  // Model name
  // TODO
  
  auto completion = openai::completion().create(query);

  // ToDo: Get the response from the JSON object completion.

  return completion.dump(2);
}


