#include "./../../../public/bullet/controllers/FrostBulletController.h"
#include "./../../../public/bullet/BulletConfig.h"
#include "./../../../public/projectile/ProjectileConfig.h"

namespace Bullet {
	namespace Controllers {
		FrostBulletController::FrostBulletController() :BulletController(BulletType::FROST) {

		}

		FrostBulletController::~FrostBulletController() {

		}

		void FrostBulletController::initialize(sf::Vector2f position, Projectile::ProjectileDirection direction) {
			BulletController::initialize(position, direction);
			setBulletSpeed(m_movement_speed);
		}
	}
}