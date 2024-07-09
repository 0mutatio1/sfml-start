//
// Created by stone on 2024-07-09.
//

#ifndef PICKUP_H
#define PICKUP_H

#include "Entity.h"
#include "Command.h"
#include "ResourceIdentifiers.h"
#include <SFML/Graphics/Sprite.hpp>

class Aircraft;

class Pickup : public Entity {
public:
    enum Type {
        HealthRefill,
        MissileRefill,
        FireSpread,
        FireRate,
        TypeCount,
    };
public:
    Pickup(Type type, const TextureHolder& textures);
    virtual unsigned int getCategory() const override;
    virtual sf::FloatRect getBoundingRect() const;
    void apply(Aircraft& player) const;
protected:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
private:
    Type mType;
    sf::Sprite mSprite;
};



#endif //PICKUP_H
