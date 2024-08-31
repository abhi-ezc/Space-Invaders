#pragma once
namespace UI
{
    namespace MainMenu
    {
        class MainMenuUIController;
    }

    namespace Interface
    {
        class IUIController;
    }

    class UIService
    {
        private:
            MainMenu::MainMenuUIController* m_main_menu_ui_controller;

            void createControllers();
            void cleanUpControllers();

        public:
            UIService();
            ~UIService();

            void initialize();
            void update();
            void render();

            Interface::IUIController* getCurrentUIController();

            MainMenu::MainMenuUIController* getMainMenuController();
    };
}
