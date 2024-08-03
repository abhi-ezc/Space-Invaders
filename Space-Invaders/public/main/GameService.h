#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
namespace Global
{
	class ServiceLocator;
}

namespace Main
{
	// enum for GameState 
	// for handling transition between windows
	enum class GameState {
		BOOT,
		MAIN_MENU,
		GAMEPLAY
	};

	// GameService Class
	class GameService {

		private:
		Global::ServiceLocator* serviceLocator;
		sf::RenderWindow* gameWindow;
		static GameState gameState;

		void initialize(); // Handles game initialization
		void initializeVariables(); // initialize member variables
		void destroy(); // Handles cleanup task

		

		public:
		GameService(); // Constructor
		~GameService(); // Destructor

		void ignite(); // Initiates the game.
		void update(); // Update the game logic and game state
		void render(); // Renders each frame of the game
		bool isRunning(); // Checks if the game is currently running

		static void setGameState(GameState state); // set current game state
		static GameState getGameState(); // returns the current game state
	};
}

