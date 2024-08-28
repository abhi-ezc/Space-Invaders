#pragma once
#include "./../PowerupController.h"

namespace Powerup {
	namespace Controller {
		class RapidFireController : public PowerupController {
		public:
			RapidFireController();
			virtual ~RapidFireController();

			void onCollected() override;
		};
	}
}

