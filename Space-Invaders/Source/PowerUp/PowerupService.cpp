#include "../../Header/Powerup/PowerupService.h"
#include "../../Header/Powerup/PowerupController.h"
#include "../../Header/Powerup/PowerupConfig.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Powerup/Controllers/OutscalBombController.h"
#include "../../Header/Powerup/Controllers/RapidFireController.h"
#include "../../Header/Powerup/Controllers/ShieldController.h"
#include "../../Header/Powerup/Controllers/TripleLaserController.h"

namespace Powerup
{
	using namespace Global;
	using namespace Controller;
	using namespace Collectible;

	PowerupService::PowerupService() { }

	PowerupService::~PowerupService() { Destroy(); }

	void PowerupService::Initialize() { }

	void PowerupService::Update()
	{
		for (int i = 0; i < powerupList.size(); i++) powerupList[i]->Update(); //loop and update
	}

	void PowerupService::Render()
	{
		for (int i = 0; i < powerupList.size(); i++) powerupList[i]->Render(); //loop and render
	}

	PowerupController* PowerupService::CreatePowerup(PowerupType powerupType) //creates and returns a pointer to the created powerup
	{
		switch (powerupType)
		{
		case::Powerup::PowerupType::SHIELD:
			return new ShieldController(Powerup::PowerupType::SHIELD);

		case::Powerup::PowerupType::RAPID_FIRE:
			return new RapidFireController(Powerup::PowerupType::RAPID_FIRE);

		case::Powerup::PowerupType::TRIPPLE_LASER:
			return new TripleLaserController(Powerup::PowerupType::TRIPPLE_LASER);

		case::Powerup::PowerupType::OUTSCAL_BOMB:
			return new OutscalBombController(Powerup::PowerupType::OUTSCAL_BOMB);
		}
	}

	PowerupController* PowerupService::SpawnPowerup(PowerupType powerupType, sf::Vector2f position) //initialize a powerup
	{
		PowerupController* powerup_controller = CreatePowerup(powerupType);

		powerup_controller->Initialize(position);
		powerupList.push_back(powerup_controller);
		return powerup_controller;
	}

	void PowerupService::DestroyPowerup(PowerupController* powerupController) //destroy specific powerup
	{
		powerupList.erase(std::remove(powerupList.begin(), powerupList.end(), powerupController), powerupList.end());
		delete(powerupController);
	}

	void PowerupService::Destroy()
	{
		for (int i = 0; i < powerupList.size(); i++) delete (powerupList[i]);
	}
}