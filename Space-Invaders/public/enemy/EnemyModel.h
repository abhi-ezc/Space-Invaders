#pragma once
#include <SFML/System/Vector2.hpp>

namespace Bullet {
	enum class BulletType;
}

namespace Entity {
	enum class EntityType;
}

namespace Enemy {
	enum class EnemyType;
	enum class EnemyState;
	enum class MovementDirection;
	class EnemyController;

	class EnemyModel {
	private:
		Entity::EntityType m_entity_type;

		sf::Vector2f m_current_position;
		sf::Vector2f m_ref_position;

		MovementDirection m_movement_direction;
		MovementDirection m_previous_direction;

		EnemyType m_enemy_type;
		EnemyState m_enemy_state;

		const float m_movement_speed = 200.f;
		const float m_vertical_travel_distance = 30.f;

		const sf::Vector2f m_left_most_position = sf::Vector2f(50.f, 50.f);
		const sf::Vector2f m_right_most_position = sf::Vector2f(1800.f, 50.f);

		const sf::Vector2f m_muzzle_offset = sf::Vector2f(0.f, 40.f);

	protected:
		float m_rate_of_fire = 0.5f;
		float m_elapsed_fire_time = 0.f;
		bool m_can_fire_bullet = false;
		Bullet::BulletType m_bullet_type;


	public:
		EnemyModel(EnemyType enemyType);
		~EnemyModel();

		void initialize(EnemyController* controller);
		void update();
		void render();

		sf::Vector2f getCurrentPosition();
		void setCurrentPosition(sf::Vector2f current_position);

		MovementDirection getMovementDirection();
		void setMovementDirection(MovementDirection movementDirection);
		MovementDirection getPreviousDirection();
		void setPreviousDirection(MovementDirection direction);

		float getVerticalTravelDistance();

		float getMovementSpeed();

		sf::Vector2f getLeftMostPosition();
		sf::Vector2f getRightMostPosition();

		sf::Vector2f getReferencePosition();
		void setReferencePosition(sf::Vector2f refPosition);

		EnemyState getEnemyState();
		void setEnemyState(EnemyState state);

		EnemyType getEnemyType();
		void setEnemyType(EnemyType type);

		void setRateOfFire(float rate);
		float getFireDelay();

		void setElapsedFireTime(float elapsedTime);
		float getElapsedFireTime();

		void setBulletType(EnemyType type);
		Bullet::BulletType getBulletType();

		bool getCanFire();
		sf::Vector2f getMuzzleOffset();

		Entity::EntityType getEntityType();
	};
}
