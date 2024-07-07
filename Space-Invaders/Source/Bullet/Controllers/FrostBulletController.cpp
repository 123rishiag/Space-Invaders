#include "../../Header/Bullet/Controllers/FrostBulletController.h"
#include "../../Header/Bullet/BulletModel.h"

namespace Bullet
{
	namespace Controller
	{
		FrostBulletController::FrostBulletController(BulletType type) : BulletController(type) { }

		FrostBulletController::~FrostBulletController() { }

		void FrostBulletController::Initialize(sf::Vector2f position, MovementDirection direction)
		{
			BulletController::Initialize(position, direction);
			bulletModel->SetMovementSpeed(frostBulletMovementSpeed);
		}
	}
}