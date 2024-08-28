#pragma once
#include "SFML/System/Vector2.hpp"

namespace Powerup {
	enum class PowerupType;

	class PowerupModel {
	private:
		sf::Vector2f m_position;
		PowerupType m_powerup_type;

	public:
		PowerupModel(PowerupType type);
		~PowerupModel();

		void initialize(sf::Vector2f position);
		void update();
		void render();

		void setPosition(sf::Vector2f position);
		sf::Vector2f getPosition();

		PowerupType getType();

	};
}