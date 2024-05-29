#include "view_terminal.h"

// Constructor implementation
ViewTerminal::ViewTerminal(ChatBotModel& modelRef, ChatBotController& controllerRef) : model(modelRef), controller(controllerRef) {
    model.addObserver(this);  // Registering this view as an observer to the model
}

// TODO 1: The View is the point of interaction with the user and 
// we move the main / control loop into this run method. 
// Refactor your code again ...
// Function to start the interaction loop
// Interaction loop for the terminal view
void ViewTerminal::run() {
    std::string input;
    std::cout << "Welcome to the n-gram Chat Bot. Type 'generate' to create a sentence, or 'exit' to quit." << std::endl;

    while (true) {
        ...
        break;
        ...
    }
}

//TODO 2 a): Implement the update function - how to display to the user in the view
// the change.
// Afterwards = TODO 2 b): In the model class (the Observable) add the notifyUpdate to trigger
//      this update using the observer mechanism.
// Implementation of the update method from Observer
void ViewTerminal::update() {
    // Output the latest data from the model
    std::cout << "Model updated. Current word: " << TODO GET CURRENT STATE OF MODEL << std::endl;
}