#include "../../Header/Enemy/Controllers/ThunderSnakeController.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Global/ServiceLocator.h"


namespace Enemy
{
    using namespace Global;

    namespace Controller
    {
        ThunderSnakeController::ThunderSnakeController(EnemyType type, Entity::EntityType ownerType) : EnemyController(type, ownerType) { }

        ThunderSnakeController::~ThunderSnakeController() { }

        void ThunderSnakeController::Initialize()
        {
            EnemyController::Initialize(); // init the base controller
            rateOfFire = thunderSnakeRateOfFire;
        }

        void ThunderSnakeController::FireBullet()
        {
            // we spawn the bullet and pass the needed parameters
            ServiceLocator::GetInstance()->GetBulletService()->SpawnBullet(Bullet::BulletType::FROST_BULLET, 
                enemyModel->GetEntityType(), enemyModel->GetEnemyPosition() + enemyModel->barrelPositionOffset,
                Bullet::MovementDirection::DOWN);
        }

        // Method for moving the Thunder Snake enemy
        void ThunderSnakeController::Move()
        {
            // Switch statement based on the movement direction of the enemy
            switch (enemyModel->GetMovementDirection())
            {
                // If the movement direction is LEFT
            case::Enemy::MovementDirection::LEFT:
                MoveLeft();
                break;

                // If the movement direction is RIGHT
            case::Enemy::MovementDirection::RIGHT:
                MoveRight();
                break;
            }
        }

        // Method for moving the Thunder Snake enemy left
        void ThunderSnakeController::MoveLeft()
        {
            // Get the current position of the enemy
            sf::Vector2f currentPosition = enemyModel->GetEnemyPosition();

            // Update the position to move left
            currentPosition.x -= horizontalMovementSpeed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();
            currentPosition.y += verticalMovementSpeed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

            // Check if the enemy reached the leftmost position
            if (currentPosition.x <= enemyModel->leftMostPosition.x)
            {
                // Set movement direction to DOWN and update reference position
                enemyModel->SetMovementDirection(MovementDirection::RIGHT);
                enemyModel->SetReferencePosition(currentPosition);
            }
            else
            {
                // Update the enemy position
                enemyModel->SetEnemyPosition(currentPosition);
            }
        }

        // Method for moving the Thunder Snake enemy right
        void ThunderSnakeController::MoveRight()
        {
            // Get the current position of the enemy
            sf::Vector2f currentPosition = enemyModel->GetEnemyPosition();

            // Update the position to move right
            currentPosition.x += horizontalMovementSpeed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();
            currentPosition.y += verticalMovementSpeed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

            // Check if the enemy reached the rightmost position
            if (currentPosition.x >= enemyModel->rightMostPosition.x)
            {
                // Set movement direction to DOWN and update reference position
                enemyModel->SetMovementDirection(MovementDirection::LEFT);
                enemyModel->SetReferencePosition(currentPosition);
            }
            else
            {
                // Update the enemy position
                enemyModel->SetEnemyPosition(currentPosition);
            }
        }
    }
}