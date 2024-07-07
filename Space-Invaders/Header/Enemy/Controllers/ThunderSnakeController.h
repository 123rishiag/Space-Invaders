#pragma once
#include "../../Header/Enemy/EnemyController.h"

namespace Enemy
{
    namespace Controller
    {
        class ThunderSnakeController : public EnemyController
        {
        private:
            float verticalMovementSpeed = 20.f;
            float enemyMovementSpeed = 550.0f;

            void Move() override;
            void MoveLeft();
            void MoveRight();

        public:
            ThunderSnakeController(EnemyType type);
            ~ThunderSnakeController();

            void Initialize() override;
        };
    }
}