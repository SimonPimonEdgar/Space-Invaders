#include "model_ngram_chatbot.h"
#include "control_chatbot.h"
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

    // Load the text and compute the bigrams
    model.loadTextAndComputeBigrams(input_file);  // Load and prepare the model

    // Controller is instantiated with a reference to the model
    ChatBotController controller(model);

    // Run the view which starts the interaction loop
    controller.run();
    return 0;
}
