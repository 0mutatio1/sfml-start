//
// Created by stone on 2024-06-13.
//

#include "Game.h"
#include <iostream>
#include "StringHelpers.h"

const float Game::PlayerSpeed = 100.f;
const sf::Time Game::TimePerFrame = sf::seconds(1.f / 60.f);

Game::Game()
: mWindow(sf::VideoMode(640, 480), "SFML App", sf::Style::Close)
, mTexture()
, mPlayer()
, mFont()
, mStatisticsText()
, mStatisticsUpdateTime()
, mStatisticsNumFrames(0)
{
    if (!mTexture.loadFromFile("D:/sfml-start/src/Eagle.png"))
    {
        std::cout << "load image failed" << std::endl;
    }
    mPlayer.setTexture(mTexture);
    mPlayer.setPosition(100.f, 100.f);

    mFont.loadFromFile("D:/sfml-start/src/Sansation.ttf");
    mStatisticsText.setFont(mFont);
    mStatisticsText.setPosition(5.f, 5.f);
    mStatisticsText.setCharacterSize(10);
}
void Game::processEvents() {
    sf::Event event;
    while (mWindow.pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::KeyPressed:
                handlePlayerInput(event.key.code, true);
            break;
            case sf::Event::KeyReleased:
                handlePlayerInput(event.key.code, false);
            break;
            case sf::Event::Closed:
                mWindow.close();
            break;
        }
    }
}
void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
    if (key == sf::Keyboard::W)
        mIsMovingUp = isPressed;
    else if (key == sf::Keyboard::S)
        mIsMovingDown = isPressed;
    else if (key == sf::Keyboard::A)
        mIsMovingLeft = isPressed;
    else if (key == sf::Keyboard::D)
        mIsMovingRight = isPressed;
}
void Game::update(sf::Time deltaTime)
{
    sf::Vector2f movement(0.f, 0.f);
    if (mIsMovingUp)
        movement.y -= 10.f;
    if (mIsMovingDown)
        movement.y += 10.f;
    if (mIsMovingLeft)
        movement.x -= 10.f;
    if (mIsMovingRight)
        movement.x += 10.f;
    mPlayer.move(movement * deltaTime.asSeconds());

}
void Game::render() {
    mWindow.clear();
    //
    mWindow.draw(mPlayer);
    mWindow.draw(mStatisticsText);
    mWindow.display();
}

void Game::run() {
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while (mWindow.isOpen())
    {
        sf::Time elapsedTime = clock.restart();
        timeSinceLastUpdate += elapsedTime;
        while (timeSinceLastUpdate > TimePerFrame) {
            timeSinceLastUpdate -= TimePerFrame;
            processEvents();
            update(TimePerFrame);
            updateStatistics0(TimePerFrame);
        }
        // updateStatistics(elapsedTime);
        render();
    }
}

void Game::updateStatistics0(sf::Time elapsedTime) {
    mStatisticsUpdateTime += elapsedTime;
    mStatisticsNumFrames += 1;
    if (mStatisticsUpdateTime >= sf::seconds(1.0f)) {
        std::cout << " mStatisticsNumFrames: " << mStatisticsNumFrames << std::endl;
        mStatisticsText.setString(
            "Frames / Second = " + toString(mStatisticsNumFrames) + "\n" +
            "Time / Update = " + toString(mStatisticsUpdateTime.asMicroseconds() / mStatisticsNumFrames) + "us");
        mStatisticsUpdateTime -= sf::seconds(1.0f);
        mStatisticsNumFrames = 0;
    }
}

void Game::updateStatistics(sf::Time elapsedTime) {
    mStatisticsUpdateTime += elapsedTime;
    mStatisticsNumFrames += 1;
    if (mStatisticsUpdateTime >= sf::seconds(1.0f)) {
        std::cout << " mStatisticsNumFrames: " << mStatisticsNumFrames << std::endl;
        mStatisticsText.setString(
            "Frames / Second = " + toString(mStatisticsNumFrames) + "\n" +
            "Time / Update = " + toString(mStatisticsUpdateTime.asMicroseconds() / mStatisticsNumFrames) + "us");
        mStatisticsUpdateTime -= sf::seconds(1.0f);
        mStatisticsNumFrames = 0;
    }
}
