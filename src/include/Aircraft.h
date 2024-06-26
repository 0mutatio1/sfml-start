//
// Created by stone on 2024-06-25.
//

#ifndef AIRCRAFT_H
#define AIRCRAFT_H

#include "Entity.h"
#include "ResourceIdentifiers.h"

#include <SFML/Graphics/Sprite.hpp>


class Aircraft : public Entity {
public:
    enum Type {
        Eagle,
        Raptor,
    };
public:
    Aircraft(Type type, const TextureHolder& textures);
    virtual unsigned int getCategory() const;
private:
    virtual void drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const;
private:
    Type mType;
    sf::Sprite mSprite;
};



#endif //AIRCRAFT_H
