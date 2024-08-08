#pragma once
#include <SFML/System/Vector2.hpp>

namespace Enemy
{
    class EnemyView;
    class EnemyModel;

    class EnemyController
    {
        private:
            EnemyView* m_enemy_view;
            EnemyModel* m_enemy_model;
        public:
            EnemyController();
            ~EnemyController();

            void initialize();
            void update();
            void render();

            void move();
            void moveLeft();
            void moveRight();
            void moveDown();
            sf::Vector2f getPosition();
    };
}
