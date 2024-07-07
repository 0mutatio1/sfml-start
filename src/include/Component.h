//
// Created by stone on 2024-07-05.
//

#ifndef COMPONENT_H
#define COMPONENT_H

#include <memory>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>

#include "SFML/System/NonCopyable.hpp"
#include "SFML/Window/Event.hpp"


namespace GUI {

class Component : public sf::Drawable
                , public sf::Transformable
                , public sf::NonCopyable {
public:
    typedef std::shared_ptr<Component> Ptr;
public:
    Component();
    virtual ~Component();
    virtual bool isSelecteable() const = 0;
    bool isSelected() const;
    virtual void select();
    virtual void deselect();
    virtual bool isActive() const;
    virtual void activate();
    virtual void deactivate();
    virtual void handleEvent(const sf::Event& event) = 0;
private:
    bool mIsSelected;
    bool mIsActive;
};

}



#endif //COMPONENT_H
