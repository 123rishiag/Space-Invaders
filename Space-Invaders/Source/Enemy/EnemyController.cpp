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
		enemyView->Initialize(this); // we will discuss this soon
	}

	void EnemyController::Update()
	{
		Move();
		enemyView->Update();
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

	EnemyType EnemyController::GetEnemyType() const
	{
		return enemyModel->GetEnemyType();
	}

	sf::Vector2f EnemyController::GetEnemyPosition()
	{
		return enemyModel->GetEnemyPosition();
	}
}