//
// Created by stone on 2024-07-01.
//

#ifndef STATESTACK_H
#define STATESTACK_H

#include "State.h"
#include "StateIdentifiers.h"
#include "ResourceIdentifiers.h"
#include <SFML/System/NonCopyable.hpp>
#include <SFML/System/Time.hpp>

#include <vector>
#include <utility>
#include <functional>
#include <map>

namespace sf {
    class Event;
    class RenderWindow;
}

class StateStack : private sf::NonCopyable {
public:
    enum Action {
        Push,
        Pop,
        Clear,
    };
public:
    explicit StateStack(State::Context context);
    template<typename T>
    void registerState(States::ID stateID);
    void update(sf::Time dt);
    void draw();
    void handleEvent(const sf::Event& event);
    void pushState(States::ID stateID);
    void popState();
    void clearStates();
    bool isEmpty() const;
private:
    State::Ptr createState(States::ID stateID);
    void applyPendingChanges();
private:
    struct PendingChange {
        explicit PendingChange(Action action, States::ID stateID = States::None);
        Action action;
        States::ID stateID;
    };
private:
    std::vector<State::Ptr> mStack;
    std::vector<PendingChange> mPendingList;
    State::Context mContext;
    std::map<States::ID, std::function<State::Ptr()>> mFactories;
};



#endif //STATESTACK_H
