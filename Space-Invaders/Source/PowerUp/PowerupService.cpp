#include "../../Header/Powerup/PowerupService.h"
#include "../../Header/Powerup/PowerupController.h"
#include "../../Header/Powerup/PowerupConfig.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Collision/ICollider.h"
#include "../../Header/Powerup/Controllers/OutscalBombController.h"
#include "../../Header/Powerup/Controllers/RapidFireController.h"
#include "../../Header/Powerup/Controllers/ShieldController.h"
#include "../../Header/Powerup/Controllers/TripleLaserController.h"

namespace Powerup
{
	using namespace Global;
	using namespace Controller;
	using namespace Collectible;
	using namespace Collision;

	PowerupService::PowerupService() { }

	PowerupService::~PowerupService() { Destroy(); }

	void PowerupService::Initialize() { }

	void PowerupService::Update()
	{
		for (Collectible::ICollectible* powerup : powerupList)
			powerup->Update();

		DestroyFlaggedPowerup();
	}

	void PowerupService::Render()
	{
		for (Collectible::ICollectible* powerup : powerupList)
			powerup->Render();
	}

	PowerupController* PowerupService::CreatePowerup(PowerupType powerupType) //creates and returns a pointer to the created powerup
	{
		switch (powerupType)
		{
		case::Powerup::PowerupType::SHIELD:
			return new ShieldController(Powerup::PowerupType::SHIELD);

		case::Powerup::PowerupType::RAPID_FIRE:
			return new RapidFireController(Powerup::PowerupType::RAPID_FIRE);

		case::Powerup::PowerupType::TRIPLE_LASER:
			return new TripleLaserController(Powerup::PowerupType::TRIPLE_LASER);

		case::Powerup::PowerupType::OUTSCAL_BOMB:
			return new OutscalBombController(Powerup::PowerupType::OUTSCAL_BOMB);
		}
	}

	PowerupController* PowerupService::SpawnPowerup(PowerupType powerupType, sf::Vector2f position) //initialize a powerup
	{
		PowerupController* powerupController = CreatePowerup(powerupType);
		powerupController->Initialize(position);

		ServiceLocator::GetInstance()->GetCollisionService()->AddCollider(dynamic_cast<ICollider*>(powerupController));

		powerupList.push_back(powerupController);
		return powerupController;
	}

	void PowerupService::DestroyFlaggedPowerup()
	{
		for (Collectible::ICollectible* powerup : flaggedPowerupList)
			delete (powerup);

		flaggedPowerupList.clear();
	}

	void PowerupService::DestroyPowerup(PowerupController* powerupController) //destroy specific powerup
	{
		ServiceLocator::GetInstance()->GetCollisionService()->RemoveCollider(dynamic_cast<ICollider*>(powerupController));

		flaggedPowerupList.push_back(powerupController);
		powerupList.erase(std::remove(powerupList.begin(), powerupList.end(), powerupController), powerupList.end());
	}

	void PowerupService::Destroy()
	{
		for (Collectible::ICollectible* powerup : powerupList)
			delete (powerup);
	}
}