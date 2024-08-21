#include "./../../public/enemy/EnemyService.h"
#include "../../public/time/TimeService.h"
#include "./../../public/enemy/EnemyController.h"
#include "./../../public/global/ServiceLocator.h"
#include "./../../public/enemy/EnemyConfig.h"

// Different Enemy Controllers
#include "../../public/enemy/controllers/ZapperController.h"
#include "../../public/enemy/controllers/SubZeroController.h"
#include "../../public/enemy/controllers/ThunderSnakeController.h"
#include "../../public/enemy/controllers/UFOController.h"

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

    void EnemyService::destroyEnemy(EnemyController* controller)
    {
        m_enemy_controllers.erase(std::remove(m_enemy_controllers.begin(), m_enemy_controllers.end(), controller),
            m_enemy_controllers.end());

        delete controller;
    }

    void EnemyService::spawnEnemy()
    {
        const auto enemyController = createEnemy(getRandomEnemyType());
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

    EnemyType EnemyService::getRandomEnemyType()
    {
        return static_cast<EnemyType>(rand() % 4);
    }

    EnemyController* EnemyService::createEnemy(EnemyType type)
    {
        switch (type)
        {
            case EnemyType::ZAPPER:
                return new Controllers::ZapperController();
            case EnemyType::SUBZERO:
                return new Controllers::SubZeroController();
            case EnemyType::THUNDER_SNAKE:
                return new Controllers::ThunderSnakeController();
            case EnemyType::UFO:
                return new Controllers::UFOController();
            default:
                return nullptr;
        }
    }
}
