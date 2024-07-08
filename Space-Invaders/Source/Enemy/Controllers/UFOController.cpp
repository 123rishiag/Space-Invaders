#include "../../Header/Enemy/Controllers/UFOController.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Global/ServiceLocator.h"


namespace Enemy
{
    using namespace Global;

    namespace Controller
    {
        UFOController::UFOController(EnemyType type) : EnemyController(type) { }

        UFOController::~UFOController() { }

        void UFOController::Initialize()
        {
            EnemyController::Initialize(); // init the base controller
        }

        void UFOController::FireBullet()
        {
        }

        Powerup::PowerupType UFOController::GetRandomPowerupType()
        {
            std::srand(static_cast<unsigned int>(std::time(nullptr)));

            //We add '1'  to OutscalBomb below because enum has a 0 index, making the bomb number 3, we need to add 1 to make it 4 

            int randomValue = std::rand() % (static_cast<int>(Powerup::PowerupType::OUTSCAL_BOMB) + 1);
            return static_cast<Powerup::PowerupType>(randomValue);
        }

        // Method for moving the Thunder Snake enemy
        void UFOController::Move()
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
        void UFOController::MoveLeft()
        {
            // Get the current position of the enemy
            sf::Vector2f currentPosition = enemyModel->GetEnemyPosition();

            // Update the position to move left
            currentPosition.x -= horizontalMovementSpeed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

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
        void UFOController::MoveRight()
        {
            // Get the current position of the enemy
            sf::Vector2f currentPosition = enemyModel->GetEnemyPosition();

            // Update the position to move right
            currentPosition.x += horizontalMovementSpeed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

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