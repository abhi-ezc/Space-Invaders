#pragma once
#include "SFML/Graphics.hpp"


// player state enum
enum class PlayerState {
	ALIVE,
	DEAD,
	LIMBO
};

// player model class
class PlayerModel {
	private:
	const sf::Vector2f initialPlayerPosition = sf::Vector2f(500.f,500.f);
	sf::Vector2f currentPlayerPosition;
	PlayerState playerState;
	int playerScore;

	public:
	const float movementSpeed = 350.0f;

	// constructor & destructor
	PlayerModel();
	~PlayerModel();

	// lifecycle methods
	void initialize();
	void update();
	void render();

	// operator functions
	void reset();
	
	// getters
	sf::Vector2f getPlayerPosition();
	bool isPlayerAlive();
	PlayerState getPlayerState();
	int getPlayerScore();

	// setters
	void setPlayerState(PlayerState newPlayerState);
	void setPlayerScore(int score);
};