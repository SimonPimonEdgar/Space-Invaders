#include "control_chatbot.h"
#include "view_terminal.h"
#include "model_ngram_chatbot.h"
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    /* Parsing input arguments for main method:
     * Required:
     *  --input   Input file in which the n-grams shall be counted
     */
    // Provide help on how to call main.
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " --input InputFile" << std::endl;
        return 1;
    }
    
    std::string input_file;
    // Parsing the arguments.
    for (int i = 1; i < argc; ++i) {
        std::string argument = argv[i];
        // Parsing for input file.
        if (argument == "--input") {
            if (i + 1 < argc) { // Make sure we aren't at the end of argv!
                input_file = argv[++i]; // Increment 'i' so we don't get the argument as the next argv[i].
            } else { // There was no argument to the input file option.
                std::cerr << "--input option requires one argument." << std::endl;
                return 1;
            }
        }
    }

    // Check if input file was set
    if (input_file.empty()) {
        std::cerr << "Error: Input file must be specified." << std::endl;
        std::cerr << "Usage: " << argv[0] << " --input InputFile" << std::endl;
        return 1;
    }

    // Create an instance of the ChatBotModel
    ChatBotModel model;

    /**
    // Example n-gram data
    std::map<std::string, std::map<std::string, int>> ngramData = {
        {"the", {{"cat", 10}, {"dog", 5}, {"bird", 2}}},
        {"cat", {{"sat", 3}, {"sleeps", 5}}},
        {"dog", {{"barks", 7}, {"runs", 3}}},
        {"bird", {{"flies", 2}, {"sings", 3}}},
        {"sat", {{"on", 8}}},
        {"on", {{"the", 8}}},
        {"sleeps", {{"on", 4}, {"under", 1}}},
        {"barks", {{"at", 9}}},
        {"runs", {{"away", 3}}},
        {"flies", {{"away", 2}}},
        {"sings", {{"loudly", 1}}},
        {"away", {{"quickly", 2}}}
    };

    // Initialize the chatbot with the n-gram data
    model.initialize(ngramData);
    */

    // Load the text and compute the bigrams
    model.loadTextAndComputeBigrams(input_file);  // Load and prepare the model

    // Controller is instantiated with a reference to the model
    ChatBotController controller(model);

    // Create the view, passing it the model and the controller
    ViewTerminal view(model, controller);

    // Run the view which starts the interaction loop
    view.run();
    return 0;
}
