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
		std::vector<EnemyController*> flaggedEnemyList;
		float spawnTimer;

		void UpdateSpawnTimer();
		void ProcessEnemySpawn();
		EnemyType GetRandomEnemyType() const;
		EnemyController* CreateEnemy(EnemyType enemyType) const;
		void DestroyFlaggedEnemies();
		void Destroy(bool increaseScore); // function to delete enemy

	public:
		EnemyService();
		virtual ~EnemyService();

		void Initialize();
		void Update();
		void Render();

		void Reset(bool increaseScore);

		EnemyController* SpawnEnemy();
		void DestroyEnemy(EnemyController* enemyController);
	};
}