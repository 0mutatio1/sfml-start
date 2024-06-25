//
// Created by stone on 2024-06-25.
//

#include "include/World.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <algorithm>
#include <cmath>


World::World(sf::RenderWindow& window)
    : mWindow(window)
    , mWorldView(window.getDefaultView())
    , mTextures()
    , mSceneGraph()
    , mSceneLayers()
    , mWorldBounds(0.f, 0.f, mWorldView.getSize().x, 2000.f)
    , mSpawnPosition(mWorldView.getSize().x / 2.f, mWorldBounds.height - mWorldView.getSize().y / 2.f)
    , mScrollSpeed(-50.f)
    , mPlayerAircraft(nullptr)
{
    loadTextures();
    buildScene();
    mWorldView.setCenter(mSpawnPosition);
}