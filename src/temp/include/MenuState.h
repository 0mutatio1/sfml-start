//
// Created by stone on 2024-07-04.
//

#ifndef MENUSTATE_H
#define MENUSTATE_H

#include "State.h"
#include <SFML/Graphics/Sprite.hpp>

#include "Container.h"

class MenuState : public State {
public:
    MenuState(StateStack& stack, Context context);
    virtual void draw();
    virtual bool update(sf::Time dt);
    virtual bool handleEvent(const sf::Event &event);

private:
    sf::Sprite mBackgroundSprite;
    GUI::Container mGUIContianer;
};



#endif //MENUSTATE_H
