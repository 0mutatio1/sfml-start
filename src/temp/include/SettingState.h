//
// Created by stone on 2024-07-08.
//

#ifndef SETTINGSTATE_H
#define SETTINGSTATE_H

#include "State.h"
#include "Player.h"
#include "Container.h"
#include "Button.h"
#include "Label.h"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

#include <array>


class SettingState : public State {
public:
    SettingState(StateStack& stack, Context context);
    virtual void draw();
    virtual bool update(sf::Time dt);
    virtual bool handleEvent(const sf::Event &event);
private:
    void updateLabels();
    void addButtonLabel(Player::Action action, float y, const std::string& text, Context context);
private:
    sf::Sprite mBackgroundSprite;
    GUI::Container mGUIContainer;
    std::array<GUI::Button::Ptr, Player::ActionCount> mBindingButtons;
    std::array<GUI::Label::Ptr, Player::ActionCount> mBindingLabels;
};



#endif //SETTINGSTATE_H
