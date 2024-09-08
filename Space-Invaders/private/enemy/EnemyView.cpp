#include "./../../public/enemy/EnemyView.h"
#include "../../public/graphic/GraphicService.h"
#include "./../../public/global/ServiceLocator.h"
#include "./../../public/enemy/EnemyController.h"
#include "./../../public/enemy/EnemyConfig.h"
#include "./../../public/global/Config.h"
#include "./../../public/ui/UIElement/ImageView.h"

namespace Enemy {
	EnemyView::EnemyView() {
		m_enemy_controller = nullptr;
		m_enemy_image = nullptr;
	};

	EnemyView::~EnemyView() {
		delete m_enemy_image;
	}

	void EnemyView::initialize(EnemyController* enemyController) {
		m_enemy_controller = enemyController;
		initializeEnemySprite();
		createEnemySprite();
	}

	void EnemyView::update() {
		updateSpritePosition();
	}

	void EnemyView::render() {
		m_enemy_image->render();
	}

	sf::Vector2f EnemyView::getSpriteSize() {
		return sf::Vector2f(c_sprite_width, c_sprite_height);
	}

	sf::Sprite& EnemyView::getSprite() {
		return m_enemy_image->getSprite();
	}

	void EnemyView::initializeEnemySprite() {
		switch (m_enemy_controller->getEnemyType()) {
		case EnemyType::ZAPPER:
			m_str_texture_path = Global::Config::zapper_texture_path;
			break;
		case EnemyType::SUBZERO:
			m_str_texture_path = Global::Config::subzero_texture_path;
			break;
		case EnemyType::THUNDER_SNAKE:
			m_str_texture_path = Global::Config::thunder_snake_texture_path;
			break;
		case EnemyType::UFO:
			m_str_texture_path = Global::Config::ufo_texture_path;
			break;
		}
	}

	void EnemyView::createEnemySprite() {
		m_enemy_image = new UI::UIElement::ImageView();
		m_enemy_image->initialize(m_str_texture_path, c_sprite_width, c_sprite_height, m_enemy_controller->getPosition());
	}

	void EnemyView::updateSpritePosition() {
		m_enemy_image->update();
		m_enemy_image->setPosition(m_enemy_controller->getPosition());
	}
}
