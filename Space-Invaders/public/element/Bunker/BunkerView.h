#pragma once
#include <SFML/Graphics.hpp>

namespace UI {
	namespace UIElement {
		class ImageView;
	}
}

namespace Element {
	namespace Bunker {
		class BunkerController;

		class BunkerView {
		private:
			UI::UIElement::ImageView* m_bunker_image;

			float m_sprite_height = 80.f;
			float m_sprite_width = 80.f;


			void initializeSprite(sf::Vector2f position);

		public:
			BunkerView();
			~BunkerView();

			void initialize(BunkerController*);
			void update();
			void render();
		};
	}
}
