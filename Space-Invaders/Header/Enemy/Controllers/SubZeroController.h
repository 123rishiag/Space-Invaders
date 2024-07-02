#pragma once
#include "../../Header/Enemy/EnemyController.h"

namespace Enemy
{
    namespace Controller
    {
        class SubzeroController : public EnemyController
        {
        private:
            float verticalMovementSpeed = 100.f;

            void Move() override;
            void MoveDown();

        public:
            SubzeroController(EnemyType type);
            ~SubzeroController();

            void Initialize() override;
        };
    }
}