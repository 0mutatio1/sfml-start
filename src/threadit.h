#include <SFML/System/Thread.hpp>
#include <SFML/System/Mutex.hpp>
#include <SFML/System/Lock.hpp>

#include <iostream>


sf::Mutex mutex;

void func() {

	// mutex.lock();
	sf::Lock lock(mutex);
	for (int i = 0; i < 10; i++)
	{
		std::cout << " count number : " << i << std::endl;
		sf::sleep(sf::milliseconds(10));
	}
	mutex.unlock();
}

void threadit() {
	sf::Thread thread(&func);
	thread.launch();
	sf::Lock lock(mutex);
	for (int i = 0; i < 10; i++)
	{
		std::cout << " main thread " << std::endl;
		sf::sleep(sf::milliseconds(10));
	}
}