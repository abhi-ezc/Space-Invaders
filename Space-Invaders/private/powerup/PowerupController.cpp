#include "./../../public/powerup/PowerupController.h"
#include "./../../public/powerup/PowerupModel.h"
#include "./../../public/powerup/PowerupView.h"
#include "./../../public/powerup/PowerupConfig.h"
#include "./../../public/global/ServiceLocator.h"
#include "./../../public/graphic/GraphicService.h"
#include "./../../public/powerup/PowerupService.h"

namespace Powerup {
	PowerupController::PowerupController(PowerupType type) {
		m_powerup_model = new PowerupModel(type);
		m_powerup_view = new PowerupView(this);
	}

	PowerupController::~PowerupController() {
		delete m_powerup_model;
		delete m_powerup_view;
	}

	void PowerupController::initialize(sf::Vector2f position) {
		m_powerup_model->initialize(position);
		m_powerup_view->initialize();
	}

	void PowerupController::update() {
		m_powerup_model->update();
		m_powerup_view->update();
		handleOutOfBounds();
	}

	void PowerupController::render() {
		m_powerup_model->render();
		m_powerup_view->render();
	}

	sf::Vector2f PowerupController::getCollectiblePosition() {
		return m_powerup_model->getPosition();
	}

	PowerupType PowerupController::getPowerupType() {
		return m_powerup_model->getType();
	}

	void PowerupController::handleOutOfBounds() {
		auto windowSize = Global::ServiceLocator::getInstance()->getGraphicService()->getGameWindow()->getSize();
		auto position = getCollectiblePosition();

		if (position.x < 0 || position.x > windowSize.x || position.y < 0 || position.y > windowSize.y) {

			Global::ServiceLocator::getInstance()->getPowerupService()->destroyPowerup(this);
		}
	}


}
