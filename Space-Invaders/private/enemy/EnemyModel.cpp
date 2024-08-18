#include "./../../public/enemy/EnemyModel.h"

#include "../../public/enemy/EnemyController.h"
#include "./../../public/enemy/EnemyConfig.h"

namespace Enemy
{
    EnemyModel::EnemyModel(EnemyType enemyType)
    {
        m_enemy_type = enemyType;
    }

    EnemyModel::~EnemyModel() = default;

    void EnemyModel::initialize(EnemyController* controller)
    {
        m_current_position = controller->getRandomInitialPosition();
        m_enemy_state = EnemyState::PATROLLING;
        m_movement_direction = MovementDirection::RIGHT;
    }

    void EnemyModel::update() { }

    void EnemyModel::render() { }

    sf::Vector2f EnemyModel::getCurrentPosition()
    {
        return m_current_position;
    }

    void EnemyModel::setCurrentPosition(sf::Vector2f current_position)
    {
        m_current_position = current_position;
    }

    MovementDirection EnemyModel::getMovementDirection()
    {
        return m_movement_direction;
    }

    void EnemyModel::setMovementDirection(MovementDirection movementDirection)
    {
        m_movement_direction = movementDirection;
    }

    MovementDirection EnemyModel::getPreviousDirection()
    {
        return m_previous_direction;
    }

    void EnemyModel::setPreviousDirection(MovementDirection direction)
    {
        m_previous_direction = direction;
    }

    float EnemyModel::getVerticalTravelDistance()
    {
        return m_vertical_travel_distance;
    }

    float EnemyModel::getMovementSpeed()
    {
        return m_movement_speed;
    }

    sf::Vector2f EnemyModel::getLeftMostPosition()
    {
        return m_left_most_position;
    }

    sf::Vector2f EnemyModel::getRightMostPosition()
    {
        return m_right_most_position;
    }

    sf::Vector2f EnemyModel::getReferencePosition()
    {
        return m_ref_position;
    }

    void EnemyModel::setReferencePosition(sf::Vector2f refPosition)
    {
        m_ref_position = refPosition;
    }

    EnemyState EnemyModel::getEnemyState()
    {
        return m_enemy_state;
    }

    void EnemyModel::setEnemyState(EnemyState state)
    {
        m_enemy_state = state;
    }

    EnemyType EnemyModel::getEnemyType()
    {
        return m_enemy_type;
    }

    void EnemyModel::setEnemyType(EnemyType type)
    {
        m_enemy_type = type;
    }
}
