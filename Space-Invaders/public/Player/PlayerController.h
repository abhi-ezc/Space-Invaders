#pragma once
#include "SFML/System/Vector2.hpp"

namespace Entity {
	enum class EntityType;
}

namespace Player {
	class PlayerModel;
	class PlayerView;

	class PlayerController {
	private:
		PlayerModel* m_player_model;
		PlayerView* m_player_view;

		Entity::EntityType m_entity_type;

		void processPlayerInputs();
		void moveLeft();
		void moveRight();
		void fireBullet();

	public:
		// constructors and destructors
		PlayerController();
		~PlayerController();

		// life cycle methods
		void initialize();
		void update();
		void render();

		// getters
		sf::Vector2f getPlayerPosition();

		Entity::EntityType getEntityType();

	};
}
