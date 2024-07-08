#include "../../Header/Powerup/PowerupView.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Powerup/PowerupController.h"
#include "../../Header/Powerup/PowerupConfig.h"

namespace Powerup
{
	using namespace Global;

	PowerupView::PowerupView() {  }

	PowerupView::~PowerupView() { }

	void PowerupView::Initialize(PowerupController* controller)
	{
		powerupController = controller;
		gameWindow = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();
		InitializeImage(powerupController->GetPowerupType());
	}


	void PowerupView::InitializeImage(PowerupType type)
	{
		switch (type)
		{
		case::Powerup::PowerupType::TRIPPLE_LASER:
			if (powerupTexture.loadFromFile(Config::trippleLaserTexturePath))
			{
				powerupSprite.setTexture(powerupTexture);
				ScaleImage();
			}
			break;
		case::Powerup::PowerupType::SHIELD:
			if (powerupTexture.loadFromFile(Config::shieldTexturePath))
			{
				powerupSprite.setTexture(powerupTexture);
				ScaleImage();
			}
			break;
		case::Powerup::PowerupType::RAPID_FIRE:
			if (powerupTexture.loadFromFile(Config::rapidFireTexturePath))
			{
				powerupSprite.setTexture(powerupTexture);
				ScaleImage();
			}
			break;
		case::Powerup::PowerupType::OUTSCAL_BOMB:
			if (powerupTexture.loadFromFile(Config::outscalBombTexturePath))
			{
				powerupSprite.setTexture(powerupTexture);
				ScaleImage();
			}
			break;
		}
	}

	void PowerupView::ScaleImage()
	{
		powerupSprite.setScale(
			static_cast<float>(powerupSpriteWidth) / powerupSprite.getTexture()->getSize().x,
			static_cast<float>(powerupSpriteHeight) / powerupSprite.getTexture()->getSize().y
		);
	}

	void PowerupView::Update()
	{
		powerupSprite.setPosition(powerupController->GetCollectiblePosition());
	}

	void PowerupView::Render()
	{
		gameWindow->draw(powerupSprite);
	}
}
