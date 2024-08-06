#include "./../../public/ui/UIService.h"
#include "./../../public/ui/MainMenuUIController/MainMenuUIController.h"
#include "./../../public/main/GameService.h"

using namespace UI;
using namespace MainMenu;
using namespace Main;

UIService::UIService() { createControllers(); }

UIService::~UIService() { cleanUpControllers(); }

void UIService::initialize() { m_main_menu_ui_controller->initialize(); }

void UIService::update()
{
    if (GameService::getGameState() == GameState::MAIN_MENU) { m_main_menu_ui_controller->update(); }
}

void UIService::render()
{
    if (GameService::getGameState() == GameState::MAIN_MENU) { m_main_menu_ui_controller->render(); }
}

void UIService::createControllers() { m_main_menu_ui_controller = new MainMenuUIController(); }

void UIService::cleanUpControllers() { delete m_main_menu_ui_controller; }

MainMenuUIController* UIService::getMainMenuController() { return m_main_menu_ui_controller; }
