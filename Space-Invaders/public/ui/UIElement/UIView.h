#pragma once
#include <SFML/Graphics.hpp>

namespace UI {
	namespace UIElement {
		enum class UIState {
			VISIBLE,
			HIDDEN,
		};

		class UIView {
		protected:
			sf::RenderWindow* m_game_window;
			UIState m_ui_state;

		public:
			UIView();
			virtual ~UIView();

			virtual void initialize();
			virtual void update();
			virtual void render();

			virtual void show();
			virtual void hide();

			virtual sf::Drawable& getDrawable() = 0;
		};
	}
}