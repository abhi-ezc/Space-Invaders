#pragma once

namespace Enemy
{
    enum class EnemyType
    {
        ZAPPER = 0,
        SUBZERO,
        UFO,
        THUNDER_SNAKE,
    };

    enum class EnemyState
    {
        PATROLLING,
        ATTACK,
        DEAD,
    };

    enum class MovementDirection
    {
        LEFT,
        RIGHT,
        DOWN,
    };

    enum class EnemyLifeCycle
    {
        INITIALIZE,
        UPDATE,
        RENDER,
        DELETE
    };
}
