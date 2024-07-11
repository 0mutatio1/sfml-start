//
// Created by stone on 2024-07-04.
//

#include "include/MenuState.h"
#include "include/Utility.h"
#include "include/ResourceHolder.h"
#include <../../cmake-build-debug/_deps/sfml-src/include/SFML/Graphics/RenderWindow.hpp>
#include <../../cmake-build-debug/_deps/sfml-src/include/SFML/Graphics/View.hpp>

#include "include/Button.h"

MenuState::MenuState(StateStack &stack, Context context)
    : State(stack, context)
    , mGUIContianer()
{
    sf::Texture& texture = context.textures->get(Textures::TitleScreen);
    sf::Font& font = context.fonts->get(Fonts::Main);
    mBackgroundSprite.setTexture(texture);

    auto playButton = std::make_shared<GUI::Button>(*context.fonts, *context.textures);
    playButton->setPosition(100, 250);
    playButton->setText("Play");
    playButton->setCallback([this]() {
        requestStackPop();
        requestStackPush(States::Game);
    });

    auto settingsButton = std::make_shared<GUI::Button>(*context.fonts, *context.textures);
    settingsButton->setPosition(100, 300);
    settingsButton->setText("Settings");
    settingsButton->setCallback([this]() {
        requestStackPush(States::Settings);
    });

    auto exitButton = std::make_shared<GUI::Button>(*context.fonts, *context.textures);
    exitButton->setPosition(100, 350);
    exitButton->setText("Exit");
    exitButton->setCallback([this]() {
        requestStackPop();
    });
    mGUIContianer.pack(playButton);
    mGUIContianer.pack(settingsButton);
    mGUIContianer.pack(exitButton);


}

void MenuState::draw() {
    sf::RenderWindow& window = *getContext().window;
    window.setView(window.getDefaultView());
    window.draw(mBackgroundSprite);
    window.draw(mGUIContianer);
}

bool MenuState::update(sf::Time dt) {
    return true;
}

bool MenuState::handleEvent(const sf::Event &event) {
    mGUIContianer.handleEvent(event);
    return false;
}














