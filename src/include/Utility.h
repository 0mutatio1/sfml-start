//
// Created by stone on 2024-07-04.
//

#ifndef UTILITY_H
#define UTILITY_H

#include <sstream>

#include "SFML/Graphics/Sprite.hpp"

namespace sf {
    class Sprite;
    class Text;
}

template <typename T>
std::string toString(const T& value);

void centerOrigin(sf::Sprite& sprite);
void centerOrigin(sf::Text& text);

template <typename T>
std::string toString(const T& value) {
    std::stringstream stream;
    stream << value;
    return stream.str();
}



#endif //UTILITY_H
