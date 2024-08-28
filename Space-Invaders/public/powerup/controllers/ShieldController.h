#pragma once
#include "./../PowerupController.h"

namespace Powerup {
	namespace Controller {
		class ShieldController : public PowerupController {
		public:
			ShieldController();
			virtual ~ShieldController();

			void onCollected() override;
		};
	}
}