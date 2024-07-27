#pragma once
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Texture.hpp"

class PlayerService {
	private:
	const sf::String texturePath = "assets/textures/player_ship.png"; //  texture of the player
	sf::Texture texture; // player texture for create a sprite
	sf::Sprite sprite; // player sprite for rendering in the window
	int playerScore; // player score
	int health; // player health
	float movementSpeed; // player movement speed
	sf::Vector2f position; // player position in the window
	sf::RenderWindow* gameWindow;

	void initializePlayerSprite();

	void processPlayerInput();
	void updatePlayerPosition();

	public:
	PlayerService();
	~PlayerService();
	void takeDamage();
	void move(float offset);
	void shootBullets();
	void initialize();
	void update();
	void render();
};