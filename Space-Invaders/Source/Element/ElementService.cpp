#include "../../Header/Element/ElementService.h"
#include "../../Header/Collision/ICollider.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Element
{
	using namespace Global;
	using namespace Collision;

	ElementService::ElementService() { }

	ElementService::~ElementService() { Destroy(); }

	void ElementService::Initialize() {	SpawnBunkers();	}

	void ElementService::Update()
	{
		for (Bunker::BunkerController* bunker : bunkerList)
			bunker->Update();

		DestroyFlaggedBunkers();
	}

	void ElementService::Render()
	{
		for (Bunker::BunkerController* bunker : bunkerList)
			bunker->Render();
	}

	void ElementService::SpawnBunkers()
	{
		for (int i = 0; i < bunkerDataList.size(); i++)
		{
			Bunker::BunkerController* bunkerController = new Bunker::BunkerController();

			bunkerController->Initialize(bunkerDataList[i]);
			bunkerList.push_back(bunkerController);

			ServiceLocator::GetInstance()->GetCollisionService()->AddCollider(dynamic_cast<ICollider*>(bunkerController));
		}
	}

	void ElementService::DestroyBunker(Bunker::BunkerController* bunkerController)
	{
		flaggedBunkerList.push_back(bunkerController);
		bunkerList.erase(std::remove(bunkerList.begin(), bunkerList.end(), bunkerController), bunkerList.end());
	}

	void ElementService::DestroyFlaggedBunkers()
	{
		for (int i = 0; i < flaggedBunkerList.size(); i++)
		{
			ServiceLocator::GetInstance()->GetCollisionService()->RemoveCollider(dynamic_cast<ICollider*>(flaggedBunkerList[i]));
			delete (flaggedBunkerList[i]);
		}
		flaggedBunkerList.clear();
	}

	void ElementService::Reset()
	{
		Destroy();
		SpawnBunkers();
	}

	void ElementService::Destroy()
	{
		for (int i = 0; i < bunkerList.size(); i++)
		{
			ServiceLocator::GetInstance()->GetCollisionService()->RemoveCollider(dynamic_cast<ICollider*>(bunkerList[i]));
			delete(bunkerList[i]);
		}
		bunkerList.clear();
	}
}