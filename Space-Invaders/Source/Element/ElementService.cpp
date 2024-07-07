#include "../../Header/Element/ElementService.h"

namespace Element
{
	ElementService::ElementService() { }

	ElementService::~ElementService() { Destroy(); }

	void ElementService::Initialize()
	{
		for (int i = 0; i < bunkerDataList.size(); i++)
		{
			Bunker::BunkerController* bunkerController = new Bunker::BunkerController();

			bunkerController->Initialize(bunkerDataList[i]);
			bunkerList.push_back(bunkerController);
		}
	}

	void ElementService::Update()
	{
		for (int i = 0; i < bunkerList.size(); i++) bunkerList[i]->Update();
	}

	void ElementService::Render()
	{
		for (int i = 0; i < bunkerList.size(); i++) bunkerList[i]->Render();
	}

	void ElementService::Destroy()
	{
		for (int i = 0; i < bunkerList.size(); i++) delete(bunkerList[i]);
	}
}