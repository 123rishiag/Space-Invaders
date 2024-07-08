#include "../../Header/Bullet/BulletView.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Bullet/BulletController.h"
#include "../../Header/Bullet/BulletConfig.h"

namespace Bullet
{
	using namespace Global;
	using namespace UI::UIElement;

	BulletView::BulletView() { CreateUIElements(); }

	BulletView::~BulletView() { Destroy(); }

	void BulletView::Initialize(BulletController* controller)
	{
		bulletController = controller;
		InitializeImage();
	}

	void BulletView::CreateUIElements()
	{
		bulletImage = new ImageView();
	}


	void BulletView::InitializeImage()
	{
		bulletImage->Initialize(GetBulletTexturePath(), bulletSpriteWidth, bulletSpriteHeight, bulletController->GetProjectilePosition());
	}

	void BulletView::Update()
	{
		bulletImage->SetPosition(bulletController->GetProjectilePosition());
		bulletImage->Update();
	}

	void BulletView::Render()
	{
		bulletImage->Render();
	}

	sf::String BulletView::GetBulletTexturePath()
	{
		switch (bulletController->GetBulletType())
		{
		case::Bullet::BulletType::LASER_BULLET:
			return Config::laserBulletTexturePath;

		case::Bullet::BulletType::FROST_BULLET:
			return Config::frostBeamTexturePath;

		case::Bullet::BulletType::TORPEDO:
			return Config::torpedoeTexturePath;
		}
	}

	void BulletView::Destroy()
	{
		delete(bulletImage);
	}
}