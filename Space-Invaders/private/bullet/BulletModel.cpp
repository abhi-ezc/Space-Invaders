#include "./../../public/bullet/BulletModel.h"
#include "./../../public/bullet/BulletConfig.h"
#include "./../../public/projectile/ProjectileConfig.h"
#include "./../../public/entity/EntityConfig.h"

namespace Bullet {
	BulletModel::BulletModel(BulletType type, Entity::EntityType ownerEntityType) {

		m_entity_type = Entity::EntityType::BULLET;
		m_owner_entity_type = ownerEntityType;

		m_bullet_type = type;
		m_bullet_direction = Projectile::ProjectileDirection::UP;
	}

	BulletModel::~BulletModel() = default;

	void BulletModel::initialize(sf::Vector2f position, Projectile::ProjectileDirection direction) {
		m_bullet_position = position;
		m_bullet_direction = direction;
	}

	void BulletModel::update() {}

	void BulletModel::render() {}

	sf::Vector2f BulletModel::getBulletPosition() {
		return m_bullet_position;
	}

	float BulletModel::getBulletSpeed() {
		return m_bullet_speed;
	}

	Projectile::ProjectileDirection BulletModel::getBulletDirection() {
		return m_bullet_direction;
	}

	BulletType BulletModel::getBulletType() {
		return m_bullet_type;
	}

	void BulletModel::setBulletPosition(sf::Vector2f position) {
		m_bullet_position = position;
	}

	void BulletModel::setBulletSpeed(float speed) {
		m_bullet_speed = speed;
	}

	Entity::EntityType BulletModel::getEntityType() {
		return m_entity_type;
	}
	Entity::EntityType BulletModel::getOwnerEntityType() {
		return m_owner_entity_type;
	}
}
