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

    // The View is the point of interaction with the user and 
    // we move the main loop into this run method. 
    void run();

    virtual void update() override;
};

#endif // VIEW_TERMINAL_H_