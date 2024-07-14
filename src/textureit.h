
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

void textureit() {

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
        sf::Texture texture;

        if (!texture.loadFromFile("E:/sfml-start/src/f22.jpg"))
        {

        }
        sf::Sprite sprite;
        sprite.setTexture(texture);
        window.draw(sprite);

        // end the current frame
        window.display();
    }



}