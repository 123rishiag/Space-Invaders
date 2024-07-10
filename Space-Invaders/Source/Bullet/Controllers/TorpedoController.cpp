#include "../../Header/Bullet/Controllers/TorpedoController.h"
#include "../../Header/Bullet/BulletModel.h"

namespace Bullet
{
	namespace Controller
	{
		TorpedoController::TorpedoController(BulletType type, Entity::EntityType ownerType) : BulletController(type, ownerType) { }

		TorpedoController::~TorpedoController() { }

		void TorpedoController::Initialize(sf::Vector2f position, MovementDirection direction)
		{
			BulletController::Initialize(position, direction);
			bulletModel->SetMovementSpeed(torpedoMovementSpeed);
		}
	}
}