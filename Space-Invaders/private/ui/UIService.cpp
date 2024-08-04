#include "./../../public/ui/UIService.h"
#include "./../../public/ui/MainmenuUIController/MainmenuUIController.h"
#include "./../../public/main/GameService.h"

using namespace UI;
using namespace MainMenu;
using namespace Main;

UIService::UIService() {
	createContollers();
}

UIService::~UIService() {
	cleanUpControllers();
}

void UIService::initialize() {
	mainmenuUIController->initialize();
}

void UIService::update() {
	if( GameService::getGameState() == GameState::MAIN_MENU )
	{
		mainmenuUIController->update();
	}
}

void UIService::render() {
	if( GameService::getGameState() == GameState::MAIN_MENU )
	{
		mainmenuUIController->render();
	}
}

void UI::UIService::createContollers() {
	mainmenuUIController = new MainmenuUIController();
}

void UIService::cleanUpControllers() {
	delete mainmenuUIController;
}

MainmenuUIController* UIService::getMainmenuController() {
	return mainmenuUIController;
}