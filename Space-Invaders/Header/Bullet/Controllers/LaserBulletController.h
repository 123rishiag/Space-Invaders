#pragma once
#include "../../Header/Bullet/BulletController.h"
#include "../../Header/Entity/EntityConfig.h"

namespace Bullet
{
    namespace Controller
    {
        class LaserBulletController : public BulletController
        {
        public:
            LaserBulletController(BulletType type, Entity::EntityType ownerType);
            ~LaserBulletController();

            void Initialize(sf::Vector2f position, MovementDirection direction) override;
        };
    }
}