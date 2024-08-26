#pragma once
#include "SFML/Graphics.hpp"

namespace Player {
	// player state enum
	enum class PlayerState {
		ALIVE,
		DEAD,
		LIMBO
	};

	// player model class
	class PlayerModel {
	private:
		const sf::Vector2f m_initial_player_position = sf::Vector2f(950.f, 950.f);
		sf::Vector2f m_current_player_position;
		PlayerState m_player_state;
		int m_player_score;

		sf::Vector2f m_muzzle_offset = sf::Vector2f(0, -40.f);

	public:
		const float m_movement_speed = 350.0f;
		const float m_left_most_position = 50.f;
		const float m_right_most_position = 1800.f;

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
		sf::Vector2f getMuzzleOffset();

		// setters
		void setPlayerState(PlayerState newPlayerState);
		void setPlayerScore(int score);
		void setPlayerPosition(sf::Vector2f position);
	};
}
