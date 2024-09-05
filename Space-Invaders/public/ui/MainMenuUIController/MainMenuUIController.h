#pragma once
#include <SFML/Graphics.hpp>
#include "./../interface/IUIController.h"
#include "./../UIElement/ButtonView.h"

namespace UI {
	namespace MainMenu {
		class MainMenuUIController : public Interface::IUIController {
		private:
			sf::RenderWindow* m_game_window;

			// buttons size
			const float m_button_height = 140.f;
			const float m_button_width = 400.f;

			// button positions
			const float m_play_button_y_position = 500.f;
			const float m_instruction_button_y_position = 700.f;
			const float m_quit_button_y_position = 900.f;

			const float m_background_alpha = 255.f;

			UI::UIElement::ButtonView* m_play_button;
			UI::UIElement::ButtonView* m_instruction_button;
			UI::UIElement::ButtonView* m_quit_button;

			UI::UIElement::ImageView* m_background_image;

			void initializeBackgroundImage();
			void initializeButtons();

			void createButtons();
			void setAllButtonsPosition();
			void setButtonPosition(UI::UIElement::ButtonView* button);

		public:
			MainMenuUIController();
			~MainMenuUIController() override;

			void initialize() override;
			void update() override;
			void render() override;
			void show() override;

			void registerButtonCallback();
			void onPlayButtonClick();
			void onInstructionButtonClick();
			void onQuitButtonClick();
		};
	}
}
