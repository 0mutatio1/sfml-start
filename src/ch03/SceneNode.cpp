
#include "SceneNode.h"
#include <assert.h>

void SceneNode::attachChild(Ptr child) {
	child->mParent = this;
	mChildren.push_back(std::move(child));
}

SceneNode::Ptr SceneNode::detachChild(const SceneNode& node) {
	auto found = std::find_if(
		mChildren.begin(), mChildren.end(), 
		[&](Ptr& p) -> bool { return p.get() == &node; }
	);
	assert(found != mChildren.end());
	Ptr result = std::move(*found);
	result->mParent = nullptr;
	mChildren.erase(found);
	return result;
}

void SceneNode::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform *= getTransform();
	drawCurrent(target, states);
	//for (auto itr = mChildren.begin(); itr != mChildren.end(); ++itr) {
	//	(*itr)->draw(target, states);
	//}
	for (const Ptr& child : mChildren) {
		child->draw(target, states);
	}
}

void SceneNode::update(sf::Time dt) {
	updateCurrent(dt);
	updateChildren(dt);
}

void SceneNode::updateCurrent(sf::Time dt) {

}
void SceneNode::updateChildren(sf::Time dt) {
	for (const Ptr& child : mChildren) {
		child->update(dt);
	}
}

sf::Transform SceneNode::getWorldTransform() const {
	sf::Transform transform = sf::Transform::Identity;
	for (const SceneNode* node = this; node != nullptr; node = node->mParent) {
		transform = node->getTransform() * transform;
	}
	return transform;

}
sf::Vector2f SceneNode::getWorldPosition() const {
	return getWorldTransform() * sf::Vector2f();
}