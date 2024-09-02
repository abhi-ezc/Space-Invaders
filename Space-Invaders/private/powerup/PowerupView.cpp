#include "./../../public/powerup/PowerupView.h"
#include "./../../public/powerup/PowerupController.h"
#include "./../../public/powerup/PowerupConfig.h"
#include "./../../public/global/Config.h"
#include "./../../public/global/ServiceLocator.h"
#include "./../../public/graphic/GraphicService.h"
#include "./../../public/ui/UIElement/ImageView.h"

namespace Powerup {

	PowerupView::PowerupView(PowerupController* controller) {
		m_controller = controller;
		m_powerup_image = new UI::UIElement::ImageView();
	}

	PowerupView::~PowerupView() {
		delete(m_powerup_image);
	};

	void PowerupView::initialize() {
		loadTexture(m_controller->getPowerupType());
		m_powerup_image->initialize(m_powerup_texture_path, width, height, m_controller->getCollectiblePosition());
	}

	void PowerupView::update() {
		m_powerup_image->setPosition(m_controller->getCollectiblePosition());
	}

	void PowerupView::render() {
		m_powerup_image->render();
	}

	void PowerupView::loadTexture(PowerupType type) {

		switch (type) {
		case PowerupType::SHIELD:
			m_powerup_texture_path = Global::Config::shield_texture_path;
			break;
		case PowerupType::TRIPPLE_LASER:
			m_powerup_texture_path = Global::Config::tripple_laser_texture_path;
			break;
		case PowerupType::RAPID_FIRE:
			m_powerup_texture_path = Global::Config::rapid_fire_texture_path;
			break;
		case PowerupType::OUTSCAL_BOMB:
			m_powerup_texture_path = Global::Config::outscal_bomb_texture_path;
			break;
		}
	}
}
