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

        // draw triangle
        window.draw(triangle);

        // create and load texture
        sf::Texture outscalLogo;
        outscalLogo.loadFromFile("assets/textures/outscal_logo.png"); // load a texture image from the files
        
        // create sprite from texture
        sf::Sprite outscalLogoSprite;
        outscalLogoSprite.setTexture(outscalLogo); // setting texture for the sprite object
        outscalLogoSprite.setPosition(200, 300); // setting up the position for the sprite
        outscalLogoSprite.setScale(sf::Vector2f(0.5, 0.5)); // adjusted the scale for the sprite
        outscalLogoSprite.setRotation(45); // rotate the image in 45 degrees
        window.draw(outscalLogoSprite);

        // create a font object
        sf::Font font;
        font.loadFromFile("assets/fonts/bubbleBobble.ttf"); // load a font from the files

        // create a text object
        sf::Text textObject = sf::Text("SFML is Awesome", font, 50); // create a text object using the font
        textObject.setFillColor(sf::Color::White);  // update text color to white
        textObject.setPosition(800,400);
        window.draw(textObject); // draw the text

        // display whatever you draw
        window.display();

    }
    return 0;
}