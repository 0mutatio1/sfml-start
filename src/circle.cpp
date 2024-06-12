#include <SFML/Graphics.hpp>

int circle()
{
    auto window = sf::RenderWindow{ { 800u, 600u }, "SFML Start" };
    // window.setFramerateLimit(144);
    sf::CircleShape shape;
    shape.setRadius(40.f);
    shape.setPosition(100.f, 100.f);
    shape.setFillColor(sf::Color::Cyan);
    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            window.clear();
            window.draw(shape);
            window.display();
        }
    }
    return 0;
}
