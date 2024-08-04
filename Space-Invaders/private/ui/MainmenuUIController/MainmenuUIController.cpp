#include "./../../../public/ui/MainmenuUIController/MainmenuUIController.h"
#include "./../../../public/global/ServiceLocator.h"
#include "./../../../public/graphic/GraphicService.h"
#include "./../../../public/event/EventService.h"
#include "./../../../public/main/GameService.h"


namespace UI
{
	namespace MainMenu
	{
		using namespace Global;
		using namespace Graphic;
		using namespace Event;
		using namespace Main;

		MainmenuUIController::MainmenuUIController() {
			gameWindow = nullptr;
		}

		MainmenuUIController::~MainmenuUIController() {

		}

		void MainmenuUIController::initialize() {
			gameWindow = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
			initializeBackgroundImage();
			initializeButtons();
		}

		void MainmenuUIController::initializeBackgroundImage() {
			tex_backgroundImage.loadFromFile(str_backgroundImagePath);
			spr_backgroundImage.setTexture(tex_backgroundImage);

			float sizeX = static_cast<float>( gameWindow->getView().getSize().x / spr_backgroundImage.getTexture()->getSize().x );

			float sizeY = static_cast<float>( gameWindow->getView().getSize().y / spr_backgroundImage.getTexture()->getSize().y );

			spr_backgroundImage.setScale(sizeX, sizeY);
		}

		void MainmenuUIController::initializeButtons() {
			if( loadButtonTextures() )
			{
				createButtonSprites();
				scaleAllButtons();
				setAllButtonsPosition();
			}
		}

		bool MainmenuUIController::loadButtonTextures() {
			return tex_playButton.loadFromFile(str_playButtonPath) && tex_instructionButton.loadFromFile(str_instructionButtonPath) && tex_quitButton.loadFromFile(str_quitButtonPath);
		}

		void MainmenuUIController::createButtonSprites() {
			spr_playButton.setTexture(tex_playButton);
			spr_instructionButton.setTexture(tex_instructionButton);
			spr_quitButton.setTexture(tex_quitButton);
		}

		void MainmenuUIController::scaleAllButtons() {
			scaleButton(&spr_playButton);
			scaleButton(&spr_instructionButton);
			scaleButton(&spr_quitButton);
		}

		void MainmenuUIController::scaleButton(sf::Sprite* spr_button) {
			float x = f_buttonWidth / spr_button->getTexture()->getSize().x;
			float y = f_buttonHeight / spr_button->getTexture()->getSize().y;
			spr_button->setScale(x, y);
		}

		void MainmenuUIController::setAllButtonsPosition() {
			setButtonPosition(&spr_playButton, 250.f);
			setButtonPosition(&spr_instructionButton, 500);
			setButtonPosition(&spr_quitButton, 750.f);
		}

		void MainmenuUIController::setButtonPosition(sf::Sprite* spr_button, float yOffset) {

			// calculate button sizes from the original size and the sprite scale
			float buttonSizeX = spr_button->getTexture()->getSize().x * spr_button->getScale().x;
			float buttonSizeY = spr_button->getTexture()->getSize().y * spr_button->getScale().y;

			// calculate positions based on the screen center and given yOffset
			float x = gameWindow->getView().getCenter().x - ( buttonSizeX / 2 );
			float y = yOffset - ( buttonSizeY / 2 );

			// apply calculated positions
			spr_button->setPosition(x, yOffset);
		}

		void MainmenuUIController::update() {
			onButtonClick();
		}

		void MainmenuUIController::render() {
			ServiceLocator::getInstance()->getGraphicService()->draw(spr_backgroundImage);
			ServiceLocator::getInstance()->getGraphicService()->draw(spr_playButton);
			ServiceLocator::getInstance()->getGraphicService()->draw(spr_instructionButton);
			ServiceLocator::getInstance()->getGraphicService()->draw(spr_quitButton);
		}

		void MainmenuUIController::processButtonInteractions() {
			if( ServiceLocator::getInstance()->getEventService()->isLeftMouseButtonPressed() )
			{
				if( isButtonClick(&spr_playButton, sf::Mouse::getPosition()) )
				{
					onPlayButtonClick();
				}
				else if( isButtonClick(&spr_instructionButton, sf::Mouse::getPosition()) )
				{
					onInstructionButtonClick();
				}
				else if( isButtonClick(&spr_quitButton, sf::Mouse::getPosition()) )
				{
					onQuitButtonClick();
				}
				else
				{
				}
			}
		}
		bool MainmenuUIController::isButtonClick(sf::Sprite* spr_button, sf::Vector2i mousePosition) {
			return spr_button->getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);
		}
		void MainmenuUIController::onPlayButtonClick() {
			GameService::setGameState(GameState::GAMEPLAY);
		}

		void MainmenuUIController::onInstructionButtonClick() { }

		void MainmenuUIController::onQuitButtonClick() {
			ServiceLocator::getInstance()->getGraphicService()->closeGameWindow();
		}
	}
}

