
#include <SFML/Window.hpp>

void windowit() {
	sf::Window window(sf::VideoMode(800, 600), "WW", sf::Style::Default);

	window.setPosition(sf::Vector2i(10, 50));

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

	}

}