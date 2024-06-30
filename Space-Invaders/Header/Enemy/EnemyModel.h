#pragma once
#include <SFML/Graphics.hpp>

namespace Enemy
{
    class EnemyModel
    {
    private:
        sf::Vector2f referencePosition = sf::Vector2f(50.f, 50.f);
        sf::Vector2f enemyPosition;

    public:
        EnemyModel();
        ~EnemyModel();

        void Initialize();

        sf::Vector2f GetEnemyPosition() const;
        void SetEnemyPosition(sf::Vector2f position);

        sf::Vector2f GetReferencePosition() const;
        void SetReferencePosition(sf::Vector2f position);

    };
}