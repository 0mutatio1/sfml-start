
#include <SFML/Graphics/Shader.hpp>

#include <iostream>

void shaderit() {
	if (!sf::Shader::isAvailable())
	{
		std::cout << " shader not available " << std::endl;
	}
	else {
		std::cout << " shader available " << std::endl;
	}
}