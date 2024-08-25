#include "./../../public/bullet/BulletModel.h"
#include "./../../public/bullet/BulletConfig.h"

namespace Bullet
{
    BulletModel::BulletModel(BulletType type)
    {
        m_bullet_type = type;
        m_bullet_direction = Projectile::ProjectileDirection::UP;
    }

    BulletModel::~BulletModel() = default;

    void BulletModel::initialize(sf::Vector2f position, Projectile::ProjectileDirection direction)
    {
        m_bullet_position = position;
        m_bullet_direction = direction;
    }

    void BulletModel::update() { }

    void BulletModel::render() { }

    sf::Vector2f BulletModel::getBulletPosition()
    {
        return m_bullet_position;
    }

    float BulletModel::getBulletSpeed()
    {
        return m_bullet_speed;
    }

    void BulletModel::setBulletPosition(sf::Vector2f position)
    {
        m_bullet_position = position;
    }

    Projectile::ProjectileDirection BulletModel::getBulletDirection()
    {
        return m_bullet_direction;
    }

    BulletType BulletModel::getBulletType()
    {
        return m_bullet_type;
    }
}
