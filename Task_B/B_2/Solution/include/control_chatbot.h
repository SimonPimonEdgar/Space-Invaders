// control_chatbot.h
#ifndef CONTROL_CHATBOT_H
#define CONTROL_CHATBOT_H

#include "model_ngram_chatbot.h"
#include <string>

class ChatBotController {
private:
    ChatBotModel& model;  // Reference to the chatbot model

public:
    // Constructor accepts a reference to an existing model
    ChatBotController(ChatBotModel& modelRef);

    // Run the chatbot interaction loop
    void run();
};

#endif // CONTROL_CHATBOT_H
