#include "../../Header/Element/Bunker/BunkerView.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Element/Bunker/BunkerController.h"

namespace Element
{
	namespace Bunker
	{
		using namespace Global;

		BunkerView::BunkerView() { }

		BunkerView::~BunkerView() { }

		void BunkerView::Initialize(BunkerController* controller)
		{
			bunkerController = controller;
			gameWindow = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();
			InitializeBunkerSprite();
		}

		void BunkerView::InitializeBunkerSprite()
		{
			if (bunkerTexture.loadFromFile(bunkerTexturePath))
			{
				bunkerSprite.setTexture(bunkerTexture);
				ScaleBunkerSprite();
			}
		}

		void BunkerView::ScaleBunkerSprite()
		{
			bunkerSprite.setScale(
				static_cast<float>(bunkerSpriteWidth) / bunkerSprite.getTexture()->getSize().x,
				static_cast<float>(bunkerSpriteHeight) / bunkerSprite.getTexture()->getSize().y
			);
		}

		void BunkerView::Update()
		{
			bunkerSprite.setPosition(bunkerController->GetBunkerPosition());
		}

		void BunkerView::Render()
		{
			gameWindow->draw(bunkerSprite);
		}
	}
}
