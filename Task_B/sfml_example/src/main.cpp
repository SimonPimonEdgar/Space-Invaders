#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    // Create main window
    sf::RenderWindow window(sf::VideoMode(400, 300), "SFML Example");

    // Load the font
    sf::Font font;
    if (!font.loadFromFile("fonts/DejaVuSansMono.ttf")) {  // Make sure the font file is in the correct path
        std::cerr << "Error loading font" << std::endl;
        return 1;
    }

    // Create a text object that asks the user for input
    sf::Text promptText("Give some input:", font, 20);
    promptText.setPosition(50, 20);
    promptText.setFillColor(sf::Color::Black);

    // Create a text object for the input field below - this has to be updated later!
    sf::Text inputText("", font, 20);
    inputText.setPosition(50, 60);
    inputText.setFillColor(sf::Color::Black);

    // Create a rectangle for the input field (to show that this is an area for user input)
    sf::RectangleShape inputField(sf::Vector2f(300, 30));
    inputField.setPosition(50, 60);
    inputField.setFillColor(sf::Color(200, 200, 200));  // Light gray

    // Create Exit Button
    sf::RectangleShape exitButton(sf::Vector2f(100, 50));
    exitButton.setPosition(250, 200);
    exitButton.setFillColor(sf::Color(128, 128, 128));  // Medium gray
    sf::Text exitButtonText("Exit", font, 20);
    exitButtonText.setPosition(270, 210);
    exitButtonText.setFillColor(sf::Color::White);

    sf::String userInput;

    // Main processing loop - checking for events
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Handle button clicks
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2f mousePos = sf::Vector2f(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y));

                    if (exitButton.getGlobalBounds().contains(mousePos)) {
                        window.close();  // Exit program
                    }
                }
            }

            // Handle text input
            if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode == '\b') { // Handle backspace
                    if (!userInput.isEmpty()) {
                        userInput.erase(userInput.getSize() - 1);
                    }
                } else if (event.text.unicode == '\r' || event.text.unicode == '\n') { // Handle return key
                    std::cout << userInput.toAnsiString() << std::endl;
                    userInput.clear();
                } else if (event.text.unicode < 128) { // Ensure valid ASCII input
                    userInput += event.text.unicode;
                }
                inputText.setString(userInput);
            }
        }

        window.clear(sf::Color::White);
        window.draw(promptText);
        window.draw(inputField);
        window.draw(inputText);
        window.draw(exitButton);
        window.draw(exitButtonText);
        window.display();
    }

    return 0;
}
