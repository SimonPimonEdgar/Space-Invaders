#include "control_chatbot.h"
#include "model_ngram_chatbot.h"

int main() {
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

    // Specify the filename
    std::string filename = "data/sample.txt";

    // Load the text and compute the bigrams
    model.loadTextAndComputeBigrams(filename);  // Load and prepare the model

    // Controller is instantiated with a reference to the model
    ChatBotController controller(model);
    controller.run();  // Run the chatbot interaction
    return 0;
}
