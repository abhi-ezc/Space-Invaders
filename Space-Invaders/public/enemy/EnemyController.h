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
            virtual ~EnemyController();

            virtual void initialize();
            void update();
            void render();

            virtual void move() = 0;
            virtual void moveLeft();
            virtual void moveRight();
            virtual void moveDown();
            sf::Vector2f getPosition();
    };
}
