#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/String.hpp>

namespace UI {
	namespace UIElement {
		class ImageView;
	}
}

namespace Gameplay {
	class GameplayView {
	private:
		UI::UIElement::ImageView* m_background_image;

	public:
		GameplayView();
		~GameplayView();

		void initialize();
		void update();
		void render();

		void initializeBackgroundImage();
	};
}
