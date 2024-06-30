#pragma once
#include <SFML/Graphics.hpp>

namespace Enemy
{
    class EnemyView;
    class EnemyModel;

    class EnemyController
    {
    private:

        EnemyView* enemyView;
        EnemyModel* enemyModel;

        void Move();
        void MoveLeft();
        void MoveRight();
        void MoveDown();

    public:
        EnemyController();
        ~EnemyController();

        void Initialize();
        void Update();
        void Render();

        sf::Vector2f GetEnemyPosition();
    };
}