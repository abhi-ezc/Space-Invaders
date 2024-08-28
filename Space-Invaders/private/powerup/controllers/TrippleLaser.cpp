#include "./../../../public/powerup/controllers/TrippleLaserController.h"
#include "./../../../public/powerup/PowerupConfig.h"

namespace Powerup {
	namespace Controller {
		TrippleLaserController::TrippleLaserController() :PowerupController(PowerupType::SHIELD) {}
		TrippleLaserController::~TrippleLaserController() = default;
		void TrippleLaserController::onCollected() {

		}
	}
}