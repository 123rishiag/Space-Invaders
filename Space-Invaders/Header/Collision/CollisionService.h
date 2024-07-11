#pragma once
#include <vector>

namespace Collision
{
	class ICollider;

	class CollisionService
	{
	private:
		std::vector<ICollider*> colliderList;

		void ProcessCollision();
		void DoCollision(int indexI, int indexJ);
		bool HasCollisionOccurred(int indexI, int indexJ);
		bool AreActiveColliders(int indexI, int indexJ);

	public:
		CollisionService();
		~CollisionService();

		void Initialize();
		void Update();

		void AddCollider(ICollider* collider);
		void RemoveCollider(ICollider* collider);
	};
}