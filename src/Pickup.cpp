//
// Created by stone on 2024-07-09.
//

#include "include/Pickup.h"
#include "include/DataTables.h"
#include "include/Category.h"
#include "include/CommandQueue.h"
#include "include/Utility.h"
#include "include/ResourceHolder.h"

#include <SFML/Graphics/RenderTarget.hpp>

namespace {
    const std::vector<PickupData> Table = initializePickupData();
}

Pickup::Pickup(Type type, const TextureHolder &textures)
    : Entity(1)
    , mType(type)
    , mSprite(textures.get(Table[type].texture))
{
    centerOrigin(mSprite);
}
unsigned int Pickup::getCategory() const {
    return Category::Pickup;
}

sf::FloatRect Pickup::getBoundingRect() const {
    return getWorldTransform().transformRect(mSprite.getGlobalBounds());
}
void Pickup::apply(Aircraft &player) const {
    Table[mType].action(player);
}
void Pickup::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(mSprite, states);
}




