#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Enemy/EnemyView.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Enemy
{
	using namespace Global;

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
		HandleOutOfBounds();
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

	void EnemyController::HandleOutOfBounds()
	{
		sf::Vector2f enemyPosition = GetEnemyPosition();
		sf::Vector2u windowSize = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow()->getSize();

		// Destroy the enemy if it goes out of bounds.
		if (enemyPosition.x < 0 || enemyPosition.x > windowSize.x ||
			enemyPosition.y < 0 || enemyPosition.y > windowSize.y)
		{
			ServiceLocator::GetInstance()->GetEnemyService()->DestroyEnemy(this);
		}
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
}