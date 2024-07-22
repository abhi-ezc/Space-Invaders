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
        window.clear(sf::Color::Black);

        // creating circle

        sf::CircleShape circle;
        circle.setRadius(100); // setting circle raidus to 100
        circle.setPosition(( window.getSize().x / 2 ) - circle.getRadius(), ( window.getSize().y / 2 ) - circle.getRadius()); // setting the position of circle to center of the screen
        circle.setFillColor(sf::Color::Green); // filling circle with green color

        // creating square
        sf::RectangleShape square=sf::RectangleShape(sf::Vector2f(60, 60)); 
        square.setPosition(500, 200); // setting position of square
        square.setFillColor(sf::Color::Red); // filling square with red color

        // creating triangle
        sf::ConvexShape triangle = sf::ConvexShape(3); // creating triangle  using convex shape with 3 points
        triangle.setPosition(500, 500); // setting triangle position
        triangle.setPoint(0, sf::Vector2f(0, 0)); // setting the position of first point
        triangle.setPoint(1, sf::Vector2f(-60, 100)); // setting the position of second point
        triangle.setPoint(2, sf::Vector2f(60, 100));  // setting the position of third point
        triangle.setFillColor(sf::Color::Blue); // filling the triangle with blue color

        // draw circle
        window.draw(circle);

        // draw square
        window.draw(square);

        //draw triangle
        window.draw(triangle);

        // display whatever you draw
        window.display();

    }
    return 0;
}