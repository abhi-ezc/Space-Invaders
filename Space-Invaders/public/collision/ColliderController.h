#pragma once
#include "./ICollider.h"
namespace Collision {
	class ColliderController : public ICollider {
	private:
		CollisionState m_collision_state;

	public:
		ColliderController();
		virtual ~ColliderController() override;
		virtual const sf::Sprite& getColliderSprite() override = 0;
		virtual void onCollision(ICollider* otherCollider) override = 0;
		virtual Entity::EntityType getEntityType() override = 0;

		void enableCollision() override;
		void disableCollision() override;
		CollisionState getCollisionState() override;

	};
}
