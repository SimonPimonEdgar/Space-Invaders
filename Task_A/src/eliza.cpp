#include <iostream>
#include <time.h>
#include <vector>
#include <map>

#include "ELIZA/eliza.h"

#include "chat_bot.h"

elizascript::script s;
std::stringstream ss(elizascript::CACM_1966_01_DOCTOR_script);
elizascript::eliza_script_reader<std::stringstream> reader(ss, s);
elizalogic::eliza eliza(s.rules, s.mem_rule);

void giveWelcomeMessage()
{
  writeln(join(s.hello_message));
  std::cout << std::endl;
}

std::string askChatBotForAnswer( const std::string& userInput )
{
  return eliza.response(userInput);
}


