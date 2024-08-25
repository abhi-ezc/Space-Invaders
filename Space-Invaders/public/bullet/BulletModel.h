#pragma once
#include <SFML/System/Vector2.hpp>
#include "./../../public/projectile/ProjectileConfig.h"


namespace Bullet
{
    enum class BulletType;

    class BulletModel
    {
        private:
            sf::Vector2f m_bullet_position;
            float m_bullet_speed = 100.f;
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

            void setBulletPosition(sf::Vector2f position);

            Projectile::ProjectileDirection getBulletDirection();

            BulletType getBulletType();
    };
}
