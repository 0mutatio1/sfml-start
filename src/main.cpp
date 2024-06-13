
#include "Game.h"
#include <iostream>


Game::Game() : mWindow(sf::VideoMode(640, 480), "SFML App"), mPlayer(), mTexture()
{
	if (!mTexture.loadFromFile("D:/sfml-start/src/Eagle.png"))
	{
		std::cout << "load image failed" << std::endl;
	}
	mPlayer.setTexture(mTexture);
	mPlayer.setPosition(100.f, 100.f);
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
	mWindow.display();
}
void Game::runWithDeltaTime() {
	sf::Clock clock;
	while (mWindow.isOpen())
	{
		sf::Time deltaTime = clock.restart();
		processEvents();
		update(deltaTime);
		render();
	}
}
void Game::run() {
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (mWindow.isOpen())
	{
		processEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > TimePerFrame) {
			timeSinceLastUpdate -= TimePerFrame;
			processEvents();
			update(TimePerFrame);
		}		
		render();
	}
}

int main() {
	Game game;
	game.run();
}