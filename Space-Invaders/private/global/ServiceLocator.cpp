#include "../../public/global/ServiceLocator.h"
#include "../../public/event/EventService.h"
#include "../../public/graphic/GraphicService.h"
#include "../../public/player/PlayerService.h"
#include "../../public/time/TimeService.h"
#include "../../public/ui/UIService.h";

namespace Global
{
    using namespace Graphic;
    using namespace Event;
    using namespace Player;
    using namespace Time;
    using namespace UI;

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
        graphicService->initialize();
        eventService->initialize();
        playerService->initialize();
        timeService->initialize();
        uiService->initialize();
    }

    void ServiceLocator::update()
    {
        // update all the services
        graphicService->update();
        eventService->update();
        playerService->update();
        timeService->update();
        uiService->update();
    }

    void ServiceLocator::render()
    {
        // render using the services
        playerService->render();
        graphicService->render();
        uiService->render();
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
        graphicService = new GraphicService();
        eventService = new EventService();
        playerService = new PlayerService();
        timeService = new TimeService();
        uiService = new UIService();
    }

    void ServiceLocator::clearAllServices()
    {
        // deallocate all the services and cleanup resources used by the services
        delete graphicService;
        delete eventService;
        delete playerService;
        delete timeService;
        delete uiService;
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
    GraphicService* ServiceLocator::getGraphicService() { return graphicService; }
    
    EventService* ServiceLocator::getEventService() { return eventService; }
    
    PlayerService* ServiceLocator::getPlayerService() { return playerService; }

    TimeService* ServiceLocator::getTimeService() { return timeService; }

    UIService* ServiceLocator::getUIService() {
        return uiService;
    }

    #pragma endregion

}