#include "../../../public/enemy/controllers/SubZeroController.h"

namespace Enemy
{
    namespace Controllers
    {
        SubZeroController::SubZeroController() {}

        SubZeroController::~SubZeroController() { }

        void SubZeroController::initialize()
        {
            EnemyController::initialize();
        }

        void SubZeroController::move() { }

        void SubZeroController::moveDown() { }
    }
}
