#pragma once
#include "../../Header/Enemy/EnemyController.h"

namespace Enemy
{
    namespace Controller
    {
        class ZapperController : public EnemyController
        {
        private:
            const float zapperRateOfFire = 4.f;
            float verticalTravelDistance = 100.f;

            void FireBullet() override;
            void Move() override;
            void MoveLeft();
            void MoveRight();
            void MoveDown();

        public:
            ZapperController(EnemyType type);
            ~ZapperController();

            void Initialize() override;
        };
    }
}