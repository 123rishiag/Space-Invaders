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
		enemyView->Update();
		HandleOutOfBounds();
	}

	void EnemyController::Render()
	{
		enemyView->Render();
	}

	/*
	//switch between move functions based on move dir state
	void EnemyController::Move()
	{
		switch (enemyModel->GetMovementDirection())
		{
		case::Enemy::MovementDirection::LEFT:
			MoveLeft();
			break;

		case::Enemy::MovementDirection::RIGHT:
			MoveRight();
			break;

		case::Enemy::MovementDirection::DOWN:
			MoveDown();
			break;
		}
	}

	void EnemyController::MoveLeft()
	{
		// Get current pos
		// Move left by multiplying by speed and delta time
		sf::Vector2f currentPosition = enemyModel->GetEnemyPosition();
		currentPosition.x -= enemyModel->enemyMovementSpeed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

		//check for bounds
		if (currentPosition.x <= enemyModel->leftMostPosition.x)
		{
			//if reached the left most pos
			//start moving down
			//set ref pos for the downwards movement
			enemyModel->SetMovementDirection(MovementDirection::DOWN);
			enemyModel->SetReferencePosition(currentPosition);
		}
		else enemyModel->SetEnemyPosition(currentPosition);
	}

	void EnemyController::MoveRight()
	{
		sf::Vector2f currentPosition = enemyModel->GetEnemyPosition(); //get enemy pos
		currentPosition.x += enemyModel->enemyMovementSpeed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime(); //move

		if (currentPosition.x >= enemyModel->rightMostPosition.x) //check if we reached right most pos
		{
			enemyModel->SetMovementDirection(MovementDirection::DOWN); // move
			enemyModel->SetReferencePosition(currentPosition);// set ref pos
		}
		else enemyModel->SetEnemyPosition(currentPosition); //if we have not reached right most pos continue moving right
	}

	void EnemyController::MoveDown()
	{
		sf::Vector2f currentPosition = enemyModel->GetEnemyPosition();
		currentPosition.y += enemyModel->enemyMovementSpeed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

		//check if enemy has moved the specified distance downwards
		if (currentPosition.y >= enemyModel->GetReferencePosition().y + enemyModel->verticalTravelDistance)
		{
			//check where to move them based on position
			if (enemyModel->GetReferencePosition().x <= enemyModel->leftMostPosition.x) enemyModel->SetMovementDirection(MovementDirection::RIGHT);
			else enemyModel->SetMovementDirection(MovementDirection::LEFT);
		}
		else enemyModel->SetEnemyPosition(currentPosition);
	}
	*/

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