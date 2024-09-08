#pragma once

namespace Graphic {
	class GraphicService;
}

namespace Event {
	class EventService;
}

namespace Player {
	class PlayerService;
}

namespace Time {
	class TimeService;
}

namespace UI {
	class UIService;
}

namespace Enemy {
	class EnemyService;
}

namespace Gameplay {
	class GameplayService;
}

namespace Element {
	class ElementService;
}

namespace Sound {
	class SoundService;
}

namespace Bullet {
	class BulletService;
}

namespace Powerup {
	class PowerupService;
}

namespace Collision {
	class CollisionService;
}

namespace Global {
	// ServiceLocator Class Summary: This class manages access to various services in the application.
	class ServiceLocator {
	private:
		Graphic::GraphicService* m_graphic_service;
		Event::EventService* m_event_service;
		Player::PlayerService* m_player_service;
		Time::TimeService* m_time_service;
		UI::UIService* m_ui_service;
		Enemy::EnemyService* m_enemy_service;
		Gameplay::GameplayService* m_gameplay_service;
		Element::ElementService* m_element_service;
		Sound::SoundService* m_sound_service;
		Bullet::BulletService* m_bullet_service;
		Powerup::PowerupService* m_powerup_service;
		Collision::CollisionService* m_collision_service;

		// Constructor for initializing the ServiceLocator.
		ServiceLocator();

		// Destructor for cleaning up resources upon object deletion.
		~ServiceLocator();

		// Private Methods:
		void createServices(); // Creates instances of all services.
		void clearAllServices(); //	Deletes and deallocates memory for all services.

	public:
		// Public Methods:
		static ServiceLocator* getInstance();
		// Provides a method to access the unique ServiceLocator instance (object). We will discuss this later.

		void initialize(); // Initializes the ServiceLocator.
		void update(); // Updates all services.
		void render(); // Renders using the services.

		// Methods to Get Specific Services: 
		Event::EventService* getEventService(); // Retrieve the EventService instance
		Graphic::GraphicService* getGraphicService(); // Retrieve the GraphicService instance
		Player::PlayerService* getPlayerService(); // Retrieve the PlayerService instance
		Time::TimeService* getTimeService();
		Collision::CollisionService* getCollisionService();
		UI::UIService* getUIService();
		Enemy::EnemyService* getEnemyService();
		Gameplay::GameplayService* getGameplayService();
		Element::ElementService* getElementService();
		Sound::SoundService* getSoundService();
		Bullet::BulletService* getBulletService();
		Powerup::PowerupService* getPowerupService();
	};
}
