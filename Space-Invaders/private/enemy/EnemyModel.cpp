#include "./../../public/enemy/EnemyModel.h"

namespace Enemy
{
    EnemyModel::EnemyModel() = default;
    EnemyModel::~EnemyModel() = default;

    void EnemyModel::initialize() { m_current_position = m_spawn_position; }

    void EnemyModel::update() { }

    void EnemyModel::render() { }

    sf::Vector2f EnemyModel::getCurrentPosition() { return m_current_position; }
    void EnemyModel::setCurrentPosition(sf::Vector2f current_position) { m_current_position = current_position; }

    MovementDirection EnemyModel::getMovementDirection() { return m_movement_direction; }

    void EnemyModel::setMovementDirection(MovementDirection movementDirection)
    {
        m_movement_direction = movementDirection;
    }

    MovementDirection EnemyModel::getPreviousDirection() { return m_previous_direction; }
    void EnemyModel::setPreviousDirection(MovementDirection direction) { m_previous_direction = direction; }

    float EnemyModel::getVerticalTravelDistance() { return m_vertical_travel_distance; }

    int EnemyModel::getMovementSpeed() { return m_movement_speed; }

    sf::Vector2f EnemyModel::getLeftMostPosition() { return m_left_most_position; }
    sf::Vector2f EnemyModel::getRightMostPosition() { return m_right_most_position; }
    float EnemyModel::getDownMostPositionY() { return m_ref_position.y + m_vertical_travel_distance; }

    sf::Vector2f EnemyModel::getReferencePosition() { return m_ref_position; }
    void EnemyModel::setReferencePosition(sf::Vector2f refPosition) { m_ref_position = refPosition; }
}
