#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    auto window = sf::RenderWindow{ { 800u, 600u }, "SFML Start" };
    window.setFramerateLimit(144);

    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.scancode == sf::Keyboard::Scan::Escape)
                {
                    std::cout << "the escape key was pressed" << std::endl;
                    std::cout << "scancode: " << event.key.scancode << std::endl;
                    std::cout << "code: " << event.key.code << std::endl;
                    std::cout << "control: " << event.key.control << std::endl;
                    std::cout << "alt: " << event.key.alt << std::endl;
                    std::cout << "shift: " << event.key.shift << std::endl;
                    std::cout << "system: " << event.key.system << std::endl;
                    std::cout << "description: " << sf::Keyboard::getDescription(event.key.scancode).toAnsiString() << std::endl;
                    std::cout << "localize: " << sf::Keyboard::localize(event.key.scancode) << std::endl;
                    std::cout << "delocalize: " << sf::Keyboard::delocalize(event.key.code) << std::endl;
                }
            }
            if (event.type == sf::Event::Resized)
            {
                std::cout << "new width: " << event.size.width << std::endl;
                std::cout << "new height: " << event.size.height << std::endl;
            }
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Right)
                {
                    std::cout << "the right button was pressed" << std::endl;
                    std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                    std::cout << "mouse y: " << event.mouseButton.y << std::endl;
                }
            }
        }

        window.clear();
        window.display();
    }
}
