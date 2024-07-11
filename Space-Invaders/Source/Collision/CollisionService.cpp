#include "../../Header/Collision/CollisionService.h"
#include "../../Header/Collision/ICollider.h"

namespace Collision
{
	CollisionService::CollisionService() { }

	CollisionService::~CollisionService() { }

	void CollisionService::Initialize() { }

	void CollisionService::Update()
	{
		ProcessCollision();
	}

	void CollisionService::ProcessCollision()
	{
		for (int i = 0; i < colliderList.size(); i++)
		{
			for (int j = i + 1; j < colliderList.size(); j++)
			{
				DoCollision(i, j);
			}
		}
	}

	void CollisionService::DoCollision(int indexI, int indexJ)
	{
		if (colliderList[indexI]->GetCollisionState() == CollisionState::DISABLED ||
			colliderList[indexJ]->GetCollisionState() == CollisionState::DISABLED) return;

		if (HasCollisionOccurred(indexI, indexJ))
		{
			if (AreActiveColliders(indexI, indexJ))
				colliderList[indexI]->OnCollision(colliderList[indexJ]);

			if (AreActiveColliders(indexI, indexJ))
				colliderList[indexJ]->OnCollision(colliderList[indexI]);
		}
	}

	bool CollisionService::HasCollisionOccurred(int indexI, int indexJ)
	{
		const sf::Sprite& colliderOneSprite = colliderList[indexI]->GetColliderSprite();
		const sf::Sprite& colliderTwoSprite = colliderList[indexJ]->GetColliderSprite();

		return colliderOneSprite.getGlobalBounds().intersects(colliderTwoSprite.getGlobalBounds());
	}

	bool CollisionService::AreActiveColliders(int indexI, int indexJ)
	{
		return (indexI < colliderList.size() && indexJ < colliderList.size() &&
			colliderList[indexI] != nullptr && colliderList[indexJ] != nullptr);
	}

	void CollisionService::AddCollider(ICollider* collider)
	{
		colliderList.push_back(collider);
	}

	void CollisionService::RemoveCollider(ICollider* collider)
	{
		colliderList.erase(std::remove(colliderList.begin(), colliderList.end(), collider), colliderList.end());
	}
}