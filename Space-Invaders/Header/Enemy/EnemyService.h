#pragma once
#include <vector>

namespace Enemy
{
	class EnemyController;
	class EnemyService
	{
	private:
		const float spawnInterval = 3.f;
		std::vector<EnemyController*> enemyList;
		float spawnTimer;

		void UpdateSpawnTimer();
		void ProcessEnemySpawn();
		void Destroy(); // function to delete enemy

	public:
		EnemyService();
		virtual ~EnemyService();

		void Initialize();
		void Update();
		void Render();

		void SpawnEnemy(); 		// Function to spawn enemy
	};
}