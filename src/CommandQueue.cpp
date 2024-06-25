//
// Created by stone on 2024-06-25.
//

#include "include/CommandQueue.h"
#include "include/SceneNode.h"

void CommandQueue::push(const Command& command) {
	mQueue.push(command);
}

Command CommandQueue::pop() {
	Command command = mQueue.front();
	mQueue.pop();
	return command;
}

bool CommandQueue::isEmpty() const {
	return mQueue.empty();
}