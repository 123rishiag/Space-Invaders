#include "../../Header/Element/Bunker/BunkerController.h"
#include "../../Header/Element/Bunker/BunkerView.h"
#include "../../Header/Element/Bunker/BunkerModel.h"

namespace Element
{
	BunkerController::BunkerController()
	{
		bunkerView = new BunkerView();
		bunkerModel = new BunkerModel();
	}

	BunkerController::~BunkerController()
	{
		delete (bunkerView);
		delete (bunkerModel);
	}

	void BunkerController::Initialize()
	{
		bunkerModel->Initialize();
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

	sf::Vector2f BunkerController::GetBunkerPosition()
	{
		return bunkerModel->GetBunkerPosition();
	}
}