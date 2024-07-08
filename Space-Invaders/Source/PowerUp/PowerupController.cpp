#include "../../Header/Powerup/PowerupController.h"
#include "../../Header/Powerup/PowerupView.h"
#include "../../Header/Powerup/PowerupModel.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Powerup
{
	using namespace Global;

	PowerupController::PowerupController(PowerupType type)
	{
		powerupView = new PowerupView();
		powerupModel = new PowerupModel(type);
	}

	PowerupController::~PowerupController()
	{
		delete (powerupView);
		delete (powerupModel);
	}

	void PowerupController::Initialize(sf::Vector2f position)
	{
		powerupModel->Initialize(position);
		powerupView->Initialize(this);
	}

	void PowerupController::Update()
	{
		UpdatePowerupPosition();
		powerupView->Update();
	}

	void PowerupController::Render()
	{
		powerupView->Render();
	}

	void PowerupController::OnCollected()
	{
	}

	void PowerupController::UpdatePowerupPosition()
	{
		sf::Vector2f currentPosition = powerupModel->GetPowerupPosition();
		currentPosition.y += powerupModel->GetMovementSpeed() * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

		powerupModel->SetPowerupPosition(currentPosition);
	}

	void PowerupController::HandleOutOfBounds()
	{
		sf::Vector2f powerupPosition = GetCollectiblePosition();
		sf::Vector2u windowSize = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow()->getSize();

		if (powerupPosition.x < 0 || powerupPosition.x > windowSize.x ||
			powerupPosition.y < 0 || powerupPosition.y > windowSize.y)
		{
			ServiceLocator::GetInstance()->GetPowerupService()->DestroyPowerup(this);
		}
	}

	sf::Vector2f PowerupController::GetCollectiblePosition()
	{
		return powerupModel->GetPowerupPosition();
	}

	PowerupType PowerupController::GetPowerupType()
	{
		return powerupModel->GetPowerupType();
	}
}