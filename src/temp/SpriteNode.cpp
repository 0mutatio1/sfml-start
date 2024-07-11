//
// Created by stone on 2024-06-25.
//

#include "include/SpriteNode.h"

#include <../../cmake-build-debug/_deps/sfml-src/include/SFML/Graphics/RenderTarget.hpp>

SpriteNode::SpriteNode(const sf::Texture &texture)
    : mSprite(texture)
{

}

SpriteNode::SpriteNode(const sf::Texture &texture, const sf::IntRect &textureRect)
    : mSprite(texture, textureRect)
{

}

void SpriteNode::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(mSprite, states);
}


