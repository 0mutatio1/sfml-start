
#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>


void viewit() {
    // create the window
    sf::RenderWindow window(sf::VideoMode(1024, 756), "My window");
    sf::View view(sf::FloatRect(0.f, 0.f, 1000.f, 600.f));

    window.setView(view);
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
        view.move(1.f, 1.f);

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        sf::Texture texture;
        if (!texture.loadFromFile("E:/sfml-start/src/minimap.png"))
        {

        }
        sf::Sprite sprite;
        sprite.setTexture(texture);
        window.draw(sprite);
        window.setView(view);
        // end the current frame
        window.display();
    }
}