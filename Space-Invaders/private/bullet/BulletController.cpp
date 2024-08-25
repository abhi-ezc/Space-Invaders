#include "./../../public/bullet/BulletController.h"
#include "../../public/global/ServiceLocator.h"
#include "../../public/graphic/GraphicService.h"
#include "../../public/time/TimeService.h"
#include  "./../../public/bullet/BulletModel.h"
#include  "./../../public/bullet/BulletView.h"
#include "./../../public/bullet/BulletConfig.h"
#include "./../../public/projectile/ProjectileConfig.h"
#include "./../../public/global/ServiceLocator.h"
#include "./../../public/bullet/BulletService.h"

namespace Bullet {
	BulletController::BulletController(BulletType type) {
		m_bullet_model = new BulletModel(type);
		m_bullet_view = new BulletView(this);
	}

	BulletController::~BulletController() {
		delete m_bullet_model;
		delete m_bullet_view;
	}

	void BulletController::initialize(sf::Vector2f position, Projectile::ProjectileDirection direction) {
		m_bullet_model->initialize(position, direction);
		m_bullet_view->initialize();
	}

	void BulletController::update() {
		updateProjectilePosition();
		m_bullet_model->update();
		m_bullet_view->update();
		handleOutOfBounds();
	}

	void BulletController::render() {
		m_bullet_model->render();
		m_bullet_view->render();
	}

	sf::Vector2f BulletController::getProjectilePosition() {
		return m_bullet_model->getBulletPosition();
	}

	BulletType BulletController::getBulletType() {
		return m_bullet_model->getBulletType();
	}

	void BulletController::handleOutOfBounds() {
		auto position = getProjectilePosition();
		auto windowSize = Global::ServiceLocator::getInstance()->getGraphicService()->getGameWindow()->getSize();

		if (position.x < 0 || position.x > windowSize.x || position.y < 0 || position.y > windowSize.y) {
			Global::ServiceLocator::getInstance()->getBulletService()->destroyBullet(this);
		}
	}

	void BulletController::updateProjectilePosition() {
		switch (m_bullet_model->getBulletDirection()) {
		case Projectile::ProjectileDirection::UP:
			moveUp();
			break;
		case Projectile::ProjectileDirection::DOWN:
			moveDown();
			break;
		}
	}

	void BulletController::moveUp() {
		auto position = m_bullet_model->getBulletPosition();

		const auto speed = m_bullet_model->getBulletSpeed() * Global::ServiceLocator::getInstance()->getTimeService()->
			getDeltaTime();

		position.y = position.y - speed;

		m_bullet_model->setBulletPosition(position);
	}

	void BulletController::moveDown() {
		auto position = m_bullet_model->getBulletPosition();

		const auto speed = m_bullet_model->getBulletSpeed() * Global::ServiceLocator::getInstance()->getTimeService()->
			getDeltaTime();

		position.y = position.y + speed;

		m_bullet_model->setBulletPosition(position);
	}

	void BulletController::setBulletSpeed(float speed) {
		m_bullet_model->setBulletSpeed(speed);
	}
}
