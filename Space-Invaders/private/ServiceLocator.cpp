#include "../public/ServiceLocator.h"

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
}

void ServiceLocator::update()
{
    // update all the services
    graphicService->update();
    eventService->update();
    playerService->update();
    timeService->update();
}

void ServiceLocator::render()
{
    // render using the services
    playerService->render();
    graphicService->render();
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
}

void ServiceLocator::clearAllServices()
{
    // deallocate all the services and cleanup resources used by the services
    delete graphicService;
    delete eventService;
    delete playerService;
    delete timeService;
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

#pragma endregion
