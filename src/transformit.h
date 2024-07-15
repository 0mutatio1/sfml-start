#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Transform.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Clock.hpp>

class T : public sf::Transformable {

};
class Node : public sf::Drawable, public sf::Transformable {
public:
    void draw(sf::RenderTarget& target, const sf::Transform& parentTransform) const {
        sf::Transform combinedTransform = parentTransform;
        onDraw(target, combinedTransform);
        for (size_t i = 0; i < m_children.size(); i++)
        {
            m_children[i]->draw(target, combinedTransform);
        }
    }
private:
    virtual void onDraw(sf::RenderTarget& target, const sf::Transform& transform) const = 0;
    sf::Transform m_transform;
    std::vector<Node*> m_children;
};
class SpriteNode : public Node
{
public:
private:
    virtual void onDraw(sf::RenderTarget& target, const sf::Transform& transform) const {
        target.draw(m_sprite, transform);
    }
    sf::Sprite m_sprite;
};

void transformit() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    sf::Clock clock;
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        sf::Texture texture;

        if (!texture.loadFromFile("D:/sfml-start/src/f22.jpg"))
        {

        }
        // draw everything here...
        sf::CircleShape shape(200.f);
        shape.setOrigin(0, 0);

        shape.setPosition(300, 200);
        shape.setTexture(&texture);
        sf::Time elapsed = clock.getElapsedTime();
        if (elapsed.asSeconds() > 3)
        {
            shape.move(-30.f, 0);
            shape.rotate(30.f);
        }
        window.draw(shape);

        // end the current frame
        window.display();
    }
}