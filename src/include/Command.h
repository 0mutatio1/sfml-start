//
// Created by stone on 2024-06-25.
//

#ifndef COMMAND_H
#define COMMAND_H


#include "Category.h"
#include <SFML/System/Time.hpp>

#include <functional>
#include <cassert>

class SceneNode;

struct Command {

	Command();
	std::function<void(SceneNode&, sf::Time)> action;
	unsigned int category;

};

template<typename GameObject, typename Function>
std::function<void(SceneNode&, sf::Time)> derivedAction(Function fn) {
	return [=](SceneNode& node, sf::Time dt) {
		assert(dynamic_cast<GameObject*>(&node) != nullptr);
		fn(static_cast<GameObject&>(node), dt);
	};
}



#endif //COMMAND_H
