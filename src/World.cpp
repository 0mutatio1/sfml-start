
#include "World.h"

World::World(sf::RenderWindow& window)
	: mWindow(window)
	, mWorldView(window.getDefaultView())
	, mWorldBounds(0.f, 0.f, mWorldView.getSize().x, 2000.f)
	, mSpawnPosition(mWorldView.getSize().x / 2.f,
		mWorldBounds.height - mWorldView.getSize().y / 2.f)
	, mScrollSpeed(-50.f)
	, mPlayerAircraft(nullptr)
{
	loadTextures();
	buildScene();
	mWorldView.setCenter(mSpawnPosition);
}

void World::loadTextures()
{
	mTextures.load(Textures::Eagle, "E:/sfml-start/src/Eagle.png");
	mTextures.load(Textures::Raptor, "E:/sfml-start/src/Raptor.png");
	mTextures.load(Textures::Desert, "E:/sfml-start/src/Desert.png");
}

void World::buildScene() {
	for (std::size_t i = 0; i < LayerCount; ++i) {
		SceneNode::Ptr layer(new SceneNode());
		mSceneLayers[i] = layer.get();
		mSceneGraph.attachChild(std::move(layer));
	}
	// prepare the tiled bg
	sf::Texture& texture = mTextures.get(Textures::Desert);
	sf::IntRect textureRect(mWorldBounds);
	texture.setRepeated(true);
	//
	std::unique_ptr<SpriteNode> backgroundSprite(
		new SpriteNode(texture, textureRect)
	);
	backgroundSprite->setPosition(
		mWorldBounds.left,
		mWorldBounds.top
	);
	mSceneLayers[Background]->attachChild(std::move(backgroundSprite));

	std::unique_ptr<Aircraft> leader(
		new Aircraft(Aircraft::Eagle, mTextures)
	);
	mPlayerAircraft = leader.get();
	mPlayerAircraft->setPosition(mSpawnPosition);
	mPlayerAircraft->setVelocity(40.f, mScrollSpeed);
	mSceneLayers[Air]->attachChild(std::move(leader));
	//


}
