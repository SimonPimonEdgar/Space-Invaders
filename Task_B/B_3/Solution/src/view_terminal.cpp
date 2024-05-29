#include "view_terminal.h"

// Constructor implementation
ViewTerminal::ViewTerminal(ChatBotModel& modelRef, ChatBotController& controllerRef) : model(modelRef), controller(controllerRef) {
    model.addObserver(this);  // Registering this view as an observer to the model
}

// Implementation of the update method from Observer
void ViewTerminal::update() {
    // Output the latest data from the model
    std::cout << "Model updated. Current word: " << model.getCurrentWord() << std::endl;
}

// Interaction loop for the terminal view
void ViewTerminal::run() {
    std::string input;
    std::cout << "Welcome to the n-gram Chat Bot. Type 'generate' to create a sentence, or 'exit' to quit." << std::endl;

    while (true) {
        std::cout << "> ";
        std::getline(std::cin, input);
        if (input == "exit") {
            break;
        }
        else {
        //if (input.empty()) {
            controller.processCommand(input);  // Pass the command to the controller for processing
        }
        /**else {
            std::cout << "Unknown command. Please type 'generate' or 'exit'." << std::endl;
        }*/
    }
}
