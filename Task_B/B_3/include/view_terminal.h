#ifndef VIEW_TERMINAL_H_
#define VIEW_TERMINAL_H_

#include "observer.h"
#include "model_ngram_chatbot.h"
#include "control_chatbot.h" 
#include <iostream>
#include <string>

// Simple view class for realizing the view in the terminal.
// You should first have looked at the observer and observable mechanism (observer.h).
// The View is realizing a receiver for updates. This means it will get notified 
// that something changed in the model (when notifyUpdate has been added in the model)
// - but only that something changed.
// The View has to implement what to do with this and how to represent this:
// - the update function is automatically triggered and inside it
//      the change has to be handled.
class ViewTerminal : public Observer {
private:
    ChatBotModel& model;  // Reference to the model to observe and interact with
    ChatBotController& controller; // Reference to the controller to delegate commands

public:
    // Constructor requires a reference to the model
    ViewTerminal(ChatBotModel& modelRef, ChatBotController& controllerRef);

    // TODO 1: The View is the point of interaction with the user and 
    // we move the main loop into this run method. 
    // Refactor your code again ...
    // Function to start the interaction loop
    void run();

    //TODO 2 a): Implement the update function - how to display to the user in the view
    // the change.
    // TODO 2 b): In the model class (the Observable) add the notifyUpdate to trigger
    //      this update using the observer mechanism.
    // Overriding the update function from Observer
    virtual void update() override;
};

#endif // VIEW_TERMINAL_H_