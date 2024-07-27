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
}

void ServiceLocator::update() {
	// update all the services
	graphicService->update();
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
}

void ServiceLocator::clearAllServices() {
	// deallocate all the services and cleanup resources used by the services
	delete graphicService;
}
#pragma endregion

#pragma region Getters

// returning the new instance of ServiceLocator 
ServiceLocator* ServiceLocator::getInstance() {
	return new ServiceLocator();
}

// for deleting an instance of the ServiceLocator
void ServiceLocator::deleteInstance(ServiceLocator* serviceLocator) {
	delete serviceLocator;
}

// return GraphicService ptr
GraphicService* ServiceLocator::getGraphicService() {
	return graphicService;
}
#pragma endregion
