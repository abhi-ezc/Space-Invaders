#include "./../../public/enemy/EnemyController.h"

#include "../../public/enemy/EnemyService.h"
#include "../../public/graphic/GraphicService.h"
#include "../../public/time/TimeService.h"
#include "./../../public/enemy/EnemyModel.h"
#include "./../../public/enemy/EnemyView.h"
#include "./../../public/global/ServiceLocator.h"
#include "./../../public/enemy/EnemyConfig.h"
#include "SFML/System/Clock.hpp"
#include "./../../public/projectile/ProjectileConfig.h"
#include "./../../public/bullet/BulletService.h"

namespace Enemy {
	using namespace Global;

	EnemyController::EnemyController(EnemyType type) {
		std::srand(static_cast<unsigned>(std::chrono::high_resolution_clock::now().time_since_epoch().count()));
		m_enemy_model = new EnemyModel(type);
		m_enemy_view = new EnemyView();
	}

	EnemyController::~EnemyController() {
		delete m_enemy_model;
		delete m_enemy_view;
	};

	void EnemyController::initialize() {
		m_enemy_model->initialize(this);
		m_enemy_view->initialize(this);
	}

	void EnemyController::update() {
		move();
		updateFireTimer();
		m_enemy_model->update();
		m_enemy_view->update();
		handleOutOfBounds();
	}

	void EnemyController::render() {
		m_enemy_model->render();
		m_enemy_view->render();
	}

	sf::Vector2f EnemyController::getPosition() {
		return m_enemy_model->getCurrentPosition();
	}

	EnemyType EnemyController::getEnemyType() {
		return m_enemy_model->getEnemyType();
	}

	EnemyState EnemyController::getEnemyState() {
		return m_enemy_model->getEnemyState();
	}

	sf::Vector2f EnemyController::getRandomInitialPosition() {
		float randomX = m_enemy_model->getLeftMostPosition().x + static_cast<float>(std::rand() %
			static_cast<int>(m_enemy_model->
				getRightMostPosition().x -
				m_enemy_model->getLeftMostPosition().x + 1));

		return { randomX, m_enemy_model->getLeftMostPosition().y };
	}

	void EnemyController::handleOutOfBounds() {
		const sf::Vector2u windowSize = ServiceLocator::getInstance()->getGraphicService()->getGameWindow()->getSize();
		const sf::Vector2f position = getPosition();

		if (position.x < 0 || position.y < 0 || position.x > windowSize.x || position.y > windowSize.y) {
			ServiceLocator::getInstance()->getEnemyService()->destroyEnemy(this);
		}
	}

	void EnemyController::updateFireTimer() {

		if (m_enemy_model->getCanFire()) {
			if (m_enemy_model->getElapsedFireTime() >= m_enemy_model->getFireDelay()) {
				processBulletFire();
				m_enemy_model->setElapsedFireTime(0);
			} else {
				float newElapsedTime = m_enemy_model->getElapsedFireTime() + ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
				m_enemy_model->setElapsedFireTime(newElapsedTime);
			}
		}

	}

	void EnemyController::processBulletFire() {
		fireBullet();
	}
	void EnemyController::fireBullet() {
		sf::Vector2f bulletSpawnPosition = getPosition();
		auto offset = m_enemy_model->getMuzzleOffset();

		bulletSpawnPosition.x += (m_enemy_view->getSpriteSize().x / 2) + offset.x;
		bulletSpawnPosition.y += (m_enemy_view->getSpriteSize().y / 2) + offset.y;
		ServiceLocator::getInstance()->getBulletService()->spawnBullet(m_enemy_model->getBulletType(), bulletSpawnPosition, Projectile::ProjectileDirection::DOWN);
	}
}
