#include "../../../public/enemy/controllers/SubZeroController.h"
#include "../../../public/enemy/EnemyConfig.h"
#include "../../../public/enemy/EnemyModel.h"
#include "../../../public/global/ServiceLocator.h"
#include "../../../public/time/TimeService.h"
#include "../../../public/bullet/BulletService.h"
#include "../../../public/bullet/BulletConfig.h"
#include "../../../public/projectile/ProjectileConfig.h"
#include "../../../public/enemy/EnemyView.h"

namespace Enemy {
	namespace Controllers {
		using namespace Global;

		SubZeroController::SubZeroController() : EnemyController(EnemyType::SUBZERO) {}

		SubZeroController::~SubZeroController() {}

		void SubZeroController::initialize() {
			EnemyController::initialize();
			m_enemy_model->setMovementDirection(MovementDirection::DOWN);
		}

		void SubZeroController::move() {
			switch (m_enemy_model->getMovementDirection()) {
			case MovementDirection::DOWN:
				moveDown();
				break;
			default:
				break;
			}
		}

		void SubZeroController::moveDown() {
			sf::Vector2f position = m_enemy_model->getCurrentPosition();
			position.y += m_vertical_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
			m_enemy_model->setCurrentPosition(position);
		}
	}
}
