#pragma once
#include "../BulletController.h"

namespace Projectile
{
    enum class ProjectileDirection;
}

namespace Bullet
{
    enum class BulletType;

    namespace Controllers
    {
        class LaserBulletController : public BulletController
        {
            public:
                LaserBulletController();
                ~LaserBulletController() override;

                void initialize(sf::Vector2f position, Projectile::ProjectileDirection direction) override;
        };
    }
}
