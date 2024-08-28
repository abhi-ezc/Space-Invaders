#include "../../../public/enemy/controllers/UFOController.h"
#include "../../../public/enemy/EnemyConfig.h"
#include "../../../public/enemy/EnemyModel.h"
#include "../../../public/global/ServiceLocator.h"
#include "../../../public/time/TimeService.h"
#include "../../../public/bullet/BulletService.h"
#include "../../../public/bullet/BulletConfig.h"
#include "../../../public/projectile/ProjectileConfig.h"
#include "../../../public/powerup/PowerupConfig.h"
#include "../../../public/powerup/PowerupService.h"

namespace Enemy {
	namespace Controllers {
		using namespace Global;

		UFOController::UFOController() : EnemyController(EnemyType::UFO) {}
		UFOController::~UFOController() {
			spawnRandomPowerup();
		}

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

		void UFOController::spawnRandomPowerup() {
			auto randomPowerType = static_cast<Powerup::PowerupType>(rand() % 4);
			Global::ServiceLocator::getInstance()->getPowerupService()->spawnPowerup(randomPowerType, getPosition());
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
