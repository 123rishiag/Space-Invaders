#pragma once
#include <vector>

namespace Enemy
{
	enum class EnemyType;
	class EnemyController;
	class EnemyService
	{
	private:
		const float spawnInterval = 3.f;
		std::vector<EnemyController*> enemyList;
		float spawnTimer;

		void UpdateSpawnTimer();
		void ProcessEnemySpawn();
		EnemyType GetRandomEnemyType() const;
		EnemyController* CreateEnemy(EnemyType enemyType) const;
		void Destroy(); // function to delete enemy

	public:
		EnemyService();
		virtual ~EnemyService();

		void Initialize();
		void Update();
		void Render();

		EnemyController* SpawnEnemy();
		void DestroyEnemy(EnemyController* enemyController);
	};
}