#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <math.h>       /* fmod */
#include <iostream>
#include <random>


#define M_PI 3.14159265358

class ParticleSystem : public sf::Drawable, public sf::Transformable
{
public:

    ParticleSystem(unsigned int count) :
        m_particles(count),
        m_vertices(sf::Points, count),
        m_lifetime(sf::seconds(3.f)),
        m_emitter(500.f, 480.f),
        m_angle(0),
        m_rotate(1)
    {
    }

    void setEmitter(sf::Vector2f position)
    {
        std::cout << "x: " << position.x << " y: " << position.y << std::endl;
        m_emitter = position;
    }
    void updateEmitter(sf::Time dt) {
        float radius = 200.f;
        
        std::cout << "angle: " << m_angle << std::endl;
        std::cout << "x : " << radius * std::cos(m_angle) << std::endl;
        std::cout << "y : " << radius * std::sin(m_angle) << std::endl;
        setEmitter(sf::Vector2f(500.f + radius * std::cos(m_angle), 500.f + radius * std::sin(m_angle)));
        m_angle = m_angle + 10 * M_PI / 180;
               
    }

    void update(sf::Time elapsed)
    {
        srand(time(NULL));
        for (std::size_t i = 0; i < m_particles.size(); ++i)
        {
            // update the particle lifetime
            Particle& p = m_particles[i];
            p.lifetime -= elapsed;

            // if the particle is dead, respawn it
            if (p.lifetime <= sf::Time::Zero)
                resetParticle(i);

            // update the position of the corresponding vertex
            m_vertices[i].position += p.velocity * elapsed.asSeconds();

            // update the alpha (transparency) of the particle according to its lifetime
            float ratio = p.lifetime.asSeconds() / m_lifetime.asSeconds();

            int r = rand() % 255;
            int g = rand() % 255;
            int b = rand() % 255;
            int t = rand() % 255;

            m_vertices[i].color = sf::Color(r, g, b, t);
            // m_vertices[i].color = sf::Color::Red;
            // m_vertices[i].color.a = static_cast<sf::Uint8>(ratio * std::rand());
        }
        updateEmitter(elapsed);
    }

private:

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        // apply the transform
        states.transform *= getTransform();

        // our particles don't use a texture
        states.texture = NULL;

        // draw the vertex array
        target.draw(m_vertices, states);
    }

private:

    struct Particle
    {
        sf::Vector2f velocity;
        sf::Time lifetime;
    };

    void resetParticle(std::size_t index)
    {
        // give a random velocity and lifetime to the particle
        float angle = (std::rand() % 360) * 3.14f / 180.f;
        float speed = (std::rand() % 50) + 50.f;
        m_particles[index].velocity = sf::Vector2f(std::cos(angle) * speed, std::sin(angle) * speed);
        m_particles[index].lifetime = sf::milliseconds((std::rand() % 2000) + 1000);

        // reset the position of the corresponding vertex
        m_vertices[index].position = m_emitter;
    }

    std::vector<Particle> m_particles;
    sf::VertexArray m_vertices;
    sf::Time m_lifetime;
    sf::Vector2f m_emitter;
    float m_angle;
    float m_rotate;
};


int particle()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Particles");

    // create the particle system
    ParticleSystem particles(100000);

    // create a clock to track the elapsed time
    sf::Clock clock;

    // run the main loop
    while (window.isOpen())
    {
        // handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // make the particle system emitter follow the mouse
        //sf::Vector2i mouse = sf::Mouse::getPosition(window);
        //particles.setEmitter(window.mapPixelToCoords(mouse));

        // update it
        sf::Time elapsed = clock.restart();
        particles.update(elapsed);

        // draw it
        window.clear();
        window.draw(particles);
        window.display();
    }

    return 0;
}
