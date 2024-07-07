#include "../../Header/Element/ElementService.h"
#include "../../Header/Element/Bunker/BunkerController.h"

namespace Element {
	ElementService::ElementService()
	{
		bunkerController = new BunkerController();
	}

	ElementService::~ElementService()
	{
		delete (bunkerController);
	}

	void ElementService::Initialize()
	{
		bunkerController->Initialize();
	}

	void ElementService::Update()
	{
		bunkerController->Update();
	}

	void ElementService::Render()
	{
		bunkerController->Render();
	}
}