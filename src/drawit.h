

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

void drawit() {

    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        sf::Font font;
        font.loadFromFile("E:/sfml-start/src/SOURCECODEPRO-LIGHT.OTF");
        sf::Text text;
        text.setFont(font);
        text.setString("Hello SFML");
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::Red);
        text.setStyle(sf::Text::Bold | sf::Text::Underlined);
        window.draw(text);
        
        // end the current frame
        window.display();
    }

}
