#include "../../Header/Enemy/EnemyService.h"
#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Enemy
{
	using namespace Global;


	EnemyService::EnemyService() { enemy = nullptr; }

	EnemyService::~EnemyService() { Destroy(); }

	void EnemyService::Initialize()
	{
		//Spawn Enemy
		SpawnEnemy();
	}

	void EnemyService::Update()
	{
		enemy->Update();
	}

	void EnemyService::Render()
	{
		enemy->Render();
	}

	EnemyController* EnemyService::SpawnEnemy()
	{
		//creates and intis an enemy controller
		enemy = new EnemyController();
		enemy->Initialize();

		return enemy;
	}

	void EnemyService::Destroy()
	{
		//deallocate memory 
		delete(enemy);
	}
}