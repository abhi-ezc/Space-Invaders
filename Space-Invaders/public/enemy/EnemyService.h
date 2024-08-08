#pragma once
#include "vector"

namespace Enemy
{
    enum class EnemyLifeCycle
    {
        INITIALIZE,
        UPDATE,
        RENDER,
        DELETE
    };

    class EnemyController;

    class EnemyService
    {
        private:
            std::vector<EnemyController*> m_enemy_controllers;
            const float m_spawn_delay = 3.f;
            float m_remaining_spawn_delay;

            void spawnEnemy();
            void triggerLifeCycleFunction(EnemyLifeCycle lifeCycle);
            void updateRemainingSpawnDelay();
            void processEnemySpawn();
        public:
            EnemyService();
            ~EnemyService();

            void initialize();
            void update();
            void render();
    };
}
