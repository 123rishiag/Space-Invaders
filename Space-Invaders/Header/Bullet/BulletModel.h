#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Entity/EntityConfig.h"

namespace Bullet
{
    enum class BulletType;
    enum class MovementDirection;

    class BulletModel
    {
    private:
        float movementSpeed = 300.f;
        sf::Vector2f bulletPosition;

        BulletType bulletType;
        MovementDirection movementDirection;

        Entity::EntityType bulletOwner;

    public:

        BulletModel(BulletType type, Entity::EntityType ownerType);
        ~BulletModel();

        void Initialize(sf::Vector2f position, MovementDirection direction);

        sf::Vector2f GetBulletPosition();
        void SetBulletPosition(sf::Vector2f position);

        BulletType GetBulletType() const;
        void SetBulletType(BulletType type);

        MovementDirection GetMovementDirection();
        void SetMovementDirection(MovementDirection direction);

        float GetMovementSpeed();
        void SetMovementSpeed(float speed);

        Entity::EntityType GetEntityType() const;
        void SetEntityType(Entity::EntityType ownerType);

    };
}