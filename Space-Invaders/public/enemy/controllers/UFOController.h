#pragma once
#include "../EnemyController.h"

namespace Collectible {
	class ICollectible;
}

namespace Enemy {
	namespace Controllers {
		class UFOController : public EnemyController {
		private:
			void moveLeft();
			void moveRight();
		public:
			UFOController();
			~UFOController() override;
			void initialize() override;
			void move() override;

			void spawnRandomPowerup();

		};
	}
}
