#include "./../../public/player/PlayerController.h" 
#include "./../../public/global/ServiceLocator.h"
#include "./../../public/time/TimeService.h"
#include "./../../public/player/PlayerView.h"
#include "./../../public/player/PlayerModel.h"
#include "./../../public/event/EventService.h"

namespace Player
{
	using namespace Global;
	using namespace Event;

#pragma region Life Cycle methods
	PlayerController::PlayerController() {
		playerModel = new PlayerModel();
		playerView = new PlayerView();
	}

	PlayerController::~PlayerController() {
		delete playerModel;
		delete playerView;
	}

	void PlayerController::initialize() {
		playerModel->initialize();
		playerView->initialize(this);
	}

	void PlayerController::update() {
		processPlayerInputs();
		playerModel->update();
		playerView->update();
	}

	void PlayerController::render() {
		playerModel->render();
		playerView->render();
	}

#pragma endregion

#pragma region Operations
	void PlayerController::processPlayerInputs() {

		EventService* eventService = ServiceLocator::getInstance()->getEventService();

		if( eventService->isLeftKeyPressed() || eventService->isAKeyPressed() )
		{
			moveLeft();
		}
		else if( eventService->isRightKeyPressed() || eventService->isDKeyPressed() )
		{
			moveRight();
		}
		else
		{

		}
	}

	void PlayerController::moveLeft() {
		sf::Vector2f currentPosition = playerModel->getPlayerPosition();
		currentPosition.x -= playerModel->movementSpeed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
		currentPosition.x = std::max(currentPosition.x, playerModel->leftMostPosition);
		playerModel->setPlayerPosition(currentPosition);
	}

	void PlayerController::moveRight() {
		sf::Vector2f currentPosition = playerModel->getPlayerPosition();
		currentPosition.x += playerModel->movementSpeed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		currentPosition.x = std::min(currentPosition.x, playerModel->rightMostPosition);
		playerModel->setPlayerPosition(currentPosition);
	}
#pragma endregion

#pragma region Getters
	sf::Vector2f PlayerController::getPlayerPosition() {
		return playerModel->getPlayerPosition();
	}
#pragma endregion

}
