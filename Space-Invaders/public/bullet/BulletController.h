#pragma once
#include "./../projectile/IProjectile.h"

namespace Projectile
{
    enum class ProjectileDirection;
}

namespace Bullet
{
    class BulletModel;
    class BulletView;

    enum class BulletType;

    class BulletController : public Projectile::IProjectile

    {
        private:
            BulletModel* m_bullet_model;
            BulletView* m_bullet_view;

            void moveUp();
            void moveDown();

        public:
            BulletController(BulletType type);
            ~BulletController() override;

            void initialize(sf::Vector2f position, Projectile::ProjectileDirection direction) override;
            void update() override;
            void render() override;

            sf::Vector2f getProjectilePosition() override;
            BulletType getBulletType();

            void updateProjectilePosition() override;
            void handleOutOfBounds();
    };
}
