#include "./../../public/powerup/PowerupService.h"
#include "./../../public/global/Config.h"
#include "./../../public/collectible/ICollectible.h"
#include "./../../public/powerup/PowerupConfig.h"
#include "./../../public/powerup/controllers/OutscalBombController.h"
#include "./../../public/powerup/controllers/RapidFireController.h"
#include "./../../public/powerup/controllers/ShieldController.h"
#include "./../../public/powerup/controllers/TrippleLaserController.h"


namespace Powerup {

	PowerupService::PowerupService() = default;

	PowerupService::~PowerupService() {
		destroy();
	}

	void PowerupService::initialize() {}

	void PowerupService::update() {
		executeLifecycle(Global::LifeCycle::UPDATE);
	}

	void PowerupService::render() {
		executeLifecycle(Global::LifeCycle::RENDER);
	}

	void PowerupService::destroy() {
		executeLifecycle(Global::LifeCycle::DESTROY);
		m_collectibles_list.clear();
	}

	void PowerupService::executeLifecycle(Global::LifeCycle state) {
		for (int i = 0; i < m_collectibles_list.size(); i++) {
			auto collectible = m_collectibles_list[i];
			if (collectible == nullptr) {
				continue;
			}

			switch (state) {
			case Global::LifeCycle::INIT:
				break;
			case Global::LifeCycle::UPDATE:
				collectible->update();
				break;
			case Global::LifeCycle::RENDER:
				collectible->render();
				break;
			case Global::LifeCycle::DESTROY:
				delete collectible;
				break;
			}
		}
	}

	void PowerupService::spawnPowerup(PowerupType type, sf::Vector2f position) {
		auto controller = createPowerup(type);
		controller->initialize(position);
	}

	void PowerupService::destroyPowerup(Collectible::ICollectible* powerup) {
		m_collectibles_list.erase(
			std::remove(m_collectibles_list.begin(), m_collectibles_list.end(), powerup),
			m_collectibles_list.end());

		delete powerup;
	}

	Collectible::ICollectible* PowerupService::createPowerup(PowerupType type) {
		switch (type) {
		case PowerupType::SHIELD:
			return new Controller::ShieldController();

		case PowerupType::RAPID_FIRE:
			return new Controller::RapidFireController();

		case PowerupType::OUTSCAL_BOMB:
			return new Controller::OutscalBombController();

		case PowerupType::TRIPPLE_LASER:
			return new Controller::ShieldController();
		}
	}

}


