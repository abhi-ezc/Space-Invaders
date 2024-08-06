#include "./../../public/enemy/EnemyModel.h"

namespace Enemy
{
    EnemyModel::EnemyModel() = default;
    EnemyModel::~EnemyModel() = default;

    void EnemyModel::initialize() { m_current_position = m_spawn_position; }

    void EnemyModel::update() { }

    void EnemyModel::render() { }

    sf::Vector2f EnemyModel::getPlayerPosition() { return m_current_position; }

    void EnemyModel::setCurrentPosition(sf::Vector2f current_position) { m_current_position = current_position; }
}
