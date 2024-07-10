#include "../../Header/Enemy/EnemyService.h"
#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Enemy/Controllers/SubZeroController.h"
#include "../../Header/Enemy/Controllers/ThunderSnakeController.h"
#include "../../Header/Enemy/Controllers/UFOController.h"
#include "../../Header/Enemy/Controllers/ZapperController.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Time/TimeService.h"

namespace Enemy
{
	using namespace Global;
	using namespace Time;
	using namespace Controller;

	EnemyService::EnemyService() {
		std::srand(static_cast<unsigned>(std::time(nullptr)));
	}

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

	EnemyController* EnemyService::SpawnEnemy()
	{
		// The base class pointer will be pointing to a child class object
		EnemyController* enemyController = CreateEnemy(GetRandomEnemyType(), Entity::EntityType::ENEMY);

		enemyController->Initialize();
		enemyList.push_back(enemyController);

		return enemyController;
	}

	// Function to destroy an enemy controller object from the enemy_list vector.
	void EnemyService::DestroyEnemy(EnemyController* enemyController)
	{
		// Erase the enemy_controller object from the enemy_list vector.
		// std::remove rearranges the elements in the vector so that all elements 
		// that are equal to enemy_controller are moved to the end of the vector,
		// then it returns an iterator pointing to the start of the removed elements.
		// The erase function then removes those elements from the vector.
		enemyList.erase(std::remove(enemyList.begin(), enemyList.end(), enemyController), enemyList.end());

		// Delete the enemy_controller object from memory to free up resources.
		delete(enemyController);
	}

	EnemyType EnemyService::GetRandomEnemyType() const
	{
		int randomType = std::rand() % 4;  //since we have 4 enemies now
		return static_cast<Enemy::EnemyType>(randomType); //cast int to EnemyType enum class
	}

	EnemyController* EnemyService::CreateEnemy(EnemyType enemyType, Entity::EntityType ownerType) const
	{
		switch (enemyType)
		{
		case::Enemy::EnemyType::SUBZERO:
			return new SubzeroController(Enemy::EnemyType::SUBZERO, ownerType);
		case::Enemy::EnemyType::THUNDER_SNAKE:
			return new ThunderSnakeController(Enemy::EnemyType::THUNDER_SNAKE, ownerType);
		case::Enemy::EnemyType::UFO:
			return new UFOController(Enemy::EnemyType::UFO, ownerType);
		case::Enemy::EnemyType::ZAPPER:
			return new ZapperController(Enemy::EnemyType::ZAPPER, ownerType);
		}
	}

	void EnemyService::Destroy()
	{
		for (int i = 0; i < enemyList.size(); i++)
		{
			delete(enemyList[i]);
		}
	}
}