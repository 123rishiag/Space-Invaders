#include "../../Header/Powerup/PowerupModel.h"

namespace Powerup
{
	PowerupModel::PowerupModel(PowerupType type)
	{
		powerupType = type;
	}

	PowerupModel::~PowerupModel() { }

	void PowerupModel::Initialize(sf::Vector2f position)
	{
		powerupPosition = position;
	}

	sf::Vector2f PowerupModel::GetPowerupPosition()
	{
		return powerupPosition;
	}

	void PowerupModel::SetPowerupPosition(sf::Vector2f position)
	{
		powerupPosition = position;
	}

	PowerupType PowerupModel::GetPowerupType()
	{
		return powerupType;
	}

	void PowerupModel::SetPowerupType(PowerupType type)
	{
		powerupType = type;
	}

	float PowerupModel::GetMovementSpeed()
	{
		return movementSpeed;
	}

	void PowerupModel::SetMovementSpeed(float speed)
	{
		movementSpeed = speed;
	}
}