#include "../../Header/Enemy/EnemyService.h"
#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Time/TimeService.h"

namespace Enemy
{
	using namespace Global;
	using namespace Time;

	EnemyService::EnemyService() {}

	EnemyService::~EnemyService() { Destroy(); }

	void EnemyService::Initialize()
	{
		spawnTimer = spawnInterval; // for the first spawn
	}

	void EnemyService::Update()
	{
		UpdateSpawnTimer();
		ProcessEnemySpawn();
		for (int i = 0; i < enemyList.size(); i++) 
		{ 
			enemyList[i]->Update(); 
		}
	}

	void EnemyService::Render()
	{
		for (int i = 0; i < enemyList.size(); i++)
		{
			enemyList[i]->Render();
		}
	}

	void EnemyService::UpdateSpawnTimer()
	{
		spawnTimer += ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime(); // increase timer
	}

	void EnemyService::ProcessEnemySpawn()
	{
		if (spawnTimer >= spawnInterval)
		{
			SpawnEnemy(); //spawn 
			spawnTimer = 0.0f; // reset
		}
	}

	void EnemyService::SpawnEnemy()
	{
		EnemyController* enemyController = new EnemyController();
		enemyController->Initialize();

		enemyList.push_back(enemyController);
	}

	void EnemyService::Destroy()
	{
		for (int i = 0; i < enemyList.size(); i++)
		{
			delete(enemyList[i]);
		}
	}
}