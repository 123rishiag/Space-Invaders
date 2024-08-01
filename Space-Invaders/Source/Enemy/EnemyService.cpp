#include "../../Header/Enemy/EnemyService.h"
#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Enemy/Controllers/SubZeroController.h"
#include "../../Header/Enemy/Controllers/ThunderSnakeController.h"
#include "../../Header/Enemy/Controllers/UFOController.h"
#include "../../Header/Enemy/Controllers/ZapperController.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Time/TimeService.h"
#include "../../Header/Collision/ICollider.h"

namespace Enemy
{
	using namespace Global;
	using namespace Time;
	using namespace Controller;
	using namespace Collision;

	EnemyService::EnemyService() {
		std::srand(static_cast<unsigned>(std::time(nullptr)));
	}

	EnemyService::~EnemyService() { Destroy(true); }

	void EnemyService::Initialize()
	{
		spawnTimer = spawnInterval; // for the first spawn
	}

	void EnemyService::Update()
	{
		UpdateSpawnTimer();
		ProcessEnemySpawn();
		for (EnemyController* enemy : enemyList)
			enemy->Update();

		DestroyFlaggedEnemies();
	}

	void EnemyService::Render()
	{
		for (EnemyController* enemy : enemyList)
			enemy->Render();
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

	EnemyController* EnemyService::SpawnEnemy()
	{
		// The base class pointer will be pointing to a child class object
		EnemyController* enemyController = CreateEnemy(GetRandomEnemyType());
		enemyController->Initialize();

		ServiceLocator::GetInstance()->GetCollisionService()->AddCollider(dynamic_cast<ICollider*>(enemyController));

		enemyList.push_back(enemyController);
		return enemyController;
	}

	EnemyType EnemyService::GetRandomEnemyType() const
	{
		int randomValue = std::rand() % (static_cast<int>(Enemy::EnemyType::ZAPPER) + 1);
		return static_cast<Enemy::EnemyType>(randomValue); //cast int to EnemyType enum class
	}

	EnemyController* EnemyService::CreateEnemy(EnemyType enemyType) const
	{
		switch (enemyType)
		{
		case::Enemy::EnemyType::SUBZERO:
			return new SubzeroController(Enemy::EnemyType::SUBZERO);
		case::Enemy::EnemyType::THUNDER_SNAKE:
			return new ThunderSnakeController(Enemy::EnemyType::THUNDER_SNAKE);
		case::Enemy::EnemyType::UFO:
			return new UFOController(Enemy::EnemyType::UFO);
		case::Enemy::EnemyType::ZAPPER:
			return new ZapperController(Enemy::EnemyType::ZAPPER);
		}
	}

	void EnemyService::DestroyFlaggedEnemies()
	{
		for (int i = 0; i < flaggedEnemyList.size(); i++)
		{
			ServiceLocator::GetInstance()->GetCollisionService()->RemoveCollider(dynamic_cast<ICollider*>(flaggedEnemyList[i]));
			delete (flaggedEnemyList[i]);
		}
		flaggedEnemyList.clear();
	}

	// Function to destroy an enemy controller object from the enemy_list vector.
	void EnemyService::DestroyEnemy(EnemyController* enemyController)
	{
		dynamic_cast<ICollider*>(enemyController)->DisableCollision();
		flaggedEnemyList.push_back(enemyController);
		enemyList.erase(std::remove(enemyList.begin(), enemyList.end(), enemyController), enemyList.end());
	}

	void EnemyService::Destroy(bool increaseScore)
	{
		for (int i = 0; i < enemyList.size(); i++)
		{
			ServiceLocator::GetInstance()->GetCollisionService()->RemoveCollider(dynamic_cast<ICollider*>(enemyList[i]));
			enemyList[i]->Destroy();
			if (increaseScore == true) {
				ServiceLocator::GetInstance()->GetPlayerService()->IncreaseEnemiesKilled(1);
			}
		}
		enemyList.clear();
	}

	void EnemyService::Reset(bool increaseScore)
	{
		Destroy(increaseScore);
		spawnTimer = 0.0f;
	}
}