#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
namespace UI
{
	namespace MainMenu
	{
		class MainmenuUIController {
			private:
			sf::RenderWindow* gameWindow;

			public:
			MainmenuUIController();
			~MainmenuUIController();

			void initialize();
			void update();
			void render();
		};
	}
}