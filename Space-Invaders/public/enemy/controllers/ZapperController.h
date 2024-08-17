#pragma once
#include "../EnemyController.h"

namespace Enemy
{
    namespace Controllers
    {
        class ZapperController : public EnemyController
        {
            private:
                float vertical_travel_distance = 100.f;
                void move() override;
                void moveLeft() override;
                void moveRight() override;
                void moveDown() override;
            public:
                ZapperController();
                ~ZapperController() override;

                void initialize() override;
        };
    }
}
