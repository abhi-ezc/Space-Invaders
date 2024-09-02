#pragma once
#include "SFML/System/String.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Sprite.hpp"

namespace UI {
	namespace UIElement {
		class ImageView;
	}
}

namespace Powerup {
	class PowerupController;
	enum class PowerupType;

	class PowerupView {
	private:
		sf::String m_powerup_texture_path;

		UI::UIElement::ImageView* m_powerup_image;
		float width = 30.f;
		float height = 30.f;

		PowerupController* m_controller;

		void loadTexture(PowerupType type);
	public:
		PowerupView(PowerupController* controller);
		~PowerupView();

		void initialize();
		void update();
		void render();

	};
}