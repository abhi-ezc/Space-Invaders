#include "./../../public/bullet/BulletView.h"
#include "../../public/bullet/BulletController.h"
#include "../../public/global/ServiceLocator.h"
#include "../../public/graphic/GraphicService.h"
#include "../../public/bullet/BulletConfig.h"
#include "../../public/global/Config.h"
#include "../../public/ui/UIElement/ImageView.h"

namespace Bullet {
	BulletView::BulletView(BulletController* controller) {
		m_bullet_controller = controller;
		m_bullet_image = nullptr;
	}

	BulletView::~BulletView() {
		delete m_bullet_image;
	}

	void BulletView::initialize() {
		loadTexture();
		initializeSprite();
	}

	void BulletView::update() {
		m_bullet_image->update();
		m_bullet_image->setPosition(m_bullet_controller->getProjectilePosition());
	}

	void BulletView::render() {
		m_bullet_image->render();
	}

	sf::Sprite& BulletView::getBulletSprite() {
		return m_bullet_image->getSprite();
	}

	void BulletView::loadTexture() {
		switch (m_bullet_controller->getBulletType()) {
		case BulletType::LASER:
			m_bullet_texture_path = Global::Config::laser_bullet_texture_path;
			break;
		case BulletType::FROST:
			m_bullet_texture_path = Global::Config::frost_beam_texture_path;
			break;
		case BulletType::TORPEDO:
			m_bullet_texture_path = Global::Config::torpedoe_texture_path;
			break;
		}
	}

	void BulletView::initializeSprite() {
		m_bullet_image = new UI::UIElement::ImageView();
		m_bullet_image->initialize(m_bullet_texture_path, m_sprite_width, m_sprite_height, m_bullet_controller->getProjectilePosition());
		m_bullet_image->setOriginAtCentre();
	}
}
