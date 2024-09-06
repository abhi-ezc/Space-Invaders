#pragma once
#include "../BulletController.h"

namespace Projectile {
	enum class ProjectileDirection;
}

namespace Entity {
	enum class EntityType;
}

namespace Bullet {
	enum class BulletType;

	namespace Controllers {
		class LaserBulletController : public BulletController {
		public:
			LaserBulletController(Entity::EntityType ownerEntityType);
			~LaserBulletController() override;

			void initialize(sf::Vector2f position, Projectile::ProjectileDirection direction) override;
		};
	}
}
