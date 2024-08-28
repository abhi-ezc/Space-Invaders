#pragma once
#include "./../collectible/ICollectible.h"

namespace Powerup {

	class PowerupModel;
	class PowerupView;
	enum class PowerupType;

	class PowerupController : public Collectible::ICollectible {
	private:
		PowerupModel* m_powerup_model;
		PowerupView* m_powerup_view;

		void handleOutOfBounds();
	public:
		PowerupController(PowerupType type);
		~PowerupController();

		void initialize(sf::Vector2f position) override;
		void update()override;
		void render()override;

		sf::Vector2f getCollectiblePosition();
		PowerupType getPowerupType();
	};
}