#include "./../../public/player/PlayerView.h"

#include "../../public/global/Config.h"
#include "./../../public/global/ServiceLocator.h"
#include "./../../public/player/PlayerController.h"
#include "./../../public/graphic/GraphicService.h"
#include "./../../public/ui/UIElement/ImageView.h"


namespace Player {
	using namespace Global;

	PlayerView::PlayerView() {
		m_game_window = nullptr;
		m_player_controller = nullptr;
		m_player_image = nullptr;
	}

	PlayerView::~PlayerView() {
		delete m_player_image;
	}

	void PlayerView::initialize(PlayerController* controller) {
		m_player_controller = controller;
		m_game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		createPlayerSprite();
	}

	void PlayerView::update() {
		// setting the updated sprite position from playercontroller
		m_player_image->setPosition(m_player_controller->getPlayerPosition());
	}

	void PlayerView::render() {
		m_player_image->render();
	}

	void PlayerView::createPlayerSprite() {
		m_player_image = new UI::UIElement::ImageView();
		m_player_image->initialize(Config::player_texture_path, m_sprite_width, m_sprite_height, m_player_controller->getPlayerPosition());
		m_player_image->setOriginAtCentre();
	}

	sf::FloatRect PlayerView::getLocalBounds() {
		return m_player_image->getLocalBounds();
	}
}
