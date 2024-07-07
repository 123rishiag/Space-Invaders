#include "../../Header/Player/PlayerView.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Player/PlayerController.h"
#include "../../Header/Global/Config.h"

namespace Player {
	using namespace Global;
	PlayerView::PlayerView() { }

	PlayerView::~PlayerView() { }

	void PlayerView::Initialize(PlayerController* controller)
	{
		playerController = controller; //to later use it for setting position
		gameWindow = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();
		InitializePlayerSprite();
	}

	void PlayerView::InitializePlayerSprite()
	{
		if (playerTexture.loadFromFile(Config::playerTexturePath))
		{
			playerSprite.setTexture(playerTexture);
			ScalePlayerSprite();
		}
	}

	void PlayerView::ScalePlayerSprite()
	{
		// setScale is an inbuilt method of the sprite class that takes two floats to scale the sprite. it scales the sprite to our desired height
		playerSprite.setScale(
			//Here we find the factor to scale our sprites with. Ignore the static_cast for now, we will discuss it later.
			static_cast<float>(playerSpriteWidth) / playerSprite.getTexture()->getSize().x,
			static_cast<float>(playerSpriteHeight) / playerSprite.getTexture()->getSize().y
		);
	}

	void PlayerView::Update()
	{
		//set the updated position before we render
		playerSprite.setPosition(playerController->GetPlayerPosition());
	}

	void PlayerView::Render()
	{
		gameWindow->draw(playerSprite);
	}
}
