#pragma once

class GameService {
	private:
	void initialize(); // Handles game initialization
	void destroy(); // Handles cleanup task

	public:
	GameService(); // Constructor
	~GameService(); // Destructor

	void ignite(); // Initiates the game.
	void update(); // Update the game logic and game state
	void render(); // Renders each frame of the game
	bool isRunning(); // Checks if the game is currently running
};