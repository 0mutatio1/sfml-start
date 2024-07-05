//
// Created by stone on 2024-07-04.
//

#include "include/PauseState.h"
#include "include/Utility.h"
#include "include/ResourceHolder.h"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>

PauseState::PauseState(StateStack &stack, Context context)
    : State(stack, context)
    , mBackgroundSprite()
    , mPauseText()
    , mInstructionText()
{
    sf::Font& font = context.fonts->get(Fonts::Main);
    sf::Vector2f viewSize = context.window->getView().getSize();

    mPauseText.setFont(font);
    mPauseText.setString("Game Paused");
    mPauseText.setCharacterSize(70);
    centerOrigin(mPauseText);

    mInstructionText.setFont(font);
    mInstructionText.setString("(Press Backspace to return to the main menu)");
    centerOrigin(mInstructionText);
    mInstructionText.setPosition(0.5f * viewSize.x, 0.6f * viewSize.y);
}


void PauseState::draw() {
    sf::RenderWindow& window = *getContext().window;
    window.setView(window.getDefaultView());

    sf::RectangleShape backgroundShape;
    backgroundShape.setFillColor((sf::Color(0, 0, 0, 150)));
    backgroundShape.setSize(window.getView().getSize());
    window.draw(backgroundShape);
    window.draw(mPauseText);
    window.draw(mInstructionText);
}

bool PauseState::update(sf::Time dt) {
    return false;
}

bool PauseState::handleEvent(const sf::Event &event) {
    if (event.type != sf::Event::KeyPressed) {
        return false;
    }
    if (event.key.code == sf::Keyboard::Escape) {
        requestStackPop();
    }
    if (event.key.code == sf::Keyboard::Backspace) {
        requestStateClear();
        requestStackPush(States::Menu);
    }
    return false;
}



















