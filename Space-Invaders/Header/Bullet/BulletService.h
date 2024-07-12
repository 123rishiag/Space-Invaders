#pragma once
#include <vector>
#include "SFML/System/Vector2.hpp"
#include "../../Header/Projectile/IProjectile.h"
#include "../../Header/Entity/EntityConfig.h"

namespace Bullet
{
	class BulletController;
	enum class BulletType;
	enum class MovementDirection;

	class BulletService
	{
	private:
		std::vector<Projectile::IProjectile*> flaggedBulletList;
		std::vector<Projectile::IProjectile*> bulletList;

		BulletController* CreateBullet(BulletType bulletType, Entity::EntityType ownerType);

		bool IsValidBullet(int indexI, std::vector<Projectile::IProjectile*>& bulletList);
		void DestroyFlaggedBullets();

		void Destroy();

	public:
		BulletService();
		virtual ~BulletService();

		void Initialize();
		void Update();
		void Render();

		BulletController* SpawnBullet(BulletType bulletType, Entity::EntityType ownerType, 
			sf::Vector2f position, MovementDirection direction);
		void DestroyBullet(BulletController* bulletController);

		void Reset();
	};
}