//
// Created by stone on 2024-07-10.
//

#ifndef PARTICLENODE_H
#define PARTICLENODE_H

#include "SceneNode.h"
#include "ResourceIdentifiers.h"
#include "Particle.h"

#include <SFML/Graphics/VertexArray.hpp>
#include <deque>

class ParticleNode : public SceneNode {
public:
    ParticleNode(Particle::Type type, const TextureHolder &textures);

    void addParticle(sf::Vector2f position);

    Particle::Type getParticleType() const;

    virtual unsigned int getCategory() const override;

private:
    virtual void updateCurrent(sf::Time dt, CommandQueue &commands) override;

    void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void addVertex(float worldX, float worldY, float texCoordX, float texCoordY, const sf::Color &color) const;

    void computeVertices() const;
private:
    std::deque<Particle> mParticles;
    const sf::Texture& mTexture;
    Particle::Type mType;
    mutable sf::VertexArray mVertexArray;
    mutable bool mNeedsVertexUpdate;
};


#endif //PARTICLENODE_H
