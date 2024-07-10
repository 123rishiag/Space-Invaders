#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Entity/EntityConfig.h"

namespace Enemy
{
    enum class EnemyType;
    enum class EnemyState;
    class EnemyView;
    class EnemyModel;
    class EnemyController
    {
    protected:
        float verticalMovementSpeed = 30.f;
        float horizontalMovementSpeed = 200.0f;

        float rateOfFire = 3.f; //we want to fire the bullet every 3 seconds
        float elapsedFireDuration = 0.f; //variable to check how long it has been since we last fired

        EnemyView* enemyView;
        EnemyModel* enemyModel;

        void UpdateFireTimer();
        void ProcessBulletFire();
        virtual void FireBullet() = 0;

        virtual void Move() = 0;

        sf::Vector2f GetRandomInitialPosition() const;
        void HandleOutOfBounds();

    public:
        EnemyController(EnemyType type, Entity::EntityType ownerType);
        virtual ~EnemyController();

        virtual void Initialize();
        void Update();
        void Render();

        EnemyType GetEnemyType() const;
        EnemyState GetEnemyState() const;

        sf::Vector2f GetEnemyPosition();

        Entity::EntityType GetEntityType() const;
    };
}