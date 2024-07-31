#include "./../../public/player/PlayerController.h" 
#include "./../../public/global/ServiceLocator.h"
#include "./../../public/time/TimeService.h"
#include "./../../public/player/PlayerView.h"
#include "./../../public/player/PlayerModel.h"

namespace Player
{
	using namespace Global;
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
		if( sf::Keyboard::isKeyPressed(sf::Keyboard::Left) )
		{
			moveLeft();
		}
		else if( sf::Keyboard::isKeyPressed(sf::Keyboard::Right) )
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
