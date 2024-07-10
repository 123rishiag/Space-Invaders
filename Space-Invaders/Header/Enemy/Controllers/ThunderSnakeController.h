#pragma once
#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Entity/EntityConfig.h"

namespace Enemy
{
    namespace Controller
    {
        class ThunderSnakeController : public EnemyController
        {
        private:
            const float thunderSnakeRateOfFire = 6.f;
            float verticalMovementSpeed = 20.f;
            float horizontalMovementSpeed = 550.0f;

            void FireBullet() override;
            void Move() override;
            void MoveLeft();
            void MoveRight();

        public:
            ThunderSnakeController(EnemyType type, Entity::EntityType ownerType);
            ~ThunderSnakeController();

            void Initialize() override;
        };
    }
}