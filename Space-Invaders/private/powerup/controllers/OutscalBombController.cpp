#include "./../../../public/powerup/controllers/OutscalBombController.h"
#include "./../../../public/powerup/PowerupConfig.h"

namespace Powerup {
	namespace Controller {
		OutscalBombController::OutscalBombController() :PowerupController(PowerupType::OUTSCAL_BOMB) {}
		OutscalBombController::~OutscalBombController() = default;
		void OutscalBombController::onCollected() {

		}
	}
}