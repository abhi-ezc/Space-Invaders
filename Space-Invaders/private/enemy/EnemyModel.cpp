#include "./../../public/enemy/EnemyModel.h"
#include "../../public/enemy/EnemyController.h"
#include "./../../public/enemy/EnemyConfig.h"
#include "./../../public/bullet/BulletConfig.h"
#include "./../../public/entity/EntityConfig.h"

namespace Enemy {
	EnemyModel::EnemyModel(EnemyType enemyType) {
		m_enemy_type = enemyType;
		m_entity_type = Entity::EntityType::ENEMY;
		setBulletType(enemyType);
	}

	EnemyModel::~EnemyModel() = default;

	void EnemyModel::initialize(EnemyController* controller) {
		m_current_position = controller->getRandomInitialPosition();
		m_enemy_state = EnemyState::PATROLLING;
		m_movement_direction = MovementDirection::RIGHT;
	}

	void EnemyModel::update() {}

	void EnemyModel::render() {}

	sf::Vector2f EnemyModel::getCurrentPosition() {
		return m_current_position;
	}

	void EnemyModel::setCurrentPosition(sf::Vector2f current_position) {
		m_current_position = current_position;
	}

	MovementDirection EnemyModel::getMovementDirection() {
		return m_movement_direction;
	}

	void EnemyModel::setMovementDirection(MovementDirection movementDirection) {
		m_movement_direction = movementDirection;
	}

	MovementDirection EnemyModel::getPreviousDirection() {
		return m_previous_direction;
	}

	void EnemyModel::setPreviousDirection(MovementDirection direction) {
		m_previous_direction = direction;
	}

	float EnemyModel::getVerticalTravelDistance() {
		return m_vertical_travel_distance;
	}

	float EnemyModel::getMovementSpeed() {
		return m_movement_speed;
	}

	sf::Vector2f EnemyModel::getLeftMostPosition() {
		return m_left_most_position;
	}

	sf::Vector2f EnemyModel::getRightMostPosition() {
		return m_right_most_position;
	}

	sf::Vector2f EnemyModel::getReferencePosition() {
		return m_ref_position;
	}

	void EnemyModel::setReferencePosition(sf::Vector2f refPosition) {
		m_ref_position = refPosition;
	}

	EnemyState EnemyModel::getEnemyState() {
		return m_enemy_state;
	}

	void EnemyModel::setEnemyState(EnemyState state) {
		m_enemy_state = state;
	}

	EnemyType EnemyModel::getEnemyType() {
		return m_enemy_type;
	}

	void EnemyModel::setEnemyType(EnemyType type) {
		m_enemy_type = type;
	}

	void EnemyModel::setRateOfFire(float rate) {
		m_rate_of_fire = rate;
	}

	float EnemyModel::getFireDelay() {
		return 1.f / m_rate_of_fire;
	}

	void EnemyModel::setElapsedFireTime(float elapsedTime) {
		m_elapsed_fire_time = elapsedTime;
	}

	float EnemyModel::getElapsedFireTime() {
		return m_elapsed_fire_time;
	}

	void EnemyModel::setBulletType(EnemyType type) {

		m_can_fire_bullet = true; // setting all the enemies can fire bullet initially

		switch (type) {
		case EnemyType::ZAPPER:
			m_bullet_type = Bullet::BulletType::LASER;
			break;

		case EnemyType::SUBZERO:
			m_bullet_type = Bullet::BulletType::FROST;
			break;

		case EnemyType::THUNDER_SNAKE:
			m_bullet_type = Bullet::BulletType::TORPEDO;
			break;

		case EnemyType::UFO:
			m_can_fire_bullet = false; // UFO cannot fire
			break;
		}
	}

	Bullet::BulletType EnemyModel::getBulletType() {
		return m_bullet_type;
	}

	bool EnemyModel::getCanFire() {
		return m_can_fire_bullet;
	}

	sf::Vector2f EnemyModel::getMuzzleOffset() {
		return m_muzzle_offset;
	}

	Entity::EntityType EnemyModel::getEntityType() {
		return m_entity_type;
	}



}
