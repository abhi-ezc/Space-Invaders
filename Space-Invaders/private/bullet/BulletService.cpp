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
		invokeLifecycle(Projectile::ProjectileLifecycle::UPDATE);
	}

	void BulletService::render() {
		invokeLifecycle(Projectile::ProjectileLifecycle::RENDER);
	}

	void BulletService::destroy() {
		invokeLifecycle(Projectile::ProjectileLifecycle::DESTROY);
		m_projectiles_list.clear();
	}

	void BulletService::invokeLifecycle(Projectile::ProjectileLifecycle lifecycle) {

		for (int i = 0; i < m_projectiles_list.size(); i++) {
			auto bulletController = m_projectiles_list[i];

			if (bulletController == nullptr) {
				continue;
			}

			switch (lifecycle) {
			case Projectile::ProjectileLifecycle::INIT:
				break;
			case Projectile::ProjectileLifecycle::UPDATE:
				bulletController->update();
				break;
			case Projectile::ProjectileLifecycle::RENDER:
				bulletController->render();
				break;
			case Projectile::ProjectileLifecycle::DESTROY:
				delete bulletController;
				break;
			}
		}
	}

	void BulletService::spawnBullet(BulletType type, sf::Vector2f position, Projectile::ProjectileDirection direction, Entity::EntityType ownerEntityType) {
		auto bulletController = createBullet(type, ownerEntityType);
		bulletController->initialize(position, direction);
		m_projectiles_list.push_back(bulletController);
	}

	Projectile::IProjectile* BulletService::createBullet(BulletType type, Entity::EntityType ownerEntityType) {
		switch (type) {
		case BulletType::LASER:
			return new Controllers::LaserBulletController(ownerEntityType);
		case BulletType::FROST:
			return new Controllers::FrostBulletController(ownerEntityType);
		case BulletType::TORPEDO:
			return new Controllers::TorpedoController(ownerEntityType);
		default:
			return nullptr;
		}
	}


	void BulletService::destroyBullet(Projectile::IProjectile* bullet) {

		m_projectiles_list.erase(
			std::remove(m_projectiles_list.begin(), m_projectiles_list.end(), bullet),
			m_projectiles_list.end());

		delete bullet;
	}




}
