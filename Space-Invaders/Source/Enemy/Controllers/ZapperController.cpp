#include "../../Header/Enemy/Controllers/ZapperController.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Global/ServiceLocator.h"


namespace Enemy
{
    using namespace Global;

    namespace Controller
    {
        ZapperController::ZapperController(EnemyType type) : EnemyController(type) { }

        ZapperController::~ZapperController() { }

        void ZapperController::Initialize()
        {
            EnemyController::Initialize(); // init the base controller
        }

        // Method for moving the Zapper enemy
        void ZapperController::Move()
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

                // If the movement direction is DOWN
            case::Enemy::MovementDirection::DOWN:
                MoveDown();
                break;
            }
        }

        // Method for moving the Zapper enemy left
        void ZapperController::MoveLeft()
        {
            // Get the current position of the enemy
            sf::Vector2f currentPosition = enemyModel->GetEnemyPosition();

            // Update the position to move left
            currentPosition.x -= enemyModel->enemyMovementSpeed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

            // Check if the enemy reached the leftmost position
            if (currentPosition.x <= enemyModel->leftMostPosition.x)
            {
                // Set movement direction to DOWN and update reference position
                enemyModel->SetMovementDirection(MovementDirection::DOWN);
                enemyModel->SetReferencePosition(currentPosition);
            }
            else
            {
                // Update the enemy position
                enemyModel->SetEnemyPosition(currentPosition);
            }
        }

        // Method for moving the Zapper enemy right
        void ZapperController::MoveRight()
        {
            // Get the current position of the enemy
            sf::Vector2f currentPosition = enemyModel->GetEnemyPosition();

            // Update the position to move right
            currentPosition.x += enemyModel->enemyMovementSpeed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

            // Check if the enemy reached the rightmost position
            if (currentPosition.x >= enemyModel->rightMostPosition.x)
            {
                // Set movement direction to DOWN and update reference position
                enemyModel->SetMovementDirection(MovementDirection::DOWN);
                enemyModel->SetReferencePosition(currentPosition);
            }
            else
            {
                // Update the enemy position
                enemyModel->SetEnemyPosition(currentPosition);
            }
        }

        // Method for moving the Zapper enemy down
        void ZapperController::MoveDown()
        {
            // Get the current position of the enemy
            sf::Vector2f currentPosition = enemyModel->GetEnemyPosition();

            // Update the position to move down
            currentPosition.y += enemyModel->enemyMovementSpeed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

            // Check if the enemy reached the reference position plus vertical travel distance
            if (currentPosition.y >= enemyModel->GetReferencePosition().y + verticalTravelDistance)
            {
                // Check if the enemy reference position is on the left side
                if (enemyModel->GetReferencePosition().x <= enemyModel->leftMostPosition.x)
                {
                    // Set movement direction to RIGHT
                    enemyModel->SetMovementDirection(MovementDirection::RIGHT);
                }
                else
                {
                    // Set movement direction to LEFT
                    enemyModel->SetMovementDirection(MovementDirection::LEFT);
                }
            }
            else
            {
                // Update the enemy position
                enemyModel->SetEnemyPosition(currentPosition);
            }
        }
    }
}