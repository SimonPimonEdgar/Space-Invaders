// control_chatbot.cpp
#include "control_chatbot.h"
#include <iostream>

// Constructor implementation (standard, gets access to the model)
ChatBotController::ChatBotController(ChatBotModel& modelRef) : model(modelRef) {}

// Controller is running in a loop
void ChatBotController::run() {
    std::string input;
    std::cout << "Welcome to the n-gram Chat Bot. Type a word to start a sentence, or 'exit' to quit." << std::endl;
    std::string completion;

    while (true) {
        // TODO:
        // Implement interaction with user
        // Control has to take input from the user
        // - and as we haven't introduced a view up until now,
        //   it also directly provides feedback on the terminal
        // TODOs:
        // - get input from user, e.g. getline
        // - get from model either a complete sentence or only next word
        // - exit when called with "exit" = break;
        ...
        break; // Exits the loop and potentially the program
        ...
    }
}