
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/ConvexShape.hpp>
#include <SFML/Window/ContextSettings.hpp>
#include <SFML/Graphics/RenderWindow.hpp>


void shapeit() {


    // create the window
    sf::ContextSettings settings;
    settings.antialiasingLevel = 0;
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML shapes", sf::Style::Default, settings);

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
        sf::Texture texture;

        if (!texture.loadFromFile("E:/sfml-start/src/f22.jpg"))
        {

        }
        // draw everything here...
        sf::CircleShape shape(200.f);
        shape.setPosition(300, 100);
        // shape.setFillColor(sf::Color(100, 250, 50));
        // shape.setOutlineThickness(10.f);
        // shape.setOutlineColor(sf::Color(250, 150, 100));

        shape.setTexture(&texture);

        window.draw(shape);

        // 
        sf::RectangleShape rectangle(sf::Vector2f(120.f, 50.f));
        rectangle.setPosition(10, 10);
        rectangle.setFillColor(sf::Color(100, 250, 50));
        window.draw(rectangle);
        //
        sf::CircleShape triangle(80.f, 3);
        triangle.setPosition(10, 80);
        triangle.setFillColor(sf::Color(100, 250, 50));
        window.draw(triangle);
        sf::CircleShape square(80.f, 4);
        square.setPosition(10, 210);
        square.setFillColor(sf::Color(100, 250, 50));
        window.draw(square);
        sf::CircleShape octagon(80.f, 8);
        octagon.setPosition(10, 400);
        octagon.setFillColor(sf::Color(100, 250, 50));
        window.draw(octagon);

        //

        sf::ConvexShape convex;
        convex.setPosition(150, 10);
        convex.setPointCount(5);
        convex.setPoint(0, sf::Vector2f(0.f, 0.f));
        convex.setPoint(1, sf::Vector2f(150.f, 10.f));
        convex.setPoint(2, sf::Vector2f(120.f, 90.f));
        convex.setPoint(3, sf::Vector2f(30.f, 100.f));
        convex.setPoint(4, sf::Vector2f(0.f, 50.f));
        convex.setFillColor(sf::Color(100, 250, 50));
        window.draw(convex);

        //
        sf::RectangleShape line(sf::Vector2f(150.f, 5.f));
        line.setPosition(320, 10);
        line.rotate(15.f);
        window.draw(line);

        sf::Vertex points[] = {
            sf::Vertex(sf::Vector2f(380.f, 10.f)),
            sf::Vertex(sf::Vector2f(390.f, 100.f))
        };
        window.draw(points, 2, sf::Lines);



        //

        // end the current frame
        window.display();
    }
}