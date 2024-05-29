// control_chatbot.cpp
#include "control_chatbot.h"
#include <iostream>

// Constructor implementation
ChatBotController::ChatBotController(ChatBotModel& modelRef) : model(modelRef) {}

// Interaction loop implementation
void ChatBotController::run() {
    std::string input;
    std::cout << "Welcome to the n-gram Chat Bot. Type a word to start a sentence, or 'exit' to quit." << std::endl;
    std::string completion;

    while (true) {
        std::cout << "> ";
        std::getline(std::cin, input);
        if (input == "exit") {
            break; // Exits the loop and potentially the program
        } else if (input.empty()) {
            completion = model.generateNextWord(); // Get next word when no input provided.
        } else {
            completion = model.getSentenceCompletion(input); // Get full sentence completion for provided input
        }
        std::cout << "Completion: " << completion << std::endl;
    }
}