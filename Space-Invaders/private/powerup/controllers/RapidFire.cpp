#include "./../../../public/powerup/controllers/RapidFireController.h"
#include "./../../../public/powerup/PowerupConfig.h"

namespace Powerup {
	namespace Controller {
		RapidFireController::RapidFireController() :PowerupController(PowerupType::SHIELD) {}
		RapidFireController::~RapidFireController() = default;
		void RapidFireController::onCollected() {

		}
	}
}