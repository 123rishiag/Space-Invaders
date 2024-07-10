#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Entity/EntityConfig.h"

namespace Enemy
{
    enum class EnemyType;
    enum class MovementDirection;
    enum class EnemyState;

    class EnemyModel
    {
    private:
        sf::Vector2f referencePosition = sf::Vector2f(50.f, 50.f);
        sf::Vector2f enemyPosition;

        MovementDirection movementDirection; 
        EnemyType enemyType;
        EnemyState enemyState;

        Entity::EntityType bulletOwner;

    public:
        EnemyModel(EnemyType type, Entity::EntityType ownerType);
        ~EnemyModel();

        //const data related to movement and bounds
        const sf::Vector2f leftMostPosition = sf::Vector2f(50.f, 50.f);
        const sf::Vector2f rightMostPosition = sf::Vector2f(1800.f, 50.f);
        const sf::Vector2f barrelPositionOffset = sf::Vector2f(20.f, 50.f); // we add this offset variable

        const float verticalTravelDistance = 100.f;
        const float enemyMovementSpeed = 250.0f;

        void Initialize();

        sf::Vector2f GetEnemyPosition() const;
        void SetEnemyPosition(sf::Vector2f position);

        sf::Vector2f GetReferencePosition() const;
        void SetReferencePosition(sf::Vector2f position);

        EnemyType GetEnemyType() const;
        void SetEnemyType(EnemyType type);

        EnemyState GetEnemyState() const;
        void SetEnemyState(EnemyState state);

        MovementDirection GetMovementDirection() const;
        void SetMovementDirection(MovementDirection direction);

        Entity::EntityType GetEntityType() const;

    };
}