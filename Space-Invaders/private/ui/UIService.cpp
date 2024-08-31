#include "./../../public/ui/UIService.h"
#include "./../../public/ui/MainMenuUIController/MainMenuUIController.h"
#include "./../../public/main/GameService.h"
#include "./../../public/ui/interface/IUIController.h"

using namespace UI;
using namespace MainMenu;
using namespace Main;

UIService::UIService()
{
    createControllers();
}

UIService::~UIService()
{
    cleanUpControllers();
}

void UIService::initialize()
{
    m_main_menu_ui_controller->initialize();
}

void UIService::update()
{
    Interface::IUIController* controller = getCurrentUIController();
    controller->update();
}

void UIService::render()
{
    Interface::IUIController* controller = getCurrentUIController();
    controller->render();
}

Interface::IUIController* UIService::getCurrentUIController()
{
    switch (Main::GameService::getGameState())
    {
        case GameState::MAIN_MENU:
            return m_main_menu_ui_controller;
        default:
            return nullptr;
    }
}

void UIService::createControllers()
{
    m_main_menu_ui_controller = new MainMenuUIController();
}

void UIService::cleanUpControllers()
{
    delete m_main_menu_ui_controller;
}

MainMenuUIController* UIService::getMainMenuController()
{
    return m_main_menu_ui_controller;
}
