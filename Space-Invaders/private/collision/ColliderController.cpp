#include "./../../public/collision/ColliderController.h"

using namespace Collision;

ColliderController::ColliderController() {
	m_collision_state = CollisionState::ENABLED;
}

ColliderController::~ColliderController() = default;

void ColliderController::enableCollision() {
	m_collision_state = CollisionState::ENABLED;
}

void Collision::ColliderController::disableCollision() {
	m_collision_state = CollisionState::DISABLED;
}

CollisionState ColliderController::getCollisionState() {
	return m_collision_state;
}