#pragma once
#include "./../public/PlayerService.h"
#include "./../public/ServiceLocator.h"

#pragma region Life Cycle Functions

PlayerService::PlayerService() {
	gameWindow = nullptr;
	health = 100;
	playerScore = 0;
	movementSpeed = 5;
	position = sf::Vector2f(200.f, 100.f);
}

PlayerService::~PlayerService() = default;

void PlayerService::initialize() {
	initializePlayerSprite();
	gameWindow = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
}


void PlayerService::update() {
	processPlayerInput();
	updatePlayerPosition();
}

void PlayerService::render() {
	ServiceLocator::getInstance()->getGraphicService()->getGameWindow()->draw(sprite);
}

#pragma endregion

#pragma region Operations

void PlayerService::initializePlayerSprite() {
	texture.loadFromFile(texturePath);
	sprite.setTexture(texture);
}

void PlayerService::updatePlayerPosition() {
	sprite.setPosition(position);
}

void PlayerService::processPlayerInput() {
	EventService* eventService = ServiceLocator::getInstance()->getEventService();
		if( eventService->isLeftKeyPressed() )
		{
			move(movementSpeed * -1.f);
		}
		else if( eventService->isRightKeyPressed() )
		{
			move(movementSpeed);
		}
		else
		{
			// do nothing
		}
}

void PlayerService::move(float offset) {
	position.x += offset;

}

void PlayerService::shootBullets() {

}

void PlayerService::takeDamage() {

}

#pragma endregion

#pragma region Getter Functions

#pragma endregion



