#pragma once

namespace Enemy
{
	class EnemyController;
	class EnemyService
	{
	private:
		void Destroy(); // function to delete enemy
		EnemyController* enemy; 	// enemy controller ptr

	public:
		EnemyService();
		virtual ~EnemyService();

		void Initialize();
		void Update();
		void Render();

		EnemyController* SpawnEnemy(); 		// Function to spawn enemy
	};
}