//
// Created by stone on 2024-06-13.
//

#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include "World.h"

class Game : private sf::NonCopyable {
public:
    Game();
    void run();
private:
    void processEvents();
    void update(sf::Time deltaTime);
    void render();

    void updateStatistics(sf::Time elapsedTime);
    void updateStatistics0(sf::Time elapsedTime);
    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
private:
    static const float PlayerSpeed;
    static const sf::Time TimePerFrame;
    sf::RenderWindow mWindow;
    World mWorld;
    sf::Texture mTexture;
    sf::Sprite mPlayer;
    sf::Font mFont;
    sf::Text mStatisticsText;
    sf::Time mStatisticsUpdateTime;
    std::size_t mStatisticsNumFrames;
    bool mIsMovingUp{ false };
    bool mIsMovingDown{ false };
    bool mIsMovingLeft{ false };
    bool mIsMovingRight{ false };
};
#endif //GAME_H
