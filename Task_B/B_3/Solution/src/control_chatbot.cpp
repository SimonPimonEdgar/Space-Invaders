// control_chatbot.cpp
#include "control_chatbot.h"
#include <iostream>

// Constructor implementation
ChatBotController::ChatBotController(ChatBotModel& modelRef) : model(modelRef) {}

// Control loop is now driven by main window / terminal. Controller is therefore
// quite simple.
// Interaction loop implementation
void ChatBotController::processCommand(const std::string& command) {
    if (command.empty()) {  // No input means generate the next word
        std::string nextWord = model.generateNextWord();
        std::cout << "Next Word: " << nextWord << std::endl;
        if (nextWord == "NO TEXT GENERATED") {
            std::cout << "No further text can be generated." << std::endl;
        }
    } else {
        std::string completion = model.getSentenceCompletion(command);
        std::cout << "Completion: " << completion << std::endl;
    }
}