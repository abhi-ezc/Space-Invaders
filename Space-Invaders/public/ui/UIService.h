#pragma once
namespace UI
{
    namespace MainMenu
    {
        class MainMenuUIController;
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

            MainMenu::MainMenuUIController* getMainMenuController();
    };
}
