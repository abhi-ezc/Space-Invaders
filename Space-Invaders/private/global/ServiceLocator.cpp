#include "../../public/global/ServiceLocator.h"
#include "../../public/event/EventService.h"
#include "../../public/graphic/GraphicService.h"
#include "../../public/player/PlayerService.h"
#include "../../public/time/TimeService.h"
#include "../../public/ui/UIService.h"
#include "../../public/enemy/EnemyService.h"
#include "../../public/gameplay/GameplayService.h"

namespace Global
{
    using namespace Graphic;
    using namespace Event;
    using namespace Player;
    using namespace Time;
    using namespace UI;
    using namespace Enemy;
    using namespace Gameplay;

    #pragma region Life Cycle Functions

    // constructor 
    ServiceLocator::ServiceLocator()
    {
        // create all the required services
        createServices();
    }

    void ServiceLocator::initialize()
    {
        // initialize service locator
        m_graphic_service->initialize();
        m_event_service->initialize();
        m_player_service->initialize();
        m_time_service->initialize();
        m_ui_service->initialize();
        m_enemy_service->initialize();
        m_gameplay_service->initialize();
    }

    void ServiceLocator::update()
    {
        // update all the services
        m_graphic_service->update();
        m_event_service->update();
        m_player_service->update();
        m_time_service->update();
        m_ui_service->update();
        m_enemy_service->update();
        m_gameplay_service->update();
    }

    void ServiceLocator::render()
    {
        // render using the services
        m_gameplay_service->render();
        m_player_service->render();
        m_enemy_service->render();
        m_ui_service->render();
        m_graphic_service->render();
    }

    // destructor
    ServiceLocator::~ServiceLocator()
    {
        // clear all the service pointers
        clearAllServices();
    }

    #pragma endregion

    #pragma region Operations
    void ServiceLocator::createServices()
    {
        // creating services required for the game
        m_graphic_service = new GraphicService();
        m_event_service = new EventService();
        m_player_service = new PlayerService();
        m_time_service = new TimeService();
        m_ui_service = new UIService();
        m_enemy_service = new EnemyService();
        m_gameplay_service = new GameplayService();
    }

    void ServiceLocator::clearAllServices()
    {
        // deallocate all the services and cleanup resources used by the services
        delete m_graphic_service;
        delete m_event_service;
        delete m_player_service;
        delete m_time_service;
        delete m_ui_service;
        delete m_enemy_service;
        delete m_gameplay_service;
    }
    #pragma endregion

    #pragma region Getters

    // returning the new instance of ServiceLocator 
    ServiceLocator* ServiceLocator::getInstance()
    {
        static ServiceLocator instance;
        return &instance;
    }

    // return GraphicService ptr
    GraphicService* ServiceLocator::getGraphicService()
    {
        return m_graphic_service;
    }

    EventService* ServiceLocator::getEventService()
    {
        return m_event_service;
    }

    PlayerService* ServiceLocator::getPlayerService()
    {
        return m_player_service;
    }

    TimeService* ServiceLocator::getTimeService()
    {
        return m_time_service;
    }

    UIService* ServiceLocator::getUIService()
    {
        return m_ui_service;
    }

    Enemy::EnemyService* ServiceLocator::getEnemyService()
    {
        return m_enemy_service;
    }

    Gameplay::GameplayService* ServiceLocator::getGameplayService()
    {
        return m_gameplay_service;
    }


    #pragma endregion
}
