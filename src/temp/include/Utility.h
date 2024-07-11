//
// Created by stone on 2024-07-04.
//

#ifndef UTILITY_H
#define UTILITY_H

#include <sstream>

#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Window/Keyboard.hpp"

namespace sf {
    class Sprite;
    class Text;
}

template <typename T>
std::string toString(const T& value);

std::string toString(sf::Keyboard::Key key);

void centerOrigin(sf::Sprite& sprite);
void centerOrigin(sf::Text& text);


float toDegree(float radian);
float toRadian(float degree);

int randomInt(int exclusiveMax);
float length(sf::Vector2f vector);
sf::Vector2f unitVector(sf::Vector2f vector);



template <typename T>
std::string toString(const T& value) {
    std::stringstream stream;
    stream << value;
    return stream.str();
}




#endif //UTILITY_H
