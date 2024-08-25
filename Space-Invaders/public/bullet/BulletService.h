#pragma once
#include "vector"
#include "SFML/System/Vector2.hpp"

namespace Projectile {
	enum class ProjectileDirection;
	class IProjectile;
}

namespace Bullet {
	enum class BulletType;

	class BulletService {
	private:

		std::vector<Projectile::IProjectile*> m_projectiles_list;

		Projectile::IProjectile* createBullet(BulletType type);
		void destroy();

	public:

		BulletService();
		~BulletService();

		void initialize();
		void update();
		void render();

		void spawnBullet(BulletType type, sf::Vector2f position, Projectile::ProjectileDirection direction);

		void destroyBullet(Projectile::IProjectile* bullet);

	};
}
