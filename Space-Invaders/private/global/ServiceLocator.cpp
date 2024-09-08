#include "../../public/global/ServiceLocator.h"
#include "../../public/bullet/BulletService.h"
#include "../../public/event/EventService.h"
#include "../../public/graphic/GraphicService.h"
#include "../../public/player/PlayerService.h"
#include "../../public/time/TimeService.h"
#include "../../public/ui/UIService.h"
#include "../../public/enemy/EnemyService.h"
#include "../../public/gameplay/GameplayService.h"
#include "../../public/element/ElementService.h"
#include "../../public/sound/SoundService.h"
#include "../../public/bullet/BulletService.h"
#include "../../public/powerup/PowerupService.h"
#include "../../public/collision/CollisionService.h"

namespace Global {
	using namespace Graphic;
	using namespace Event;
	using namespace Player;
	using namespace Time;
	using namespace UI;
	using namespace Enemy;
	using namespace Gameplay;
	using namespace Element;
	using namespace Sound;
	using namespace Bullet;
	using namespace Powerup;
	using namespace Collision;

#pragma region Life Cycle Functions

	// constructor 
	ServiceLocator::ServiceLocator() {
		// create all the required services
		createServices();
	}

	void ServiceLocator::initialize() {
		// initialize service locator
		m_sound_service->initialize();
		m_graphic_service->initialize();
		m_event_service->initialize();
		m_player_service->initialize();
		m_time_service->initialize();
		m_ui_service->initialize();
		m_enemy_service->initialize();
		m_gameplay_service->initialize();
		m_element_service->initialize();
		m_bullet_service->initialize();
		m_powerup_service->initialize();
		m_collision_service->initialize();
	}

	void ServiceLocator::update() {
		// update all the services
		m_graphic_service->update();
		m_event_service->update();
		m_time_service->update();
		m_ui_service->update();
		m_enemy_service->update();
		m_bullet_service->update();
		m_element_service->update();
		m_gameplay_service->update();
		m_powerup_service->update();
		m_collision_service->update();
		m_player_service->update();
	}

	void ServiceLocator::render() {
		// render using the services
		m_gameplay_service->render();
		m_element_service->render();
		m_enemy_service->render();
		m_bullet_service->render();
		m_powerup_service->render();
		m_player_service->render();
		m_collision_service->render();
		m_ui_service->render();
		m_graphic_service->render();

	}

	// destructor
	ServiceLocator::~ServiceLocator() {
		// clear all the service pointers
		clearAllServices();
	}

#pragma endregion

#pragma region Operations
	void ServiceLocator::createServices() {
		// creating services required for the game
		m_sound_service = new SoundService();
		m_collision_service = new CollisionService();
		m_graphic_service = new GraphicService();
		m_event_service = new EventService();
		m_time_service = new TimeService();
		m_ui_service = new UIService();
		m_enemy_service = new EnemyService();
		m_gameplay_service = new GameplayService();
		m_element_service = new ElementService();
		m_bullet_service = new BulletService();
		m_powerup_service = new PowerupService();
		m_player_service = new PlayerService();
	}

	void ServiceLocator::clearAllServices() {
		// deallocate all the services and cleanup resources used by the services
		delete m_graphic_service;
		delete m_event_service;
		delete m_player_service;
		delete m_time_service;
		delete m_ui_service;
		delete m_enemy_service;
		delete m_gameplay_service;
		delete m_element_service;
		delete m_sound_service;
		delete m_bullet_service;
		delete m_powerup_service;
		delete m_collision_service;
	}
#pragma endregion

#pragma region Getters

	// returning the new instance of ServiceLocator 
	ServiceLocator* ServiceLocator::getInstance() {
		static ServiceLocator instance;
		return &instance;
	}

	// return GraphicService ptr
	GraphicService* ServiceLocator::getGraphicService() {
		return m_graphic_service;
	}

	EventService* ServiceLocator::getEventService() {
		return m_event_service;
	}

	PlayerService* ServiceLocator::getPlayerService() {
		return m_player_service;
	}

	TimeService* ServiceLocator::getTimeService() {
		return m_time_service;
	}

	UIService* ServiceLocator::getUIService() {
		return m_ui_service;
	}

	EnemyService* ServiceLocator::getEnemyService() {
		return m_enemy_service;
	}

	GameplayService* ServiceLocator::getGameplayService() {
		return m_gameplay_service;
	}

	ElementService* ServiceLocator::getElementService() {
		return m_element_service;
	}

	SoundService* ServiceLocator::getSoundService() {
		return m_sound_service;
	}

	BulletService* ServiceLocator::getBulletService() {
		return m_bullet_service;
	}

	PowerupService* ServiceLocator::getPowerupService() {
		return m_powerup_service;
	}

	CollisionService* ServiceLocator::getCollisionService() {
		return m_collision_service;
	}
#pragma endregion
}
