#pragma once
#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Powerup/PowerupConfig.h"
#include "../../Header/Collision/ICollider.h"

namespace Enemy
{
    namespace Controller
    {
        class UFOController : public EnemyController
        {
        private:

            void Move() override;
            void MoveLeft();
            void MoveRight();

            void FireBullet() override;
            Powerup::PowerupType GetRandomPowerupType();

        public:
            UFOController(EnemyType type);
            ~UFOController();

            void Initialize() override;

            void OnCollision(ICollider* otherCollider) override;
        };
    }
}