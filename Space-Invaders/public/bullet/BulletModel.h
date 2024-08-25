#pragma once
#include <SFML/System/Vector2.hpp>

namespace Projectile
{
    enum class ProjectileDirection;
}

namespace Bullet
{
    enum class BulletType;

    class BulletModel
    {
        private:
            sf::Vector2f m_bullet_position;
            float m_bullet_speed = 300.f;
            Projectile::ProjectileDirection m_bullet_direction;
            BulletType m_bullet_type;

        public:
            BulletModel(BulletType type);
            ~BulletModel();

            void initialize(sf::Vector2f position, Projectile::ProjectileDirection direction);
            void update();
            void render();

            sf::Vector2f getBulletPosition();
            float getBulletSpeed();
            Projectile::ProjectileDirection getBulletDirection();
            BulletType getBulletType();

            void setBulletPosition(sf::Vector2f position);
            void setBulletSpeed(float speed);
    };
}
