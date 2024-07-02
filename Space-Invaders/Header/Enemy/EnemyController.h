#pragma once
#include <SFML/Graphics.hpp>

namespace Enemy
{
    enum class EnemyType;
    enum class EnemyState;
    class EnemyView;
    class EnemyModel;
    class EnemyController
    {
    protected:
        EnemyView* enemyView;
        EnemyModel* enemyModel;

        virtual void Move() = 0;
        /*
        void MoveLeft();
        void MoveRight();
        void MoveDown();
        */

        sf::Vector2f GetRandomInitialPosition() const;
        void HandleOutOfBounds();

    public:
        EnemyController(EnemyType type);
        virtual ~EnemyController();

        virtual void Initialize();
        void Update();
        void Render();

        EnemyType GetEnemyType() const;
        EnemyState GetEnemyState() const;

        sf::Vector2f GetEnemyPosition();
    };
}