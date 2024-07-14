#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Enemy/EnemyView.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Bullet/BulletConfig.h"
#include "../../Header/Entity/EntityConfig.h"
#include "../../Header/Bullet/BulletController.h"
#include "../../Header/Player/PlayerController.h"
#include "../../Header/Sound/SoundService.h"

namespace Enemy
{
	using namespace Global;
	using namespace Time;
	using namespace Bullet;
	using namespace Collision;
	using namespace Entity;
	using namespace Player;
	using namespace Sound;

	EnemyController::EnemyController(EnemyType type)
	{
		enemyView = new EnemyView();
		enemyModel = new EnemyModel(type);
	}

	EnemyController::~EnemyController()
	{
		delete (enemyView);
		delete (enemyModel);
	}

	void EnemyController::Initialize()
	{
		enemyModel->Initialize();
		enemyModel->SetEnemyPosition(GetRandomInitialPosition());
		enemyView->Initialize(this); // we will discuss this soon
	}

	void EnemyController::Update()
	{
		Move();
		UpdateFireTimer();
		ProcessBulletFire();
		enemyView->Update();
	}

	void EnemyController::Render()
	{
		enemyView->Render();
	}

	void EnemyController::UpdateFireTimer()
	{
		elapsedFireDuration += ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime(); //update the elapsed duration
	}

	void EnemyController::ProcessBulletFire() //if elapsed duration is equal to or more than the amount of time we want to wait until firing than call the fire method.
	{
		if (elapsedFireDuration >= rateOfFire)
		{
			FireBullet();
			elapsedFireDuration = 0.f; //set elapsed duration back to 0.
		}
	}

	// Function to generate a random initial position for the enemy.
	sf::Vector2f EnemyController::GetRandomInitialPosition() const
	{
		// Calculate the distance between the leftmost and rightmost positions of the enemy.
		float xOffsetDistance = (std::rand() % static_cast<int>(enemyModel->rightMostPosition.x - enemyModel->leftMostPosition.x));

		// Calculate the x position by adding the x offset distance to the leftmost position.
		float xPosition = enemyModel->leftMostPosition.x + xOffsetDistance;

		// The y position remains the same.
		float yPosition = enemyModel->leftMostPosition.y;

		// Return the calculated position as a 2D vector.
		return sf::Vector2f(xPosition, yPosition);
	}

	EnemyType EnemyController::GetEnemyType() const
	{
		return enemyModel->GetEnemyType();
	}

	EnemyState EnemyController::GetEnemyState() const
	{
		return enemyModel->GetEnemyState();
	}

	sf::Vector2f EnemyController::GetEnemyPosition()
	{
		return enemyModel->GetEnemyPosition();
	}

	const sf::Sprite& EnemyController::GetColliderSprite()
	{
		return enemyView->GetEnemySprite();
	}

	void EnemyController::OnCollision(ICollider* otherCollider)
	{
		BulletController* bulletController = dynamic_cast<BulletController*>(otherCollider);
		if (bulletController && bulletController->GetEntityType() != EntityType::ENEMY)
		{
			Destroy();
			return;
		}

		PlayerController* playerController = dynamic_cast<PlayerController*>(otherCollider);
		if (playerController)
		{
			Destroy();
			return;
		}
	}

	void EnemyController::Destroy()
	{
		ServiceLocator::GetInstance()->GetAnimationService()->SpawnAnimationSystem(enemyModel->GetEnemyPosition(),
			Animation::AnimationType::EXPLOSION);

		ServiceLocator::GetInstance()->GetSoundService()->PlaySound(SoundType::EXPLOSION);


		ServiceLocator::GetInstance()->GetPlayerService()->IncreaseEnemiesKilled(1);
		ServiceLocator::GetInstance()->GetEnemyService()->DestroyEnemy(this);
	}

}