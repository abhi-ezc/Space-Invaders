#include "./../../public/enemy/EnemyService.h"
#include "./../../public/enemy/EnemyController.h"

namespace Enemy
{
    EnemyService::EnemyService() { m_enemy_controller = new EnemyController(); }

    EnemyService::~EnemyService() { delete m_enemy_controller; };

    void EnemyService::initialize() { m_enemy_controller->initialize(); }

    void EnemyService::update() { m_enemy_controller->update(); }

    void EnemyService::render() { m_enemy_controller->render(); }
}
