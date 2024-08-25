#include "./../../public/bullet/BulletView.h"
#include "../../public/bullet/BulletController.h"
#include "../../public/global/ServiceLocator.h"
#include "../../public/graphic/GraphicService.h"
#include "../../public/bullet/BulletConfig.h"
#include "../../public/global/Config.h"

namespace Bullet
{
    BulletView::BulletView(BulletController* controller)
    {
        m_bullet_controller = controller;
    }

    BulletView::~BulletView() = default;

    void BulletView::initialize()
    {
        loadTexture();
        initializeSprite();
    }

    void BulletView::update()
    {
        m_bullet_sprite.setPosition(m_bullet_controller->getProjectilePosition());
    }

    void BulletView::render()
    {
        Global::ServiceLocator::getInstance()->getGraphicService()->draw(m_bullet_sprite);
    }

    void BulletView::loadTexture()
    {
        switch (m_bullet_controller->getBulletType())
        {
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

    void BulletView::scaleSprite()
    {
        const auto size = static_cast<sf::Vector2f>(m_bullet_sprite.getTexture()->getSize());

        const float scaleX = m_sprite_width / size.x;
        const float scaleY = m_sprite_height / size.y;

        m_bullet_sprite.setScale(scaleX, scaleY);
    }

    void BulletView::initializeSprite()
    {
        if (m_bullet_texture.loadFromFile(m_bullet_texture_path))
        {
            m_bullet_sprite.setTexture(m_bullet_texture);
            scaleSprite();
        }
    }
}
