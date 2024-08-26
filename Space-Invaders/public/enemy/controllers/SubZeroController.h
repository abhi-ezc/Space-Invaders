#pragma once
#include "../EnemyController.h"

namespace Enemy {
	namespace Controllers {
		class SubZeroController : public EnemyController {
		private:
			float m_vertical_movement_speed = 100.f;
			void move() override;
			void moveDown();
		public:
			SubZeroController();
			~SubZeroController() override;

			void initialize() override;
		};
	}
}
