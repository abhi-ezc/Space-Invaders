#include "../../public/event/EventService.h"
#include "../../public/global/ServiceLocator.h"
#include "../../public/graphic/GraphicService.h"

namespace Event
{
    using namespace Global;
    // constructor
    EventService::EventService()
    {
        m_game_window = nullptr;
        m_button_state_left_mouse_button = ButtonState::RELEASED;
        m_button_state_right_mouse_button = ButtonState::RELEASED;
        m_button_state_left_arrow_key = ButtonState::RELEASED;
        m_button_state_right_arrow_key = ButtonState::RELEASED;
        m_button_state_A_key = ButtonState::RELEASED;
        m_button_state_D_key = ButtonState::RELEASED;
    }

    EventService::~EventService() = default;

    void EventService::initialize()
    {
        m_game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
    }

    void EventService::update()
    {
        processEvents();
        updateButtonState(m_button_state_left_arrow_key, sf::Keyboard::Left);
        updateButtonState(m_button_state_right_arrow_key, sf::Keyboard::Right);
        updateButtonState(m_button_state_A_key, sf::Keyboard::A);
        updateButtonState(m_button_state_D_key, sf::Keyboard::D);

        updateButtonState(m_button_state_left_mouse_button, sf::Mouse::Left);
        updateButtonState(m_button_state_right_mouse_button, sf::Keyboard::Right);
    }

    void EventService::processEvents()
    {
        if (isGameWindowOpen())
        {
            while (m_game_window->pollEvent(m_game_event))
            {
                if (gameWindowWasClosed() || hasQuitGame())
                {
                    ServiceLocator::getInstance()->getGraphicService()->closeGameWindow();
                }
            }
        }
    }

    bool EventService::pressedEscapeKey() { return m_game_event.key.code == sf::Keyboard::Escape; }

    bool EventService::isKeyboardEvent() { return m_game_event.type == sf::Event::KeyPressed; }

    bool EventService::isLeftKeyPressed() { return m_button_state_left_arrow_key != ButtonState::RELEASED; }

    bool EventService::isRightKeyPressed() { return m_button_state_right_arrow_key != ButtonState::RELEASED; }

    bool EventService::isAKeyPressed() { return m_button_state_A_key != ButtonState::RELEASED; }

    bool EventService::isDKeyPressed() { return m_button_state_D_key != ButtonState::RELEASED; }

    bool EventService::isLeftMouseButtonPressed() { return m_button_state_left_mouse_button == ButtonState::PRESSED; }

    bool EventService::isRightMouseButtonPressed() { return m_button_state_right_mouse_button == ButtonState::PRESSED; }

    bool EventService::isGameWindowOpen() { return m_game_window->isOpen(); }

    bool EventService::gameWindowWasClosed() { return m_game_event.type == sf::Event::Closed; }

    bool EventService::hasQuitGame() { return isKeyboardEvent() && pressedEscapeKey(); }

    void EventService::updateButtonState(ButtonState& button_state_current, sf::Mouse::Button button_mouse)
    {
        if (sf::Mouse::isButtonPressed(button_mouse))
        {
            switch (button_state_current)
            {
                case ButtonState::PRESSED:
                    button_state_current = ButtonState::HELD;
                    break;
                case ButtonState::RELEASED:
                    button_state_current = ButtonState::PRESSED;
                    break;
            }
        }
        else { button_state_current = ButtonState::RELEASED; }
    }

    void EventService::updateButtonState(ButtonState& button_state_current, sf::Keyboard::Key button_keyboard)
    {
        if (sf::Keyboard::isKeyPressed(button_keyboard))
        {
            switch (button_state_current)
            {
                case ButtonState::PRESSED:
                    button_state_current = ButtonState::HELD;
                    break;
                case ButtonState::RELEASED:
                    button_state_current = ButtonState::PRESSED;
                    break;
            }
        }
        else { button_state_current = ButtonState::RELEASED; }
    }
}
