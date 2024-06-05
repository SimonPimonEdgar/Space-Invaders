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

    // The main loop has been moved again - away from the control
    // The current control is in this simple case mostly acting on 
    // the input from the view and filtering what to apply to the model.
    // But control could also deal with more complex tasks,
    // e.g. consider when we not only have a language generating model
    // but also want to use our simple calculator example program. 
    // Control could be tasked with selecting the appropriate model.
    // Method to process commands received from the view
    void processCommand(const std::string& command);
};

#endif // CONTROL_CHATBOT_H
