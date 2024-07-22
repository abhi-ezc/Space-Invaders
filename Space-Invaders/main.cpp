#include <SFML/Graphics.hpp>
int main()
{
    sf::VideoMode videoMode = sf::VideoMode(1280, 720); // creating window video mode
    sf::RenderWindow window(videoMode, "SFML Window",sf::Style::Close); // creating window
    window.setFramerateLimit(60); // setting window to use 60 fps
    while( window.isOpen() ) {
        // check if window still open
        sf::Event windowEvent;
        while( window.pollEvent(windowEvent) )
        {
            // checking for any events in the window like keyboard or mouse events
            if( windowEvent.type == sf::Event::Closed )
            {
                // check if the closed event is triggered
                window.close(); // closing the window
            }
        }

        // clear the window and filling it with blue color
        window.clear(sf::Color::Blue);

        // display whatever you draw
        window.display();

    }
    return 0;
}