//
// Created by stone on 2024-07-09.
//

#include "include/TextNode.h"

#include "include/Utility.h"
#include <../../cmake-build-debug/_deps/sfml-src/include/SFML/Graphics/RenderTarget.hpp>

TextNode::TextNode(const FontHolder &fonts, const std::string &text)
{
    mText.setFont(fonts.get(Fonts::Main));
    mText.setCharacterSize(20);
    setString(text);
}

void TextNode::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(mText, states);
}

void TextNode::setString(const std::string &text) {
    mText.setString(text);
    centerOrigin(mText);
}


