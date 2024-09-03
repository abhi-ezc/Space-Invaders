#include "./../../../public/ui/UIElement/UIView.h"
#include "./../../../public/global/ServiceLocator.h"
#include "./../../../public/graphic/GraphicService.h"
namespace UI {
	namespace UIElement {
		UIView::UIView() = default;

		UIView::~UIView() = default;

		void UIView::initialize() {
			m_game_window = Global::ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
			m_ui_state = UIState::VISIBLE;
		}

		void UIView::update() {}

		void UIView::render() {
			if (m_ui_state == UIState::VISIBLE) {
				Global::ServiceLocator::getInstance()->getGraphicService()->draw(getDrawable());
			}
		}

		void UIView::show() {
			m_ui_state = UIState::VISIBLE;
		}

		void UIView::hide() {
			m_ui_state = UIState::HIDDEN;
		}

	}
}