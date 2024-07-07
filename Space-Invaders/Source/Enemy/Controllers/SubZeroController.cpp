#include "../../Header/Enemy/Controllers/SubZeroController.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Enemy
{

	using namespace Global;

	namespace Controller
	{
		SubzeroController::SubzeroController(EnemyType type) : EnemyController(type) { }

		SubzeroController::~SubzeroController() { }

		void SubzeroController::Initialize()
		{
			EnemyController::Initialize();
			enemyModel->SetMovementDirection(MovementDirection::DOWN);
			rateOfFire = subzeroRateOfFire;
		}

		void SubzeroController::FireBullet()
		{
			// we spawn the bullet and pass the needed parameters
			ServiceLocator::GetInstance()->GetBulletService()->SpawnBullet(Bullet::BulletType::TORPEDO,
				enemyModel->GetEnemyPosition() + enemyModel->barrelPositionOffset,
				Bullet::MovementDirection::DOWN);
		}

		void SubzeroController::Move()
		{
			switch (enemyModel->GetMovementDirection())
			{
			case::Enemy::MovementDirection::DOWN:
				MoveDown();
				break;
			}
		}

		void SubzeroController::MoveDown()
		{
			sf::Vector2f currentPosition = enemyModel->GetEnemyPosition();
			currentPosition.y += verticalMovementSpeed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

			enemyModel->SetEnemyPosition(currentPosition);
		}
	}
}