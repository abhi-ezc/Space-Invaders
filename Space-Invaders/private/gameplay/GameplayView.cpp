#include "./../../public/gameplay/GameplayView.h"
#include "../../public/graphic/GraphicService.h"
#include "./../../public/global/ServiceLocator.h"
#include "./../../public/global/Config.h"
#include "./../../public/ui/UIElement/ImageView.h"


namespace Gameplay {
	using namespace Global;

	GameplayView::GameplayView() {
		m_background_image = nullptr;
	};

	GameplayView::~GameplayView() = default;

	void GameplayView::initialize() {
		initializeBackgroundImage();
	}

	void GameplayView::update() {
		m_background_image->update();
	}

	void GameplayView::render() {
		m_background_image->render();
	}

	void GameplayView::initializeBackgroundImage() {
		const sf::RenderWindow* gameWindow = Global::ServiceLocator::getInstance()->getGraphicService()->
			getGameWindow();

		const sf::Vector2f size = static_cast<sf::Vector2f>(gameWindow->getSize());

		m_background_image = new UI::UIElement::ImageView();

		m_background_image->initialize(Config::background_texture_path, size.x, size.y, sf::Vector2f(0, 0));
	}
}
