#include "./../../public/powerup/PowerupView.h"
#include "./../../public/powerup/PowerupController.h"
#include "./../../public/powerup/PowerupConfig.h"
#include "./../../public/global/Config.h"
#include "./../../public/global/ServiceLocator.h"
#include "./../../public/graphic/GraphicService.h"

namespace Powerup {

	PowerupView::PowerupView(PowerupController* controller) {
		m_controller = controller;
	}

	PowerupView::~PowerupView() = default;

	void PowerupView::initialize() {
		loadTexture(m_controller->getPowerupType());
		initSprite();
	}

	void PowerupView::update() {
		m_powerup_sprite.setPosition(m_controller->getCollectiblePosition());
	}

	void PowerupView::render() {
		Global::ServiceLocator::getInstance()->getGraphicService()->draw(m_powerup_sprite);
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

	void PowerupView::initSprite() {
		if (m_powerup_texture.loadFromFile(m_powerup_texture_path)) {
			m_powerup_sprite.setTexture(m_powerup_texture);
			scaleSprite();
		}
	}

	void PowerupView::scaleSprite() {
		float spriteWidth = width / m_powerup_sprite.getTexture()->getSize().x;
		float spriteHeight = height / m_powerup_sprite.getTexture()->getSize().y;
		m_powerup_sprite.setScale(sf::Vector2f(spriteWidth, spriteHeight));
	}

}
