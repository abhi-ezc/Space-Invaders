#pragma once
#include "SFML/System/String.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "PlayerController.h"

class PlayerView {
	private:
	const sf::String texturePath = "assets/textures/player_ship.png";
	sf::Texture texture;
	sf::Sprite sprite;

	const int spriteHeight = 60;
	const int spriteWidth = 60;

	sf::RenderWindow* gameWindow;
	PlayerController* playerController;

	void setPlayerScale();

	public:
	
	// Constructors and Destructors
	PlayerView();
	~PlayerView();

	// Lifecycle methods
	void initialize(PlayerController* controller);
	void update();
	void render();

	// Operations
	void createPlayerSprite();

	// Getters
	sf::Sprite getPlayerSprite();

	// Setters
};