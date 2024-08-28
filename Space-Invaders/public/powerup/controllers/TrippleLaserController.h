#pragma once
#include "./../PowerupController.h"

namespace Powerup {
	namespace Controller {
		class TrippleLaserController : public PowerupController {
		public:
			TrippleLaserController();
			virtual ~TrippleLaserController();

			void onCollected() override;
		};
	}
}


