#pragma once
#include "../../Header/Bullet/BulletController.h"

namespace Bullet
{
    namespace Controller
    {
        class FrostBulletController : public BulletController
        {
        private:
            const float frostBulletMovementSpeed = 500.f;

        public:
            FrostBulletController(BulletType type);
            ~FrostBulletController();

            void Initialize(sf::Vector2f position, MovementDirection direction) override;
        };
    }
}