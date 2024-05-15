#include "chat_bot.h"

#include <openai/openai.hpp>

void giveWelcomeMessage()
{
  // GPT Anfrage
  // export OPENAI_API_KEY='sk- ... for OPENAI calls: export in shell
  openai::start();
  std::cout << "Welcome to ChatGPT. How can I help you (this message will be passed to ChatGPT?" << std::endl;
}

std::string askChatBotForAnswer( const std::string& userInput ) {
  openai::Json query; /** = R"({
        "model": "text-davinci-003",
        "prompt": "userInput",
        "max_tokens": 7,
        "temperature": 0
  })";*/
  
  query["model"] = "gpt-3.5-turbo";  // Model name
  query["messages"] = openai::Json::array({
      {{"role", "user"}, {"content", userInput}}  // Message array with user input
  });
  query["max_tokens"] = 100;  // Maximum number of tokens to generate
  query["temperature"] = 0; 

  //std::cout << querry << std::endl;
  auto completion = openai::completion().create(query);
  /*auto completion = openai::completion().create(R"({
        "model": "text-davinci-003",
        "prompt": "Say this is a test",
        "max_tokens": 7,
        "temperature": 0
  })"_json); // Using user-defined (raw) string literals*/
  std::cout << "Response is:\n" << completion.dump(2) << '\n';

  return completion["choices"][0]["message"]["content"];
}


