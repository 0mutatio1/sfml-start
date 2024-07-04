//
// Created by stone on 2024-07-03.
//

#include "include/Application.h"

#include "include/StringHelpers.h"

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

    mStatisticsText.setFont(mFonts.get(Fonts::Main));
    mStatisticsText.setPosition(5.f, 5.f);
    mStatisticsText.setCharacterSize(10u);

    registerStates();
    mStateStack.pushState(States::Title);

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

}









