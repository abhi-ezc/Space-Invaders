#include "../../../public/bullet/controllers/LaserBulletController.h"
#include "../../../public/bullet/BulletConfig.h"

namespace Bullet
{
    namespace Controllers
    {
        LaserBulletController::LaserBulletController(): BulletController(BulletType::LASER) { }
        LaserBulletController::~LaserBulletController() = default;

        void LaserBulletController::initialize(sf::Vector2f position, Projectile::ProjectileDirection direction)
        {
            BulletController::initialize(position, direction);
        }
    }
}
