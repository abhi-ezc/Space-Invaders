#pragma once
#include <SFML/System/Vector2.hpp>

namespace Enemy
{
    class EnemyModel
    {
        private:
            sf::Vector2f m_spawn_position = sf::Vector2f(0, 0);
            sf::Vector2f m_current_position;
        public:
            EnemyModel();
            ~EnemyModel();

            void initialize();
            void update();
            void render();

            sf::Vector2f getPlayerPosition();

            void setCurrentPosition(sf::Vector2f current_position);
    };
}
