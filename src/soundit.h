

#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
void soundit() {

	
    sf::RenderWindow window(sf::VideoMode(1024, 756), "My window");
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("E:/sfml-start/src/MissionTheme.ogg")) {

    }
    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.play();
    // run the program as long as the window is open
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
        // window.draw();
        // end the current frame
        window.display();
    }
}