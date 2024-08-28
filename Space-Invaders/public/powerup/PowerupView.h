#pragma once
#include "SFML/System/String.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Sprite.hpp"

namespace Powerup {
	class PowerupController;
	enum class PowerupType;

	class PowerupView {
	private:
		sf::String m_powerup_texture_path;
		sf::Texture m_powerup_texture;
		sf::Sprite m_powerup_sprite;

		float width = 30.f;
		float height = 30.f;

		PowerupController* m_controller;

		void loadTexture(PowerupType type);
		void initSprite();
		void scaleSprite();
	public:
		PowerupView(PowerupController* controller);
		~PowerupView();

		void initialize();
		void update();
		void render();

	};
}