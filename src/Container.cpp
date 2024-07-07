
#include "include/Container.h"
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

namespace GUI {
	Container::Container() : mChildren(), mSelectedChild(-1)
	{}
	void Container::pack(Component::Ptr component) {
		mChildren.push_back(component);
		if (!hasSelection && component->isSelecteable())
		{
			select(mChildren.size() - 1);
		}
	}
	bool Container::isSelectable() const {
		return false;
	}
	void Container::handleEvent(const sf::Event& event) {

	}
}