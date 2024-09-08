#include "./../../public/collision/CollisionService.h"
#include "./../../public/collision/ICollider.h"

namespace Collision {
	CollisionService::CollisionService() = default;

	CollisionService::~CollisionService() {}

	void CollisionService::initialize() {}

	void CollisionService::update() {
		printf("\rvector size: %d\n", m_colliders.size());
		processCollision();
	}

	void CollisionService::render() {}

	void CollisionService::addCollider(ICollider* collider) {
		m_colliders.push_back(collider);
	}

	void CollisionService::removeCollider(ICollider* collider) {
		m_colliders.erase(std::remove(
			m_colliders.begin(),
			m_colliders.end(),
			collider
		), m_colliders.end());
	}

	void CollisionService::destroy() {
		for (int i = 0; i < m_colliders.size(); i++) {
			if (m_colliders[i] != nullptr) {
				delete m_colliders[i];
			}
		}
		m_colliders.clear();
	}

	void CollisionService::processCollision() {
		for (int i = 0; i < m_colliders.size(); i++) {
			for (int j = i + 1; j < m_colliders.size(); j++) {
				doCollision(i, j);
			}
		}
	}

	void CollisionService::doCollision(int indexI, int indexJ) {

		// if any of the collision state is disabled
		// we don't have to proceed further with these two colliders
		if (m_colliders[indexI]->getCollisionState() == CollisionState::DISABLED
			|| m_colliders[indexJ]->getCollisionState() == CollisionState::DISABLED) {
			return;
		}

		// if collided and both colliders are valid
		// invoke on collision
		if (hasCollisionOccurred(indexI, indexJ)) {

			// After the invocation of onCollision at indexI, the object might get destroyed,
			// which can lead to invalid references or undefined behavior in subsequent operations.
			// Therefore, handle object validity or destruction properly to avoid potential issues.

			if (areValidColliders(indexI, indexJ)) {
				m_colliders[indexI]->onCollision(m_colliders[indexJ]);
			}

			if (areValidColliders(indexI, indexJ)) {
				m_colliders[indexJ]->onCollision(m_colliders[indexI]);
			}
		}
	}

	bool CollisionService::hasCollisionOccurred(int indexI, int indexJ) {
		sf::Sprite spriteI = m_colliders[indexI]->getColliderSprite();
		sf::Sprite spriteJ = m_colliders[indexJ]->getColliderSprite();
		return spriteI.getGlobalBounds().intersects(spriteJ.getGlobalBounds());
	}

	bool CollisionService::areValidColliders(int indexI, int indexJ) {
		return indexI < m_colliders.size()
			&& indexJ < m_colliders.size()
			&& m_colliders[indexI] != nullptr
			&& m_colliders[indexJ] != nullptr;
	}
}