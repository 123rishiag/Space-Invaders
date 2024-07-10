#include "../../Header/Bullet/BulletService.h"
#include "../../Header/Bullet/BulletController.h"
#include "../../Header/Bullet/BulletConfig.h"
#include "../../Header/Bullet/Controllers/FrostBulletController.h"
#include "../../Header/Bullet/Controllers/LaserBulletController.h"
#include "../../Header/Bullet/Controllers/TorpedoController.h"

namespace Bullet
{
	using namespace Controller;
	using namespace Projectile;

	BulletService::BulletService() { }

	BulletService::~BulletService() { Destroy(); }

	void BulletService::Initialize() { }

	void BulletService::Update()
	{
		for (int i = 0; i < bulletList.size(); i++) bulletList[i]->Update();
	}

	void BulletService::Render()
	{
		for (int i = 0; i < bulletList.size(); i++) bulletList[i]->Render();
	}

	BulletController* BulletService::CreateBullet(BulletType bulletType, Entity::EntityType ownerType)
	{
		switch (bulletType)
		{
		case::Bullet::BulletType::LASER_BULLET:
			return new LaserBulletController(Bullet::BulletType::LASER_BULLET, ownerType);

		case::Bullet::BulletType::FROST_BULLET:
			return new FrostBulletController(Bullet::BulletType::FROST_BULLET, ownerType);

		case::Bullet::BulletType::TORPEDO:
			return new TorpedoController(Bullet::BulletType::TORPEDO, ownerType);
		}
	}

	void BulletService::Destroy()
	{
		for (int i = 0; i < bulletList.size(); i++) 
		{
			delete (bulletList[i]);
		}
	}

	BulletController* BulletService::SpawnBullet(BulletType bulletType, sf::Vector2f position, MovementDirection direction, Entity::EntityType ownerType)
	{
		BulletController* bulletController = CreateBullet(bulletType, ownerType);

		bulletController->Initialize(position, direction);
		bulletList.push_back(bulletController);
		return bulletController;
	}

	void BulletService::DestroyBullet(BulletController* bulletController)
	{
		bulletList.erase(std::remove(bulletList.begin(), bulletList.end(), bulletController), bulletList.end());
		delete(bulletController);
	}
}