#include<iostream>
#include <SFML/Graphics.hpp>


class Player {
	private:
	sf::Texture texture; // player texture for create a sprite
	sf::Sprite sprite; // player sprite for rendering in the window
	int playerScore; // player score
	int health; // player health
	int movementSpeed; // player movement speed
	sf::Vector2f position; // player position in the window

	public:
	Player() {
		texture.loadFromFile("assets/textures/player_ship.png");
		sprite.setTexture(texture);
		health = 100;
		playerScore = 0;
		movementSpeed = 10;
		position = sf::Vector2f(200.f, 100.f);
	}

	int getHealth() {
		return health;
	}

	int getPlayerScore() {
		return playerScore;
	}
	
	void takeDamage() { 
		
	}

	void move() {
		
	}

	void shootBullets() {
		
	}
};

int main() {
	sf::VideoMode videoMode = sf::VideoMode(1280, 720); // creating window video mode
	sf::RenderWindow window(videoMode, "SFML Window", sf::Style::Close); // creating window
	window.setFramerateLimit(60); // setting window to use 60 fps
	Player player;
	while( window.isOpen() )
	{
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

		std::cout << "Player Health : " << player.getHealth() << std::endl;
		// clear the window and filling it with blue color
		window.clear(sf::Color::Black);

		// display whatever you draw
		window.display();

	}
	return 0;
}