//
// Created by stone on 2024-06-25.
//

#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Window/Event.hpp>
#include <map>

class CommandQueue;

class Player {

public:
    enum Action {

    };
public:
    Player();
    void handleEvent(const sf::Event& event, CommandQueue& commands);
    void handleRealtimeInput(CommandQueue& commands);

};



#endif //PLAYER_H
