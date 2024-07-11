//
// Created by stone on 2024-07-09.
//

#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "Entity.h"
#include "ResourceIdentifiers.h"

#include <SFML/Graphics/Sprite.hpp>

class Projectile : public Entity {
public:
    enum Type {
        AlliedBullet,
        EnemyBullet,
        Missile,
        TypeCount,
    };
public:
    Projectile(Type type, const TextureHolder& textures);
    void guideTowards(sf::Vector2f position);
    bool isGuided() const;
    virtual unsigned int getCategory() const override;
    virtual sf::FloatRect getBoundingRect() const;
    float getMaxSpeed() const;
    int getDamage() const;
private:
    virtual void updateCurrent(sf::Time dt, CommandQueue &commands) override;
    virtual void drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const override;
private:
    Type mType;
    sf::Sprite mSprite;
    sf::Vector2f mTargetDirection;
};



#endif //PROJECTILE_H
