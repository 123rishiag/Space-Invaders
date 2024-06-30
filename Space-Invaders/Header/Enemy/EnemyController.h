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

    public:
        EnemyController();
        ~EnemyController();

        void Initialize();
        void Update();
        void Render();

        sf::Vector2f GetEnemyPosition();
    };
}