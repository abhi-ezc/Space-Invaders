#pragma once
#include "./../../../public/bullet/BulletController.h"

namespace Projectile {
	enum class ProjectileDirection;
}

namespace Bullet {
	namespace Controllers {
		class FrostBulletController : public BulletController {
		private:
			const float m_movement_speed = 500.f;
		public:
			FrostBulletController();
			~FrostBulletController() override;

			void initialize(sf::Vector2f position, Projectile::ProjectileDirection direction) override;
		};
	}
}