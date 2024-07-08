#pragma once
#include <vector>
#include "SFML/System/Vector2.hpp"
#include "../../Header/Collectible/ICollectible.h"

namespace Powerup
{

	class PowerupController;
	enum class PowerupType;

	class PowerupService
	{
	private:
		std::vector<Collectible::ICollectible*> powerupList;

		PowerupController* CreatePowerup(PowerupType powerupType);
		void Destroy();

	public:
		PowerupService();
		virtual ~PowerupService();

		void Initialize();
		void Update();
		void Render();


		PowerupController* SpawnPowerup(PowerupType powerupType, sf::Vector2f position);
		void DestroyPowerup(PowerupController* powerupController);
	};
}