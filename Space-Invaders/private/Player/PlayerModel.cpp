#include "./../../public/player/PlayerModel.h"

PlayerModel::PlayerModel() {

}

PlayerModel::~PlayerModel() = default;

void PlayerModel::initialize() {
	reset(); // setting up initial variables
}

void PlayerModel::update() {
	
}

void PlayerModel::render() { }

void PlayerModel::reset() {
	currentPlayerPosition = initialPlayerPosition;
	playerState = PlayerState::ALIVE;
	playerScore = 0;
}

sf::Vector2f PlayerModel::getPlayerPosition() {
	return currentPlayerPosition;
}

bool PlayerModel::isPlayerAlive() {
	return playerState == PlayerState::ALIVE;
}

PlayerState PlayerModel::getPlayerState() {
	return playerState;
}

int PlayerModel::getPlayerScore() {
	return playerScore;
}

void PlayerModel::setPlayerState(PlayerState newPlayerState) {
	playerState = newPlayerState;
}

void PlayerModel::setPlayerScore(int score) {
	playerScore = score;
}

void PlayerModel::setPlayerPosition(sf::Vector2f position) { 
	currentPlayerPosition = position;
}
