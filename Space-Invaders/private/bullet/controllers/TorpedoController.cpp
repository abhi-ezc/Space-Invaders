#include "./../../../public/bullet/controllers/TorpedoController.h"
#include "./../../../public/bullet/BulletConfig.h"
#include "./../../../public/bullet/BulletModel.h"

namespace Bullet {
	namespace Controllers {
		TorpedoController::TorpedoController() :BulletController(BulletType::TORPEDO) {}

		TorpedoController::~TorpedoController() = default;

		void TorpedoController::initialize(sf::Vector2f position, Projectile::ProjectileDirection direction) {
			BulletController::initialize(position, direction);
			setBulletSpeed(m_movement_speed);

		}
	}
}