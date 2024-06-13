//
// Created by stone on 2024-06-13.
//

#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
class Game {
public:
    Game();
    void run();
    void runWithDeltaTime();
private:
    void processEvents();
    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
    void update(sf::Time deltaTime);
    void render();
private:
    sf::RenderWindow mWindow;
    sf::Sprite mPlayer;
    sf::Texture mTexture;
    sf::Time TimePerFrame{ sf::seconds(1.f / 60.f) };
    bool mIsMovingUp{ false };
    bool mIsMovingDown{ false };
    bool mIsMovingLeft{ false };
    bool mIsMovingRight{ false };
};
#endif //GAME_H
