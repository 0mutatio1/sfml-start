//
// Created by stone on 2024-07-03.
//

#include "include/Application.h"

#include "include/GameOverState.h"
#include "include/GameState.h"
#include "include/LoadingState.h"
#include "include/MenuState.h"
#include "include/PauseState.h"
#include "include/SettingState.h"
#include "include/StringHelpers.h"
#include "include/TitleState.h"

const sf::Time Application::TimePerFrame = sf::seconds(1.f/60.f);

Application::Application()
    : mWindow(sf::VideoMode(640, 480), "States", sf::Style::Close)
    , mTextures()
    , mFonts()
    , mPlayer()
    , mStateStack(State::Context(mWindow, mTextures, mFonts, mPlayer))
    , mStatisticsText()
    , mStatisticsUpdateTime()
    , mStatisticsNumFrames(0)
{
    mWindow.setKeyRepeatEnabled(false);
    mFonts.load(Fonts::Main, "D:/sfml-start/src/Media/Sansation.ttf");
    // mFonts.load(Fonts::Main, "E:/sfml-start/src/Media/Sansation.ttf");

    mTextures.load(Textures::TitleScreen, "D:/sfml-start/src/Media/TitleScreen.png");
    mTextures.load(Textures::ButtonNormal, "D:/sfml-start/src/Media/ButtonNormal.png");
    mTextures.load(Textures::ButtonSelected, "D:/sfml-start/src/Media/ButtonSelected.png");
    mTextures.load(Textures::ButtonPressed, "D:/sfml-start/src/Media/ButtonPressed.png");

    // mTextures.load(Textures::TitleScreen, "E:/sfml-start/src/Media/TitleScreen.png");
    // mTextures.load(Textures::ButtonNormal, "E:/sfml-start/src/Media/ButtonNormal.png");
    // mTextures.load(Textures::ButtonSelected, "E:/sfml-start/src/Media/ButtonSelected.png");
    // mTextures.load(Textures::ButtonPressed, "E:/sfml-start/src/Media/ButtonPressed.png");

    mStatisticsText.setFont(mFonts.get(Fonts::Main));
    mStatisticsText.setPosition(5.f, 5.f);
    mStatisticsText.setCharacterSize(10u);

    registerStates();
    // mStateStack.pushState(States::Title);
    mStateStack.pushState(States::Loading);

}

void Application::run() {
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while (mWindow.isOpen()) {
        sf::Time dt = clock.restart();
        timeSinceLastUpdate += dt;
        while (timeSinceLastUpdate > TimePerFrame) {
            timeSinceLastUpdate -= TimePerFrame;
            processInput();
            update(TimePerFrame);
            if (mStateStack.isEmpty()) {
                mWindow.close();
            }
        }
        updateStatistices(dt);
        render();
    }

}




void Application::processInput() {
    sf::Event event;
    while (mWindow.pollEvent(event)) {
        mStateStack.handleEvent(event);
        if (event.type == sf::Event::Closed) {
            mWindow.close();
        }
    }
}

void Application::update(sf::Time dt) {
    mStateStack.update(dt);
}

void Application::render() {
    mWindow.clear();
    mStateStack.draw();
    mWindow.setView(mWindow.getDefaultView());
    mWindow.draw(mStatisticsText);
    mWindow.display();
}

void Application::updateStatistices(sf::Time dt) {
    mStatisticsUpdateTime += dt;
    mStatisticsNumFrames += 1;
    if (mStatisticsUpdateTime >= sf::seconds(1.f)) {
        mStatisticsText.setString("FPS " + toString(mStatisticsNumFrames));
        mStatisticsUpdateTime -= sf::seconds(1.f);
        mStatisticsNumFrames = 0;
    }
}

void Application::registerStates() {
    mStateStack.registerState<TitleState>(States::Title);
    mStateStack.registerState<MenuState>(States::Menu);
    mStateStack.registerState<GameState>(States::Game);
    mStateStack.registerState<PauseState>(States::Pause);
    mStateStack.registerState<LoadingState>(States::Loading);
    mStateStack.registerState<SettingState>(States::Settings);
    // mStateStack.registerState<GameOverState>(States::GameOver);
}









