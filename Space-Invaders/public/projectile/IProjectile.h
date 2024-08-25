#pragma once

#include <SFML/System/Vector2.hpp>
#include "./ProjectileConfig.h"

namespace Projectile
{
    class IProjectile
    {
        public:
            virtual void initialize(sf::Vector2f position, ProjectileDirection direction) = 0;
            virtual void update() = 0;
            virtual void render() = 0;

            virtual void updateProjectilePosition() = 0;
            virtual sf::Vector2f getProjectilePosition() = 0;

            virtual ~IProjectile() = default;
    };
}
