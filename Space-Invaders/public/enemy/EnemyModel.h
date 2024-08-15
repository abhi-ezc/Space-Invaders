#pragma once
#include <SFML/System/Vector2.hpp>

namespace Enemy
{
    enum class EnemyType;
    enum class EnemyState;
    enum class MovementDirection;

    class EnemyModel
    {
        private:
            sf::Vector2f m_spawn_position = sf::Vector2f(0, 0);
            sf::Vector2f m_current_position;
            sf::Vector2f m_ref_position;

            MovementDirection m_movement_direction;
            MovementDirection m_previous_direction;

            EnemyType m_enemy_type;
            EnemyState m_enemy_state;


            const float m_movement_speed = 200.f;
            const float m_vertical_travel_distance = 30.f;

            const sf::Vector2f m_left_most_position = sf::Vector2f(50.f, 950.f);
            const sf::Vector2f m_right_most_position = sf::Vector2f(1800.f, 950.f);

        public:
            EnemyModel(EnemyType enemyType);
            ~EnemyModel();

            void initialize();
            void update();
            void render();

            sf::Vector2f getCurrentPosition();
            void setCurrentPosition(sf::Vector2f current_position);

            MovementDirection getMovementDirection();
            void setMovementDirection(MovementDirection movementDirection);
            MovementDirection getPreviousDirection();
            void setPreviousDirection(MovementDirection direction);

            float getVerticalTravelDistance();

            float getMovementSpeed();

            sf::Vector2f getLeftMostPosition();
            sf::Vector2f getRightMostPosition();
            float getDownMostPositionY();

            sf::Vector2f getReferencePosition();
            void setReferencePosition(sf::Vector2f refPosition);

            EnemyState getEnemyState();
            void setEnemyState(EnemyState state);

            EnemyType getEnemyType();
            void setEnemyType(EnemyType type);
    };
}
