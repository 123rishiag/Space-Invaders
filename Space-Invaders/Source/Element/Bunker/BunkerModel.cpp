#include "../../Header/Element/Bunker/BunkerModel.h"

namespace Element
{
	BunkerModel::BunkerModel() { }

	BunkerModel::~BunkerModel() { }

	void BunkerModel::Initialize()
	{
		bunkerPosition = referencePosition;
	}

	sf::Vector2f BunkerModel::GetBunkerPosition() const
	{
		return bunkerPosition;
	}

	void BunkerModel::SetBunkerPosition(sf::Vector2f position)
	{
		bunkerPosition = position;
	}

	sf::Vector2f BunkerModel::GetReferencePosition() const
	{
		return referencePosition;
	}

	void BunkerModel::SetReferencePosition(sf::Vector2f position)
	{
		referencePosition = position;
	}
}