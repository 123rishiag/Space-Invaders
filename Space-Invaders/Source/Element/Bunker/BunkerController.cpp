#include "../../Header/Element/Bunker/BunkerController.h"
#include "../../Header/Element/Bunker/BunkerView.h"

namespace Element
{
	namespace Bunker 
	{
		BunkerController::BunkerController()
		{
			bunkerView = new BunkerView();
		}

		BunkerController::~BunkerController()
		{
			delete (bunkerView);
		}

		void BunkerController::Initialize(BunkerData data)
		{
			bunkerData = data;
			bunkerView->Initialize(this); // we will discuss this soon
		}

		void BunkerController::Update()
		{
			bunkerView->Update();
		}

		void BunkerController::Render()
		{
			bunkerView->Render();
		}

		sf::Vector2f BunkerController::GetBunkerPosition() const
		{
			return bunkerData.position;
		}
	}
}