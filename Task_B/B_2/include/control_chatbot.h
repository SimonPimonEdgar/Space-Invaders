// control_chatbot.h
#ifndef CONTROL_CHATBOT_H
#define CONTROL_CHATBOT_H

#include "model_ngram_chatbot.h"
#include <string>

/*
 * The Controller class can operate on the model class
 * Therefore, it requires access = needs a reference.
 */
class ChatBotController {
private:
    ChatBotModel& model;  // Reference to the chatbot model

public:
    // Constructor accepts a reference to an existing model
    ChatBotController(ChatBotModel& modelRef);

    // TODO:
    // Run the chatbot interaction loop
    // You have to refactor the loop from main into this part of the program.
    // Currently, the controller is not handling much else - it should take input from the user
    // and should 
    // - either generate a single next word
    // - or a full sentence when a new start word is given
    void run();
};

#endif // CONTROL_CHATBOT_H
