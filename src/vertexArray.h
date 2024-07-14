
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/Transform.hpp>

void customVertexArray() {
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
        sf::VertexArray triangle(sf::Triangles, 3);
        triangle[0].position = sf::Vector2f(10.f, 10.f);
        triangle[1].position = sf::Vector2f(300.f, 10.f);
        triangle[2].position = sf::Vector2f(300.f, 300.f);

        // define the color of the triangle's points
        triangle[0].color = sf::Color::Red;
        triangle[1].color = sf::Color::Blue;
        triangle[2].color = sf::Color::Green;
        window.draw(triangle);

        // end the current frame
        window.display();
    }
}