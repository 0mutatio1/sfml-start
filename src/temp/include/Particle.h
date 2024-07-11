//
// Created by stone on 2024-07-10.
//

#ifndef PARTICLE_H
#define PARTICLE_H
#include <SFML/System/Vector2.hpp>

#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Time.hpp>


struct Particle {
    enum Type {
        Propellant,
        Smoke,
        ParticleCount,
    };
    sf::Vector2f position;
    sf::Color color;
    sf::Time lifetime;
};

struct ParticleData
{
    sf::Color color;
    sf::Time lifetime;
};

#endif //PARTICLE_H
