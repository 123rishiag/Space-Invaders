#pragma once
#include "../../Header/Enemy/EnemyController.h"

namespace Enemy
{
    namespace Controller
    {
        class SubzeroController : public EnemyController
        {
        private:
            const float subzeroRateOfFire = 5.f;
            float verticalMovementSpeed = 100.f;

            void FireBullet() override;
            void Move() override;
            void MoveDown();

        public:
            SubzeroController(EnemyType type);
            ~SubzeroController();

            void Initialize() override;
        };
    }
}