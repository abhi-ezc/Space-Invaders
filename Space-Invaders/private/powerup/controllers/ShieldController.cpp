#include "./../../../public/powerup/controllers/ShieldController.h"
#include "./../../../public/powerup/PowerupConfig.h"

namespace Powerup {
	namespace Controller {
		ShieldController::ShieldController() :PowerupController(PowerupType::SHIELD) {}
		ShieldController::~ShieldController() = default;
		void ShieldController::onCollected() {

		}
	}
}