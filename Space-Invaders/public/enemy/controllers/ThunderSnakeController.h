#pragma once
#include "../EnemyController.h"

namespace Enemy {
	enum class MovementDirection;

	namespace Controllers {
		class ThunderSnakeController : public EnemyController {
		private:
			float m_vertical_travel_speed = 50.f;
			void moveLeft();
			void moveRight();
			MovementDirection getRandomSideDirection();
		public:
			ThunderSnakeController();
			~ThunderSnakeController() override;

			void move() override;
			void initialize() override;
		};
	}
}
