//
// Created by stone on 2024-06-25.
//

#ifndef GAME_H
#define GAME_H

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "World.h"
#include "Player.h"
#include "ResourceIdentifiers.h"

class Game {
public:
    Game();
    void run();
private:
    void processInput();
    void update(sf::Time elapsedTime);
    void render();
    void updateStatistics(sf::Time elapsedTime);
private:
    static const sf::Time TimePerFrame;
    sf::RenderWindow mWindow;
    World mWorld;
    Player mPlayer;
    FontHolder mFonts;
    sf::Font mFont;
    sf::Text mStatisticsText;
    sf::Time mStatisticsUpdateTime;
    std::size_t mStatisticsNumFrames;
};



#endif //GAME_H
