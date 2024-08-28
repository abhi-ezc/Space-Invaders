#include "./../../public/powerup/PowerupModel.h"
#include "./../../public/powerup/PowerupConfig.h"

namespace Powerup {
	PowerupModel::PowerupModel(PowerupType type) {
		m_powerup_type = type;
	}

	PowerupModel::~PowerupModel() = default;

	void PowerupModel::initialize(sf::Vector2f position) {
		setPosition(position);
	}

	void PowerupModel::update() {}

	void PowerupModel::render() {}

	void PowerupModel::setPosition(sf::Vector2f position) {
		m_position = position;
	}

	sf::Vector2f PowerupModel::getPosition() {
		return m_position;
	}

	PowerupType PowerupModel::getType() {
		return m_powerup_type;
	}
}


