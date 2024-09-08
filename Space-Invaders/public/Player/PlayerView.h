#pragma once
#include "SFML/System/String.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

namespace UI {
	namespace UIElement {
		class ImageView;
	}
}

namespace Player {
	class PlayerController;

	class PlayerView {
	private:

		UI::UIElement::ImageView* m_player_image;

		const int m_sprite_height = 60;
		const int m_sprite_width = 60;

		sf::RenderWindow* m_game_window;
		PlayerController* m_player_controller;

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
		sf::FloatRect getLocalBounds();
		sf::Sprite& getSprite();
		// Setters
	};
}
