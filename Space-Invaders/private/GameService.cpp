#include "../public/GameService.h"

#pragma region Life Cycle Functions

// constructors initializing pointers
GameService::GameService() {
	serviceLocator = nullptr;
	gameWindow = nullptr;
}

// destructors calls the destroy function for cleaning up the resources
GameService::~GameService() {
	destroy();
}

void GameService::initialize() {
	serviceLocator->initialize();
	initializeVariables();
}

void GameService::initializeVariables() {
	gameWindow = serviceLocator->getGraphicService()->getGameWindow();
}

void GameService::ignite() {
	serviceLocator = ServiceLocator::getInstance();
	initialize();
}

void GameService::update() {
	serviceLocator->update();
}

void GameService::render() {
	serviceLocator->render();
}

#pragma endregion


#pragma region Operations
void GameService::destroy() {
}
#pragma endregion


#pragma region Getters
bool GameService::isRunning() {
	if( gameWindow != nullptr )
	{
		return gameWindow->isOpen();
	}
	return false;
}
#pragma endregion


#pragma region TestCodes


#pragma endregion
