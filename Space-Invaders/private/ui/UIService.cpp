#include "./../../public/ui/UIService.h"
#include "./../../public/ui/MainmenuUIController/MainmenuUIController.h"

using namespace UI;
using namespace MainMenu;

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
	mainmenuUIController->update();
}

void UIService::render() {
	mainmenuUIController->render();
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