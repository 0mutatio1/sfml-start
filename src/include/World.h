//
// Created by stone on 2024-06-25.
//

#ifndef WORLD_H
#define WORLD_H
#include <SFML/Graphics/RenderWindow.hpp>
#include "include/CommandQueue.h"
#include "include/Aircraft.h"
#include "include/SceneNode.h"

#include "ResourceHolder.h"
#include "include/ResourceIdentifiers.h"

#include <array>
#include <queue>

class World {
public:
	explicit World(sf::RenderWindow& window);
	void update(sf::Time dt);
	void draw();
	CommandQueue& getCommandQueue();
private:
	void loadTextures();
	void buildScene();
	void adaptPlayerPosition();
	void adaptPlayerVelocity();

private:
	enum Layer {
		Background,
		Air,
		LayerCount
	};

private:
	sf::RenderWindow& mWindow;
	sf::View mWorldView;
	TextureHolder mTextures;

	SceneNode mSceneGraph;
	std::array<SceneNode*, LayerCount> mSceneLayers;
	CommandQueue mCommandQueue;

	sf::FloatRect mWorldBounds;
	sf::Vector2f mSpawnPosition;
	float mScrollSpeed;
	Aircraft* mPlayerAircraft;

};



#endif //WORLD_H
