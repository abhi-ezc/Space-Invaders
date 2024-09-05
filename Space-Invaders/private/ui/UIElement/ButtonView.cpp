#include "./../../public/ui/UIElement/ButtonView.h"
#include "./../../public/ui/UIElement/ImageView.h"
#include "./../../public/global/ServiceLocator.h"
#include "./../../public/event/EventService.h"

namespace UI {

	namespace UIElement {
		ButtonView::ButtonView() {}

		ButtonView::~ButtonView() {}

		void ButtonView::initialize(sf::String title, sf::String texturePath, float width, float height, sf::Vector2f position) {
			ImageView::initialize(texturePath, width, height, position);
			m_button_title = title;
		}

		void ButtonView::update() {
			ImageView::update();
			if (m_ui_state == UIState::VISIBLE) {
				handleButtonInteraction();
			}
		}

		void ButtonView::render() {
			ImageView::render();
		}

		void ButtonView::registerCallbackFunction(CallbackFunction callback) {
			m_click_handler = callback;
		}

		void ButtonView::handleButtonInteraction() {
			sf::Vector2f mouse_position = sf::Vector2f(sf::Mouse::getPosition(*m_game_window));
			if (clickedButton(&m_sprite, mouse_position)) {
				if (m_click_handler) {
					m_click_handler();
				}
			}

		}

		bool ButtonView::clickedButton(sf::Sprite* buttonSprite, sf::Vector2f mousePosition) {
			return Global::ServiceLocator::getInstance()->getEventService()->isLeftMouseButtonPressed() && buttonSprite->getGlobalBounds().contains(mousePosition);
		}

		void ButtonView::printButtonClicked() {
			printf("Clicked %s\n", m_button_title.toAnsiString().c_str());
		}
	}
}