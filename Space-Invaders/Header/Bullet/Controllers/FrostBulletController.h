#pragma once
#include "../../Header/Bullet/BulletController.h"
#include "../../Header/Entity/EntityConfig.h"

namespace Bullet
{
    namespace Controller
    {
        class FrostBulletController : public BulletController
        {
        private:
            const float frostBulletMovementSpeed = 500.f;

        public:
            FrostBulletController(BulletType type, Entity::EntityType ownerType);
            ~FrostBulletController();

            void Initialize(sf::Vector2f position, MovementDirection direction) override;
        };
    }
}