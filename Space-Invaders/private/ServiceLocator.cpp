#include "../public/ServiceLocator.h"

#pragma region Life Cycle Functions

// constructor 
ServiceLocator::ServiceLocator() {
	// create all the required services
	createServices();
}

void ServiceLocator::initialize() {
	// initialize service locator
	graphicService->initialize();
	eventService->initialize();
}

void ServiceLocator::update() {
	// update all the services
	graphicService->update();
	eventService->update();
}

void ServiceLocator::render() {
	// render using the services
	graphicService->render();
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
	graphicService = new GraphicService();
	eventService = new EventService();
}

void ServiceLocator::clearAllServices() {
	// deallocate all the services and cleanup resources used by the services
	delete graphicService;
	delete eventService;
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
	return graphicService;
}
EventService* ServiceLocator::getEventService() {
	return eventService;
}
#pragma endregion
