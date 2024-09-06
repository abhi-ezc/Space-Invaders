#include "../../../public/enemy/controllers/ZapperController.h"
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

		ZapperController::ZapperController() : EnemyController(EnemyType::ZAPPER) {}

		ZapperController::~ZapperController() {}

		void ZapperController::initialize() {
			EnemyController::initialize();
			m_enemy_model->setMovementDirection(MovementDirection::RIGHT);
		}

		void ZapperController::move() {
			switch (m_enemy_model->getMovementDirection()) {
			case MovementDirection::RIGHT:
				moveRight();
				break;
			case MovementDirection::LEFT:
				moveLeft();
				break;
			case MovementDirection::DOWN:
				moveDown();
				break;
			}
		}

		void ZapperController::moveLeft() {
			sf::Vector2f position = m_enemy_model->getCurrentPosition();
			position.x -= m_enemy_model->getMovementSpeed() * ServiceLocator::getInstance()->getTimeService()->
				getDeltaTime();
			if (position.x < m_enemy_model->getLeftMostPosition().x) {
				m_enemy_model->setReferencePosition(position);
				m_enemy_model->setPreviousDirection(MovementDirection::LEFT);
				m_enemy_model->setMovementDirection(MovementDirection::DOWN);
			} else {
				m_enemy_model->setCurrentPosition(position);
			}
		}

		void ZapperController::moveRight() {
			sf::Vector2f position = m_enemy_model->getCurrentPosition();
			position.x += m_enemy_model->getMovementSpeed() * ServiceLocator::getInstance()->getTimeService()->
				getDeltaTime();
			if (position.x > m_enemy_model->getRightMostPosition().x) {
				m_enemy_model->setReferencePosition(position);
				m_enemy_model->setPreviousDirection(MovementDirection::RIGHT);
				m_enemy_model->setMovementDirection(MovementDirection::DOWN);
			} else {
				m_enemy_model->setCurrentPosition(position);
			}
		}

		void ZapperController::moveDown() {
			sf::Vector2f position = m_enemy_model->getCurrentPosition();
			position.y += m_enemy_model->getMovementSpeed() * ServiceLocator::getInstance()->getTimeService()->
				getDeltaTime();
			if (position.y >= m_enemy_model->getReferencePosition().y + m_vertical_travel_distance) {
				m_enemy_model->setMovementDirection(m_enemy_model->getPreviousDirection() ==
					MovementDirection::RIGHT
					? MovementDirection::LEFT
					: MovementDirection::RIGHT);
			} else {
				m_enemy_model->setCurrentPosition(position);
			}
		}

	}
}
