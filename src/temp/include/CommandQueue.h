//
// Created by stone on 2024-06-25.
//

#ifndef COMMANDQUEUE_H
#define COMMANDQUEUE_H

#include "Command.h"
#include <queue>

class CommandQueue {
public:
	void push(const Command& command);
	Command pop();
	bool isEmpty() const;
private:
	std::queue<Command> mQueue;
};



#endif //COMMANDQUEUE_H
