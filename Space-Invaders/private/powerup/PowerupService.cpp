#include "./../../public/powerup/PowerupService.h"
#include "./../../public/global/Config.h"
#include "./../../public/collectible/ICollectible.h"
#include "./../../public/powerup/PowerupConfig.h"


namespace Powerup {

	PowerupService::PowerupService() {}

	PowerupService::~PowerupService() {}

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

	void PowerupService::spawnPowerup(PowerupType type, sf::Vector2f position) {}

	void PowerupService::destroyPowerup(Collectible::ICollectible* powerup) {}

	Collectible::ICollectible* PowerupService::createPowerup(PowerupType type) {
		return nullptr;
	}

}


