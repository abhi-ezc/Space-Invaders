#include "./../../public/enemy/EnemyService.h"

#include "../../public/time/TimeService.h"
#include "./../../public/enemy/EnemyController.h"
#include "../../public/enemy/controllers/ZapperController.h"
#include "../../public/enemy/controllers/SubZeroController.h"
#include "./../../public/global/ServiceLocator.h"

namespace Enemy
{
    using namespace Global;

    EnemyService::EnemyService()
    {
        m_remaining_spawn_delay = 0;
    };

    EnemyService::~EnemyService()
    {
        triggerLifeCycleFunction(EnemyLifeCycle::DELETE);
    };

    void EnemyService::initialize()
    {
        spawnEnemy();
    }

    void EnemyService::update()
    {
        updateRemainingSpawnDelay();
        processEnemySpawn();
        triggerLifeCycleFunction(EnemyLifeCycle::UPDATE);
    }

    void EnemyService::render()
    {
        triggerLifeCycleFunction(EnemyLifeCycle::RENDER);
    }

    void EnemyService::spawnEnemy()
    {
        const auto enemyController = new Controllers::ZapperController();
        enemyController->initialize();
        m_enemy_controllers.push_back(enemyController);
    }

    void EnemyService::triggerLifeCycleFunction(EnemyLifeCycle lifeCycle)
    {
        for (const auto enemy : m_enemy_controllers)
        {
            if (enemy == nullptr)
            {
                continue;
            }

            switch (lifeCycle)
            {
                case EnemyLifeCycle::INITIALIZE:
                    enemy->initialize();
                    break;
                case EnemyLifeCycle::DELETE:
                    delete enemy;
                    break;
                case EnemyLifeCycle::RENDER:
                    enemy->render();
                    break;
                case EnemyLifeCycle::UPDATE:
                    enemy->update();
                    break;
            }
        }
    }

    void EnemyService::updateRemainingSpawnDelay()
    {
        if (m_remaining_spawn_delay <= 0)
        {
            m_remaining_spawn_delay = m_spawn_delay;
        }
        else
        {
            m_remaining_spawn_delay -= ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
        }
    }

    void EnemyService::processEnemySpawn()
    {
        if (m_remaining_spawn_delay >= m_spawn_delay)
        {
            spawnEnemy();
        }
    }
}
