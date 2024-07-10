//
// Created by stone on 2024-06-25.
//

#ifndef WORLD_H
#define WORLD_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "CommandQueue.h"
#include "Aircraft.h"
#include "SceneNode.h"

#include "ResourceHolder.h"
#include "ResourceIdentifiers.h"

#include <array>
#include <queue>

class World : public sf::NonCopyable {
public:
	explicit World(sf::RenderWindow& window, FontHolder& fonts);
	void update(sf::Time dt);
	void draw();
	CommandQueue& getCommandQueue();
	bool hasAlivePlayer() const;
	bool hasPlayerReachedEnd() const;
private:
	void loadTextures();
	void adaptPlayerPosition();
	void adaptPlayerVelocity();
	void handleCollisions();

	void buildScene();
	void addEnemies();
	void addEnemy(Aircraft::Type type, float relX, float relY);
	void spawnEnemies();
	void destroyEntitiesOutsideView();
	void guideMissiles();
	sf::FloatRect getViewBounds() const;
	sf::FloatRect getBattlefieldBounds() const;



private:
	enum Layer {
		Background,
		Air,
		LayerCount
	};
	struct SpawnPoint {
		SpawnPoint(Aircraft::Type type, float x, float y)
			: type(type), x(x), y(y) {}
		Aircraft::Type type;
		float x;
		float y;
	};

private:
	sf::RenderWindow& mWindow;
	sf::View mWorldView;
	TextureHolder mTextures;
	FontHolder& mFonts;

	SceneNode mSceneGraph;
	std::array<SceneNode*, LayerCount> mSceneLayers;
	CommandQueue mCommandQueue;

	sf::FloatRect mWorldBounds;
	sf::Vector2f mSpawnPosition;
	float mScrollSpeed;
	Aircraft* mPlayerAircraft;

	std::vector<SpawnPoint>	mEnemySpawnPoints;
	std::vector<Aircraft*> mActiveEnemies;
};



#endif //WORLD_H
