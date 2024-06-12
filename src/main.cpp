#include <SFML/Graphics.hpp>

#include <iostream>

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
	sf::CircleShape mPlayer;
	sf::Time TimePerFrame{ sf::seconds(1.f / 60.f) };
	bool mIsMovingUp{ false };
	bool mIsMovingDown{ false };
	bool mIsMovingLeft{ false };
	bool mIsMovingRight{ false };
};

Game::Game() : mWindow(sf::VideoMode(640, 480), "SFML App"), mPlayer()
{
	mPlayer.setRadius(40.f);
	mPlayer.setPosition(100.f, 100.f);
	mPlayer.setFillColor(sf::Color::Cyan);
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
			handlePlayerInput(event.key.code, true);
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
		movement.y -= 1.f;
	if (mIsMovingDown)
		movement.y += 1.f;
	if (mIsMovingLeft)
		movement.x -= 1.f;
	if (mIsMovingRight)
		movement.x += 1.f;
	mPlayer.move(movement * deltaTime.asSeconds());

}
void Game::render() {
	mWindow.clear();
	//
	sf::Texture texture;
	if (!texture.loadFromFile("./img/leaf.png"))
	{

	}
	sf::Sprite sprite(texture);
	sprite.setPosition(200.f, 200.f);
	mWindow.draw(sprite);
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