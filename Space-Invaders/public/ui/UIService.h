#pragma once
namespace UI
{
	namespace MainMenu
	{
		class MainmenuUIController;
	}

	class UIService {
		private:
		MainMenu::MainmenuUIController* mainmenuUIController;

		void createContollers();
		void cleanUpControllers();

		public:
		UIService();
		~UIService();
		
		void initialize();
		void update();
		void render();

		MainMenu::MainmenuUIController* getMainmenuController();
		
	};
}
