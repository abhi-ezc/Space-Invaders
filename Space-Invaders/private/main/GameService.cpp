#include "../../public/main/GameService.h"
#include "../../public/global/ServiceLocator.h"
#include "../../public/graphic/GraphicService.h"

namespace Main
{
	using namespace Global;

	GameState GameService::gameState = GameState::BOOT;

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
	void GameService::destroy() { }
	void GameService::setGameState(GameState state) { 
		gameState = state;
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
	GameState GameService::getGameState() {
		return gameState;
	}
#pragma endregion

#pragma region TestCodes

#pragma endregion

}

