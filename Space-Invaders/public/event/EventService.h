#pragma once
#include "SFML/Window/Event.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

namespace Event
{
    enum class ButtonState
    {
        PRESSED,
        HELD,
        RELEASED
    };

    class EventService
    {
        private:
            sf::Event m_game_event; // for polling game events
            sf::RenderWindow* m_game_window; // accessing game window
            ButtonState m_button_state_left_mouse_button;
            ButtonState m_button_state_right_mouse_button;
            ButtonState m_button_state_left_arrow_key;
            ButtonState m_button_state_right_arrow_key;
            ButtonState m_button_state_A_key;
            ButtonState m_button_state_D_key;

            bool isGameWindowOpen();
            bool gameWindowWasClosed(); //for the condition we already had - the title bar cross.
            bool hasQuitGame(); //for our new 'ESC' condition
            void updateButtonState(ButtonState& buttonState, sf::Mouse::Button mouseButton);
            void updateButtonState(ButtonState& buttonState, sf::Keyboard::Key keyboardButton);

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
            bool isAKeyPressed();
            bool isDKeyPressed();
            bool isLeftMouseButtonPressed();
            bool isRightMouseButtonPressed();
    };
}
