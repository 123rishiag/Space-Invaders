#pragma once
#include <SFML/Graphics.hpp>

namespace Enemy
{
    // new enum class
    enum class MovementDirection
    {
        LEFT,
        RIGHT,
        DOWN,
    };

    class EnemyModel
    {
    private:
        sf::Vector2f referencePosition = sf::Vector2f(50.f, 50.f);
        sf::Vector2f enemyPosition;

        MovementDirection movementDirection; 	//Declaration

    public:
        EnemyModel();
        ~EnemyModel();

        //const data related to movement and bounds
        const sf::Vector2f leftMostPosition = sf::Vector2f(50.f, 950.f);
        const sf::Vector2f rightMostPosition = sf::Vector2f(1800.f, 950.f);

        const float verticalTravelDistance = 100.f;
        const float enemyMovementSpeed = 250.0f;

        void Initialize();

        sf::Vector2f GetEnemyPosition() const;
        void SetEnemyPosition(sf::Vector2f position);

        sf::Vector2f GetReferencePosition() const;
        void SetReferencePosition(sf::Vector2f position);

        MovementDirection GetMovementDirection() const;
        void SetMovementDirection(MovementDirection direction);

    };
}