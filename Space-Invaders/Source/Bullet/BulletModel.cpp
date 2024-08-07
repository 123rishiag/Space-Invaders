#include "../../Header/Bullet/BulletModel.h"

namespace Bullet
{
	BulletModel::BulletModel(BulletType type, Entity::EntityType ownerType)
	{
		bulletType = type;
		bulletOwner = ownerType;
	}

	BulletModel::~BulletModel() { }

	void BulletModel::Initialize(sf::Vector2f position, MovementDirection direction)
	{
		movementDirection = direction;
		bulletPosition = position;
	}

	sf::Vector2f BulletModel::GetBulletPosition()
	{
		return bulletPosition;
	}

	void BulletModel::SetBulletPosition(sf::Vector2f position)
	{
		bulletPosition = position;
	}

	BulletType BulletModel::GetBulletType() const
	{
		return bulletType;
	}

	void BulletModel::SetBulletType(BulletType type)
	{
		bulletType = type;
	}

	MovementDirection BulletModel::GetMovementDirection()
	{
		return movementDirection;
	}

	void BulletModel::SetMovementDirection(MovementDirection direction)
	{
		movementDirection = direction;
	}

	float BulletModel::GetMovementSpeed()
	{
		return movementSpeed;
	}

	void BulletModel::SetMovementSpeed(float speed)
	{
		movementSpeed = speed;
	}

	Entity::EntityType BulletModel::GetEntityType() const
	{
		return bulletOwner;
	}

	void BulletModel::SetEntityType(Entity::EntityType ownerType)
	{
		bulletOwner = ownerType;
	}
}