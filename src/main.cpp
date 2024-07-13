
#include <SFML/System/Time.hpp>
#include <SFML/System/Clock.hpp>

#include <SFML/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>


#include <iostream>

void timeit() {
	sf::Clock clock;
	sf::Time elapsed = clock.getElapsedTime();
	std::cout << elapsed.asSeconds() << std::endl;
	clock.restart();
	sf::Time elapsed2 = clock.getElapsedTime();
	std::cout << elapsed2.asSeconds() << std::endl;
}

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "XX", sf::Style::Default);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		// draw
		sf::Text text;
		text.setString("Hello World");
		text.setCharacterSize(24);
		text.setFillColor(sf::Color::Red);
		text.setStyle(sf::Text::Bold | sf::Text::Underlined);
		window.draw(text);
		//
		sf::CircleShape shape(50.f);
		shape.setFillColor(sf::Color(150, 50, 250));
		shape.setOutlineThickness(10.f);
		shape.setOutlineColor(sf::Color(250, 150, 100));
		window.draw(shape);
		//
		//
		// define a 120x50 rectangle
		sf::RectangleShape rectangle(sf::Vector2f(120.f, 50.f));
		// change the size to 100x100
		rectangle.setSize(sf::Vector2f(100.f, 100.f));
		window.draw(rectangle);

		// define a triangle
		sf::CircleShape triangle(80.f, 3);

		// define a square
		sf::CircleShape square(80.f, 4);

		// define an octagon
		sf::CircleShape octagon(80.f, 8);
		window.draw(triangle);
		window.draw(square);
		window.draw(octagon);
		window.display();
	}
	return 0;
}