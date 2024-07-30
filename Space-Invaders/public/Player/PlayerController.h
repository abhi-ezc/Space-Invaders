#pragma once
#include "SFML/System/Vector2.hpp"

class PlayerModel;
class PlayerView;

class PlayerController {
	private:
	PlayerModel* playerModel;
	PlayerView* playerView;

	void processPlayerInputs();
	void moveLeft();
	void moveRight();
	
	public:
	// constructors and destructors
	PlayerController();
	~PlayerController();

	// life cycle methods
	void initialize();
	void update();
	void render();

	// getters
	sf::Vector2f getPlayerPosition();
};