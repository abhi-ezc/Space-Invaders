#include<iostream>
#include <SFML/Graphics.hpp>
#include "./public/GameService.h"


class Player {
	private:
	sf::Texture texture; // player texture for create a sprite
	sf::Sprite sprite; // player sprite for rendering in the window
	int playerScore; // player score
	int health; // player health
	float movementSpeed; // player movement speed
	sf::Vector2f position; // player position in the window

	public:
	Player(int health, float movementSpeed) {
		texture.loadFromFile("assets/textures/player_ship.png");
		sprite.setTexture(texture);
		this->health = health;
		playerScore = 0;
		this->movementSpeed = movementSpeed;
		position = sf::Vector2f(200.f, 100.f);
	}

	~Player() {
		std::cout << "destroyed";
	}

	sf::Sprite getSprite() {
		return sprite;
	}

	int getHealth() {
		return health;
	}

	int getPlayerScore() {
		return playerScore;
	}

	int getMovementSpeed() {
		return movementSpeed;
	}

	void takeDamage() {

	}

	void updatePlayerPosition() {
		sprite.setPosition(position);
	}

	void move(float offset) {
		position.x += offset;

	}

	void shootBullets() {

	}
};

int main() {

	/*
	sf::VideoMode videoMode = sf::VideoMode(1280, 720); // creating window video mode
	sf::RenderWindow window(videoMode, "SFML Window", sf::Style::Close); // creating window
	window.setFramerateLimit(60); // setting window to use 60 fps
	Player player(100, 5);
	while( window.isOpen() )
	{
		// check if window still open
		sf::Event windowEvent;
		while( window.pollEvent(windowEvent) )
		{

			switch( windowEvent.type )
			{
				case sf::Event::Closed:
					// check window close event
					window.close(); // close the window
					break;
				case sf::Event::KeyPressed:
					if( sf::Keyboard::isKeyPressed(sf::Keyboard::A) )
					{
						player.move(-1.f * player.getMovementSpeed()); // move player to left
					}
					else if( sf::Keyboard::isKeyPressed(sf::Keyboard::D) )
					{
						player.move(player.getMovementSpeed()); // move player to right
					}
					else if( sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) )
					{
						window.close(); // close the window
					}
					else
					{
						// handle if anything else
					}
					break;
			}
		}

		// clear the window and filling it with blue color
		window.clear(sf::Color::Black);

		// update player location
		player.updatePlayerPosition();

		// drawing player sprite
		window.draw(player.getSprite());

		// display whatever you draw
		window.display();

	}
	*/

	GameService* gameService = new GameService();
	gameService->ignite();
	while( gameService->isRunning() )
	{
		gameService->update();
		gameService->render();
	}
	delete gameService; // freeing up the GameService ptr
}