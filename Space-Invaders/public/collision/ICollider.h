#pragma once
#include "SFML/Graphics/Sprite.hpp"

namespace Collision {
	enum class CollisionState {
		ENABLED,
		DISABLED
	};

	class ICollider {
	private:
		CollisionState m_collision_state;

	public:
		virtual ~ICollider() = default;
		virtual const sf::Sprite& getColliderSprite() = 0;
		virtual void onCollision(ICollider* otherCollider) = 0;
		virtual void enableCollision() = 0;
		virtual void disableCollision() = 0;
		virtual CollisionState getCollisionState() = 0;
	};
}
