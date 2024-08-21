#include "./../../public/enemy/EnemyView.h"
#include "../../public/graphic/GraphicService.h"
#include "./../../public/global/ServiceLocator.h"
#include "./../../public/enemy/EnemyController.h"
#include "./../../public/enemy/EnemyConfig.h"
#include "./../../public/global/Config.h"

namespace Enemy
{
    EnemyView::EnemyView()
    {
        m_enemy_controller = nullptr;
    };

    EnemyView::~EnemyView() = default;

    void EnemyView::initialize(EnemyController* enemyController)
    {
        m_enemy_controller = enemyController;
        initializeEnemySprite();
        createEnemySprite();
    }

    void EnemyView::update()
    {
        updateSpritePosition();
    }

    void EnemyView::render()
    {
        Global::ServiceLocator::getInstance()->getGraphicService()->draw(m_spr_enemy);
    }

    void EnemyView::initializeEnemySprite()
    {
        switch (m_enemy_controller->getEnemyType())
        {
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

    void EnemyView::createEnemySprite()
    {
        if (m_tex_enemy.loadFromFile(m_str_texture_path))
        {
            m_spr_enemy.setTexture(m_tex_enemy);
            scaleSprite();
        }
    }

    void EnemyView::scaleSprite()
    {
        float x = c_sprite_width / m_spr_enemy.getTexture()->getSize().x;
        float y = c_sprite_height / m_spr_enemy.getTexture()->getSize().y;
        m_spr_enemy.setScale(x, y);
    }

    void EnemyView::updateSpritePosition()
    {
        m_spr_enemy.setPosition(m_enemy_controller->getPosition());
    }
}
