#pragma once

namespace Enemy
{
    class EnemyController;

    class EnemyService
    {
        private:
            EnemyController* m_enemy_controller;
        public:
            EnemyService();
            ~EnemyService();

            void initialize();
            void update();
            void render();
    };
}
