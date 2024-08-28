#pragma once
#include "./../PowerupController.h"

namespace Powerup {
	namespace Controller {
		class OutscalBombController : public PowerupController {
		public:
			OutscalBombController();
			virtual ~OutscalBombController();

			void onCollected() override;
		};
	}
}