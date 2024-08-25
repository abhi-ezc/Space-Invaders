#pragma once
#include "SFML/System/Vector2.hpp"
#include "./../BulletController.h"

namespace Projectile {
	enum class ProjectileDirection;
}

namespace Bullet {
	namespace Controllers {
		class TorpedoController : public BulletController {
		public:

			TorpedoController();
			~TorpedoController() override;

			const float m_movement_speed = 200.f;

			void initialize(sf::Vector2f position, Projectile::ProjectileDirection direction)override;
		};
	}
}