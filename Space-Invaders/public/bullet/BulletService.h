#pragma once

namespace Bullet
{
    class BulletService
    {
        private:
            BulletService();
            ~BulletService();

            void initialize();
            void update();
            void render();
    };
}
