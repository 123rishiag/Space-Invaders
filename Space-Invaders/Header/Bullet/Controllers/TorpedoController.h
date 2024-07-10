#pragma once
#include "../../Header/Bullet/BulletController.h"
#include "../../Header/Entity/EntityConfig.h"

namespace Bullet
{
    namespace Controller
    {
        class TorpedoController : public BulletController
        {
        private:
            const float torpedoMovementSpeed = 200.f;

        public:
            TorpedoController(BulletType type, Entity::EntityType ownerType);
            ~TorpedoController();

            void Initialize(sf::Vector2f position, MovementDirection direction) override;
        };
    }
}