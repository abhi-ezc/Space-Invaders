#include "../../../public/sound/SoundService.h"
#include "./../../../public/ui/MainMenuUIController/MainMenuUIController.h"
#include "./../../../public/global/ServiceLocator.h"
#include "./../../../public/graphic/GraphicService.h"
#include "./../../../public/event/EventService.h"
#include "./../../../public/main/GameService.h"
#include "./../../public/global/Config.h"


namespace UI {
	namespace MainMenu {
		using namespace Global;
		using namespace Graphic;
		using namespace Event;
		using namespace Main;

		MainMenuUIController::MainMenuUIController() {
			m_game_window = nullptr;
			m_play_button = nullptr;
			m_instruction_button = nullptr;
			m_quit_button = nullptr;
			m_background_image = nullptr;
		}

		MainMenuUIController::~MainMenuUIController() {
			delete m_background_image;
			delete m_play_button;
			delete m_instruction_button;
			delete m_quit_button;
		}

		void MainMenuUIController::initialize() {
			m_game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
			initializeBackgroundImage();
			createButtons();
			initializeButtons();
			setAllButtonsPosition();
			registerButtonCallback();
		}

		void MainMenuUIController::initializeBackgroundImage() {
			m_background_image = new UI::UIElement::ImageView();
			sf::Vector2u size = m_game_window->getSize();

			m_background_image->initialize(Config::background_texture_path, size.x, size.y, sf::Vector2f(0, 0));
			m_background_image->setImageAlpha(m_background_alpha);
		}

		void MainMenuUIController::initializeButtons() {
			m_play_button->initialize("Play",
				Config::play_button_texture_path,
				m_button_width,
				m_button_height,
				sf::Vector2f(0, m_play_button_y_position));

			m_instruction_button->initialize("Instruction",
				Config::instructions_button_texture_path,
				m_button_width,
				m_button_height,
				sf::Vector2f(0, m_instruction_button_y_position));

			m_quit_button->initialize("Quit",
				Config::quit_button_texture_path,
				m_button_width,
				m_button_height,
				sf::Vector2f(0, m_quit_button_y_position));
		}

		void MainMenuUIController::createButtons() {
			m_play_button = new UI::UIElement::ButtonView();
			m_instruction_button = new UI::UIElement::ButtonView();
			m_quit_button = new UI::UIElement::ButtonView();
		}


		void MainMenuUIController::setAllButtonsPosition() {
			setButtonPosition(m_play_button);
			setButtonPosition(m_instruction_button);
			setButtonPosition(m_quit_button);
		}

		void MainMenuUIController::setButtonPosition(UI::UIElement::ButtonView* button) {
			button->setOriginAtCentre();
			button->setCentreAligned();
		}

		void MainMenuUIController::update() {
			m_background_image->update();
			m_play_button->update();
			m_instruction_button->update();
			m_quit_button->update();
		}

		void MainMenuUIController::render() {
			m_background_image->render();
			m_play_button->render();
			m_instruction_button->render();
			m_quit_button->render();
		}

		// need to implement
		void MainMenuUIController::show() {
			m_background_image->show();
			m_play_button->show();
			m_instruction_button->show();
			m_quit_button->show();
		}

		void MainMenuUIController::registerButtonCallback() {

			m_play_button->registerCallbackFunction(
				std::bind(&UI::MainMenu::MainMenuUIController::onPlayButtonClick, this));

			m_instruction_button->registerCallbackFunction(
				std::bind(&UI::MainMenu::MainMenuUIController::onInstructionButtonClick, this));

			m_quit_button->registerCallbackFunction(
				std::bind(&UI::MainMenu::MainMenuUIController::onQuitButtonClick, this));

		}

		void MainMenuUIController::onPlayButtonClick() {
			ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::BUTTON_CLICK);
			GameService::setGameState(GameState::GAMEPLAY);
		}

		void MainMenuUIController::onInstructionButtonClick() {
			ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::BUTTON_CLICK);
		}

		void MainMenuUIController::onQuitButtonClick() {
			ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::BUTTON_CLICK);
			ServiceLocator::getInstance()->getGraphicService()->closeGameWindow();
		}
	}
}
