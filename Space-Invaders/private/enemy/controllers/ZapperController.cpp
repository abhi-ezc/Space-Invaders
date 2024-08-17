#include "../../../public/enemy/controllers/ZapperController.h"

namespace Enemy
{
    namespace Controllers
    {
        ZapperController::ZapperController() { }

        ZapperController::~ZapperController() { }

        void ZapperController::initialize()
        {
            EnemyController::initialize();
        }

        void ZapperController::move() { }

        void ZapperController::moveLeft() { }

        void ZapperController::moveRight() { }

        void ZapperController::moveDown() { }
    }
}
