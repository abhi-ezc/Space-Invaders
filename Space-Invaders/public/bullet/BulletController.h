#pragma once
#include "./../projectile/IProjectile.h"
#include "./../collision/ColliderController.h"

namespace Projectile {
	enum class ProjectileDirection;
}

namespace Entity {
	enum class EntityType;
}

namespace Bullet {
	class BulletModel;
	class BulletView;

	enum class BulletType;

	class BulletController : public Projectile::IProjectile, public Collision::ColliderController {
	private:
		BulletModel* m_bullet_model;
		BulletView* m_bullet_view;

		void moveUp();
		void moveDown();

	protected:
		void setBulletSpeed(float speed);

	public:
		BulletController(BulletType type, Entity::EntityType ownerEntityType);
		~BulletController() override;

		void initialize(sf::Vector2f position, Projectile::ProjectileDirection direction) override;
		void update() override;
		void render() override;

		sf::Vector2f getProjectilePosition() override;
		BulletType getBulletType();
		Entity::EntityType getOwnerEntity();

		void updateProjectilePosition() override;
		void handleOutOfBounds();

		const sf::Sprite& getColliderSprite()override;
		Entity::EntityType getEntityType() override;
		void onCollision(ICollider* otherCollider) override;
	};
}
