#include "../../Header/Powerup/PowerupView.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Powerup/PowerupController.h"
#include "../../Header/Powerup/PowerupConfig.h"

namespace Powerup
{
	using namespace Global;
	using namespace UI::UIElement;

	PowerupView::PowerupView() { CreateUIElements(); }

	PowerupView::~PowerupView() { Destroy(); }

	void PowerupView::Initialize(PowerupController* controller)
	{
		powerupController = controller;
		InitializeImage();
	}

	void PowerupView::CreateUIElements()
	{
		powerupImage = new ImageView();
	}


	void PowerupView::InitializeImage()
	{
		powerupImage->Initialize(GetPowerupTexturePath(), powerupSpriteWidth, powerupSpriteHeight, powerupController->GetCollectiblePosition());
	}

	void PowerupView::Update()
	{
		powerupImage->SetPosition(powerupController->GetCollectiblePosition());
		powerupImage->Update();
	}

	void PowerupView::Render()
	{
		powerupImage->Render();
	}

	sf::String PowerupView::GetPowerupTexturePath()
	{
		switch (powerupController->GetPowerupType())
		{
		case::Powerup::PowerupType::SHIELD:
			return Config::shieldTexturePath;

		case::Powerup::PowerupType::TRIPLE_LASER:
			return Config::tripleLaserTexturePath;

		case::Powerup::PowerupType::RAPID_FIRE:
			return Config::rapidFireTexturePath;

		case::Powerup::PowerupType::OUTSCAL_BOMB:
			return Config::outscalBombTexturePath;
		}
	}

	void PowerupView::Destroy()
	{
		delete(powerupImage);
	}
}
