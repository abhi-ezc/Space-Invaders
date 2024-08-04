#pragma once
#include <SFML/Graphics.hpp>
namespace UI
{
	namespace MainMenu
	{
		class MainmenuUIController {
			private:
			sf::RenderWindow* gameWindow;

			// textures for ui elements
			sf::Texture tex_backgroundImage;
			sf::Texture tex_playButton;
			sf::Texture tex_instructionButton;
			sf::Texture tex_quitButton;

			// sprites for drawing ui elements
			sf::Sprite spr_backgroundImage;
			sf::Sprite spr_playButton;
			sf::Sprite spr_instructionButton;
			sf::Sprite spr_quitButton;
			
			// buttons size
			const float f_buttonHeight = 140.f;
			const float f_buttonWidth = 400.f;

			// texture paths where image to loaded
			const sf::String str_backgroundImagePath = "assets/textures/space_invaders_bg.png";
			const sf::String str_playButtonPath = "assets/textures/play_button.png";
			const sf::String str_instructionButtonPath="assets/textures/instructions_button.png";
			const sf::String str_quitButtonPath="assets/textures/quit_button.png";

			void initializeBackgroundImage();
			void initializeButtons();

			bool loadButtonTextures();
			void createButtonSprites();
			void scaleAllButtons();
			void scaleButton(sf::Sprite* spr_button);
			void setAllButtonsPosition();
			void setButtonPosition(sf::Sprite* spr_button,float y);

			public:
			MainmenuUIController();
			~MainmenuUIController();

			void initialize();
			void update();
			void render();

			void processButtonInteractions();
			bool isButtonClick(sf::Sprite* spr_button,sf::Vector2i mousePosition);
			void onPlayButtonClick();
			void onInstructionButtonClick();
			void onQuitButtonClick();
		};
	}
}