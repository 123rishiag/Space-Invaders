#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Enemy/EnemyConfig.h"

namespace Enemy
{
	EnemyModel::EnemyModel(EnemyType type)
	{
		enemyType = type;
		bulletOwner = Entity::EntityType::ENEMY;
	}

	EnemyModel::~EnemyModel() { }

	void EnemyModel::Initialize()
	{
		enemyState = EnemyState::PATROLLING;
		movementDirection = MovementDirection::RIGHT;
		enemyPosition = referencePosition;
	}

	sf::Vector2f EnemyModel::GetEnemyPosition() const
	{
		return enemyPosition;
	}

	void EnemyModel::SetEnemyPosition(sf::Vector2f position)
	{
		enemyPosition = position;
	}

	sf::Vector2f EnemyModel::GetReferencePosition() const
	{
		return referencePosition;
	}

	void EnemyModel::SetReferencePosition(sf::Vector2f position)
	{
		referencePosition = position;
	}

	EnemyState EnemyModel::GetEnemyState() const
	{
		return enemyState;
	}

	void EnemyModel::SetEnemyState(EnemyState state)
	{
		enemyState = state;
	}

	EnemyType EnemyModel::GetEnemyType() const
	{
		return enemyType;
	}

	void EnemyModel::SetEnemyType(EnemyType type)
	{
		enemyType = type;
	}

	MovementDirection EnemyModel::GetMovementDirection() const
	{
		return movementDirection;
	}

	void EnemyModel::SetMovementDirection(MovementDirection direction)
	{
		movementDirection = direction;
	}

	Entity::EntityType EnemyModel::GetEntityType() const
	{
		return bulletOwner;
	}

}