#include "../../Header/Gameplay/GameplayView.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Graphic/GraphicService.h"


namespace Gameplay
{
	using namespace Global;
	using namespace Graphic;

	GameplayView::GameplayView() { }

	GameplayView::~GameplayView() { }

	void GameplayView::Initialize() 
	{ 
		gameWindow = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();
		InitializeBackgroundSprite();
	}

	void GameplayView::Update() { }

	void GameplayView::Render() 
	{ 
		gameWindow->draw(backgroundSprite);
	}

	void GameplayView::InitializeBackgroundSprite()
	{
		if (backgroundTexture.loadFromFile(backgroundTexturePath))
		{
			backgroundSprite.setTexture(backgroundTexture);
			ScaleBackgroundSprite();
		}
	}

	void GameplayView::ScaleBackgroundSprite()
	{
		backgroundSprite.setScale(
			static_cast<float>(gameWindow->getSize().x) / backgroundSprite.getTexture()->getSize().x,
			static_cast<float>(gameWindow->getSize().y) / backgroundSprite.getTexture()->getSize().y
		);
	}
}