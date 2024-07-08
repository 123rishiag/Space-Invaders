#pragma once

namespace Enemy
{
    enum class EnemyType
    {
        SUBZERO,
        THUNDER_SNAKE,
        UFO,
        ZAPPER,
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
}