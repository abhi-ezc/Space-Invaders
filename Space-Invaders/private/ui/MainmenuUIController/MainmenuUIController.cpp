#include "./../../../public/ui/MainmenuUIController/MainmenuUIController.h"
#include "./../../../public/global/ServiceLocator.h"
#include "./../../../public/graphic/GraphicService.h"

namespace UI
{
	namespace MainMenu
	{
		using namespace Global;
		using namespace Graphic;

		MainmenuUIController::MainmenuUIController() {
			gameWindow = nullptr;
		}

		MainmenuUIController::~MainmenuUIController() {

		}

		void MainmenuUIController::initialize() {
			gameWindow = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		}

		void MainmenuUIController::update() {

		}

		void MainmenuUIController::render() {

		}
	}
}

