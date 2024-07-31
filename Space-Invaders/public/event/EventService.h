#pragma once
#include "SFML/Window/Event.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

namespace Event
{
	class EventService {
		private:
		sf::Event gameEvent; // for polling game events
		sf::RenderWindow* gameWindow; // accessing game window

		bool isGameWindowOpen();
		bool gameWindowWasClosed(); //for the condition we already had - the title bar cross.
		bool hasQuitGame(); //for our new 'ESC' condition

		public:
		EventService();
		~EventService();

		void initialize(); // initialize game event
		void update(); // update 
		void processEvents();
		bool pressedEscapeKey();
		bool isKeyboardEvent();
		bool isLeftKeyPressed();
		bool isRightKeyPressed();
	};
}



