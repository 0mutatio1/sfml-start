
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Network/Socket.hpp>
#include <SFML/System/Thread.hpp>
#include <SFML/Network/TcpListener.hpp>
#include <SFML/Network/TcpSocket.hpp>
#include <iostream>
#include <optional>
#include <iomanip>
#include <cstddef>

void server() {
	sf::TcpListener listener;
	if (listener.listen(9999) != sf::Socket::Done)
	{
		return;
	}
	std::cout << "Server is listenting to port " << 9999 << ", waiting for connnections...." << std::endl;

	sf::TcpSocket socket;
	// if (listener.accept(socket) != sf::Socket::Status::Done)
	//	return;
	while (listener.accept(socket) == sf::Socket::Status::Done)
	{

		std::cout << "#######################################################" << std::endl;

		std::cout << "Client connected: " << socket.getRemoteAddress().toString() << std::endl;

		const char out[] = "Hi, I'm the server";
		if (socket.send(out, sizeof(out)) != sf::Socket::Status::Done)
		{
			return;
		}
		std::cout << "Message sent to the client: " << std::quoted(out) << std::endl;
		char        in[128];
		std::size_t received = 0;
		if (socket.receive(in, sizeof(in), received) != sf::Socket::Status::Done)
			return;
		std::cout << "Answer received from the client: " << std::quoted(in) << std::endl;	
		
		std::cout << "#######################################################" << std::endl;

	}
}

void client() {
	// Ask for the server address
	//std::optional<sf::IpAddress> server;
	//do
	//{
	//	std::cout << "Type the address or name of the server to connect to: ";
	//	std::cin >> server;
	//} while (!server.has_value());

	// Create a socket for communicating with the server
	sf::TcpSocket socket;


	// Connect to the server
	if (socket.connect("127.0.0.1", 9999) != sf::Socket::Status::Done)
		return;
	// std::cout << "Connected to server " << "127.0.0.1:9999" << std::endl;
	// Receive a message from the server
	char        in[128];
	std::size_t received = 0;
	if (socket.receive(in, sizeof(in), received) != sf::Socket::Status::Done)
		return;
	std::cout << "Message received from the server: " << std::quoted(in) << std::endl;

	// Send an answer to the server
	const char out[] = "Hi, I'm a client";
	if (socket.send(out, sizeof(out)) != sf::Socket::Status::Done)
		return;
	std::cout << "Message sent to the server: " << std::quoted(out) << std::endl;

}





void socketit() {
	sf::RenderWindow window(sf::VideoMode(600, 500), "My window");

	sf::Thread thread(&server);
	thread.launch();

	// run the program as long as the window is open
	sf::Clock clock;	
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}
		// clear the window with black color
		window.clear(sf::Color::Black);


		// draw everything here...
		// window.draw(sprite);

		sf::Time elapsed = clock.getElapsedTime();
		if (elapsed.asSeconds() > 10)
		{
			clock.restart();
			client();
		}

		// end the current frame
		window.display();
	}
}