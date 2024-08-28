#pragma once

#include <vector>
#include "SFML/System/Vector2.hpp"

namespace Collectible {
	class ICollectible;
}

namespace Global {
	enum class LifeCycle;
}

namespace Powerup {

	enum class PowerupType;

	class PowerupService {

	private:
		std::vector<Collectible::ICollectible*> m_collectibles_list;

		Collectible::ICollectible* createPowerup(PowerupType type);

		void destroy();

		void executeLifecycle(Global::LifeCycle state);


	public:
		PowerupService();
		~PowerupService();

		void initialize();
		void update();
		void render();

		void spawnPowerup(PowerupType type, sf::Vector2f position);
		void destroyPowerup(Collectible::ICollectible* powerup);

	};
}