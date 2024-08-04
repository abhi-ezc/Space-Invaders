#include "../../public/event/EventService.h"
#include "../../public/global/ServiceLocator.h"
#include "../../public/graphic/GraphicService.h"

namespace Event
{
	using namespace Global;
	// constructor
	EventService::EventService() {
		gameWindow = nullptr;
		button_state_left_mouse_button = ButtonState::RELEASED;
		button_state_right_mouse_button = ButtonState::RELEASED;
		button_state_left_arrow_key = ButtonState::RELEASED;
		button_state_right_arrow_key = ButtonState::RELEASED;
		button_state_A_key = ButtonState::RELEASED;
		button_state_D_key = ButtonState::RELEASED;
	}

	EventService::~EventService() = default;

	void EventService::initialize() {
		gameWindow = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
	}

	void EventService::update() {
		processEvents();
		updateButtonState(button_state_left_arrow_key, sf::Keyboard::Left);
		updateButtonState(button_state_right_arrow_key, sf::Keyboard::Right);
		updateButtonState(button_state_A_key, sf::Keyboard::A);
		updateButtonState(button_state_D_key, sf::Keyboard::D);

		updateButtonState(button_state_left_mouse_button, sf::Mouse::Left);
		updateButtonState(button_state_right_mouse_button, sf::Keyboard::Right);
	}

	void EventService::processEvents() {
		if( isGameWindowOpen() )
		{
			while( gameWindow->pollEvent(gameEvent) )
			{
				if( gameWindowWasClosed() || hasQuitGame() )
				{
					ServiceLocator::getInstance()->getGraphicService()->closeGameWindow();
				}
			}
		}
	}

	bool EventService::pressedEscapeKey() {
		return gameEvent.key.code == sf::Keyboard::Escape;
	}

	bool EventService::isKeyboardEvent() {
		return gameEvent.type == sf::Event::KeyPressed;
	}

	bool EventService::isLeftKeyPressed() {
		return  button_state_left_arrow_key != ButtonState::RELEASED;
	}

	bool EventService::isRightKeyPressed() {
		return  button_state_right_arrow_key != ButtonState::RELEASED;
	}

	bool EventService::isAKeyPressed() {
		return  button_state_A_key != ButtonState::RELEASED;
	}

	bool EventService::isDKeyPressed() {
		return button_state_D_key != ButtonState::RELEASED;
	}

	bool EventService::isLeftMouseButtonPressed() {
		return button_state_left_mouse_button == ButtonState::PRESSED;
	}

	bool EventService::isRightMouseButtonPressed() {
		return  button_state_right_mouse_button == ButtonState::PRESSED;
	}

	bool EventService::isGameWindowOpen() {
		return gameWindow->isOpen();
	}

	bool EventService::gameWindowWasClosed() {
		return gameEvent.type == sf::Event::Closed;
	}

	bool EventService::hasQuitGame() {
		return isKeyboardEvent() && pressedEscapeKey();
	}
	void EventService::updateButtonState(ButtonState& button_state_current, sf::Mouse::Button button_mouse) {
		if( sf::Mouse::isButtonPressed(button_mouse) )
		{
			switch( button_state_current )
			{
				case ButtonState::PRESSED:
					button_state_current = ButtonState::HELD;
					break;
				case ButtonState::RELEASED:
					button_state_current = ButtonState::PRESSED;
					break;
			}
		}
		else
		{
			button_state_current = ButtonState::RELEASED;
		}
	}

	void EventService::updateButtonState(ButtonState& button_state_current, sf::Keyboard::Key button_keyboard) {
		if( sf::Keyboard::isKeyPressed(button_keyboard) )
		{
			switch( button_state_current )
			{
				case ButtonState::PRESSED:
					button_state_current = ButtonState::HELD;
					break;
				case ButtonState::RELEASED:
					button_state_current = ButtonState::PRESSED;
					break;
			}
		}
		else
		{
			button_state_current = ButtonState::RELEASED;
		}
	}
}