
#include <SFML/System/Time.hpp>
#include <SFML/System/Clock.hpp>
#include <iostream>
#include <SFML/System/Sleep.hpp>

void timeit() {
	sf::Clock clock;
	std::cout << "==============" << std::endl;

	sf::sleep(sf::milliseconds(1000));
	sf::Time elapsed = clock.getElapsedTime();
	std::cout << elapsed.asSeconds() << std::endl;
	
	clock.restart();
	sf::sleep(sf::milliseconds(1000));
	sf::Time elapsed2 = clock.getElapsedTime();
	std::cout << elapsed2.asSeconds() << std::endl;
}