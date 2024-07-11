#include "../../Header/Collision/ICollider.h"

namespace Collision
{
	ICollider::ICollider() { collisionState = CollisionState::ENABLED; }

	ICollider::~ICollider() { }

	void ICollider::EnableCollision() { collisionState = CollisionState::ENABLED; }

	void ICollider::DisableCollision() { collisionState = CollisionState::DISABLED; }

	CollisionState ICollider::GetCollisionState() { return collisionState; }
}