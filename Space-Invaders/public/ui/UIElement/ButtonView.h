#pragma once
#include "./ImageView.h"
#include "functional"

using CallbackFunction = std::function<void()>;

namespace UI {
	namespace UIElement {
		class TextView;

		class ButtonView : public ImageView {
		private:
			CallbackFunction m_click_handler;
			void printButtonClicked();

		protected:
			sf::String m_button_title;
			virtual void handleButtonInteraction();
			virtual bool clickedButton(sf::Sprite* buttonSprite, sf::Vector2f mousePosition);
		public:

			ButtonView();
			~ButtonView();

			virtual void initialize(sf::String title, sf::String texturePath, float width, float height, sf::Vector2f position);
			virtual void update() override;
			virtual void render() override;

			void registerCallbackFunction(CallbackFunction callback);
		};
	}
}