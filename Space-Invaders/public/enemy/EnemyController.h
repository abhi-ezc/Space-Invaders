#pragma once
#include <SFML/System/Vector2.hpp>

namespace Entity {
	enum class EntityType;
}

namespace Enemy {
	class EnemyView;
	class EnemyModel;
	enum class EnemyState;
	enum class EnemyType;

	class EnemyController {
	private:
		void handleOutOfBounds();

	protected:
		EnemyView* m_enemy_view;
		EnemyModel* m_enemy_model;

		void updateFireTimer();
		void processBulletFire();

		virtual void fireBullet();

	public:
		EnemyController(EnemyType type);
		virtual ~EnemyController();

		virtual void initialize();
		void update();
		void render();

		virtual void move() = 0;

		sf::Vector2f getPosition();
		EnemyType getEnemyType();
		EnemyState getEnemyState();
		sf::Vector2f getRandomInitialPosition();

		Entity::EntityType getEntityType();
	};
}
