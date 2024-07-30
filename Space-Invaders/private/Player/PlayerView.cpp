#include "./../../public/player/PlayerView.h"
#include "./../../public/global/ServiceLocator.h"
#include "./../../public/player/PlayerController.h"
#include "./../../public/graphic/GraphicService.h"

PlayerView::PlayerView() {
	gameWindow = nullptr;
	playerController = nullptr;
}

PlayerView::~PlayerView() = default;

void PlayerView::initialize(PlayerController* controller) {
	playerController = controller;
	gameWindow = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
	createPlayerSprite();
}

void PlayerView::update() {
	// setting the updated sprite position from playercontroller
	sprite.setPosition(playerController->getPlayerPosition());
}

void PlayerView::render() {
	ServiceLocator::getInstance()->getGraphicService()->draw(sprite);
}

void PlayerView::setPlayerScale() { 
	float x = static_cast<float>( spriteWidth / sprite.getTexture()->getSize().x );
	float y = static_cast<float>( spriteHeight / sprite.getTexture()->getSize().y );

	//sprite.setScale(x, y);
}

void PlayerView::createPlayerSprite() {
	if( texture.loadFromFile(texturePath) )
	{
		sprite.setTexture(texture);
		setPlayerScale();
	}
}

sf::Sprite PlayerView::getPlayerSprite() {
	return sprite;
}