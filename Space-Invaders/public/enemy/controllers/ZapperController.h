#pragma once
#include "../EnemyController.h"

namespace Enemy {
	namespace Controllers {
		class ZapperController : public EnemyController {
		private:
			float m_vertical_travel_distance = 100.f;
			void move() override;
			void moveLeft();
			void moveRight();
			void moveDown();

		public:
			ZapperController();
			~ZapperController() override;

			void initialize() override;
		};
	}
}
