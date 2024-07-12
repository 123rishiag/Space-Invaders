#include "../../Header/Element/Bunker/BunkerView.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Element/Bunker/BunkerController.h"

namespace Element
{
	namespace Bunker
	{
		using namespace Global; 
		using namespace UI::UIElement;

		BunkerView::BunkerView() { CreateUIElements(); }

		BunkerView::~BunkerView() { Destroy(); }

		void BunkerView::Initialize(BunkerController* controller)
		{
			bunkerController = controller;
			InitializeImage();
		}

		void BunkerView::CreateUIElements()
		{
			bunkerImage = new ImageView();
		}


		void BunkerView::InitializeImage()
		{
			bunkerImage->Initialize(GetBunkerTexturePath(), bunkerSpriteWidth, bunkerSpriteHeight, bunkerController->GetBunkerPosition());
		}

		void BunkerView::Update()
		{
			bunkerImage->SetPosition(bunkerController->GetBunkerPosition());
			bunkerImage->Update();
		}

		void BunkerView::Render()
		{
			bunkerImage->Render();
		}

		sf::String BunkerView::GetBunkerTexturePath()
		{
			return Config::bunkerTexturePath;
		}

		const sf::Sprite& BunkerView::GetBunkerSprite() const
		{
			return bunkerImage->GetSprite();
		}

		void BunkerView::Destroy()
		{
			delete(bunkerImage);
		}
	}
}
