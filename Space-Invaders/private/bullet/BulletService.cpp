#include "./../../public/bullet/BulletService.h"
#include "./../../public/projectile/IProjectile.h"
#include "./../../public/projectile/ProjectileConfig.h"
#include "./../../public/bullet/BulletConfig.h"

#include "./../../public/bullet/controllers/FrostBulletController.h"
#include "./../../public/bullet/controllers/LaserBulletController.h"
#include "./../../public/bullet/controllers/TorpedoController.h"

namespace Bullet {

	BulletService::BulletService() {}

	BulletService::~BulletService() {
		destroy();
	}

	void BulletService::initialize() {}

	void BulletService::update() {
		for (auto bulletController : m_projectiles_list) {
			bulletController->update();
		}
	}

	void BulletService::render() {
		for (auto bulletController : m_projectiles_list) {
			bulletController->render();
		}
	}

	void BulletService::destroy() {
		for (auto bulletController : m_projectiles_list) {
			delete bulletController;
		}

		m_projectiles_list.clear();
	}

	void BulletService::spawnBullet(BulletType type, sf::Vector2f position, Projectile::ProjectileDirection direction) {
		auto bulletController = createBullet(type);
		bulletController->initialize(position, direction);
		m_projectiles_list.push_back(bulletController);
	}

	Projectile::IProjectile* BulletService::createBullet(BulletType type) {
		switch (type) {
		case BulletType::LASER:
			return new Controllers::LaserBulletController();
		case BulletType::FROST:
			return new Controllers::FrostBulletController();
		case BulletType::TORPEDO:
			return new Controllers::TorpedoController();
		}
	}


	void BulletService::destroyBullet(Projectile::IProjectile* bullet) {

		m_projectiles_list.erase(
			std::remove(m_projectiles_list.begin(), m_projectiles_list.end(), bullet),
			m_projectiles_list.end());

		delete bullet;
	}




}
