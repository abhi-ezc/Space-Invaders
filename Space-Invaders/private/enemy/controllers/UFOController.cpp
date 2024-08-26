#include "../../../public/enemy/controllers/UFOController.h"

#include "../../../public/enemy/EnemyConfig.h"
#include "../../../public/enemy/EnemyModel.h"
#include "../../../public/global/ServiceLocator.h"
#include "../../../public/time/TimeService.h"
#include "../../../public/bullet/BulletService.h"
#include "../../../public/bullet/BulletConfig.h"
#include "../../../public/projectile/ProjectileConfig.h"

namespace Enemy {
	namespace Controllers {
		using namespace Global;

		UFOController::UFOController() : EnemyController(EnemyType::UFO) {}
		UFOController::~UFOController() {}

		void UFOController::initialize() {
			EnemyController::initialize();
			m_enemy_model->setMovementDirection(MovementDirection::RIGHT);
		}

		void UFOController::move() {
			switch (m_enemy_model->getMovementDirection()) {
			case MovementDirection::RIGHT:
				moveRight();
				break;
			case MovementDirection::LEFT:
				moveLeft();
				break;
			default:
				break;
			}
		}

		void UFOController::moveLeft() {
			sf::Vector2f position = getPosition();
			position.x -= m_enemy_model->getMovementSpeed() * ServiceLocator::getInstance()->getTimeService()->
				getDeltaTime();
			if (position.x < m_enemy_model->getLeftMostPosition().x) {
				m_enemy_model->setMovementDirection(MovementDirection::RIGHT);
			} else {
				m_enemy_model->setCurrentPosition(position);
			}
		}

		void UFOController::moveRight() {
			sf::Vector2f position = getPosition();
			position.x += m_enemy_model->getMovementSpeed() * ServiceLocator::getInstance()->getTimeService()->
				getDeltaTime();
			if (position.x > m_enemy_model->getRightMostPosition().x) {
				m_enemy_model->setMovementDirection(MovementDirection::LEFT);
			} else {
				m_enemy_model->setCurrentPosition(position);
			}
		}

	}
}
