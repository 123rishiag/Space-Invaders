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
			return BulletConfig::laserBulletTexturePath;

		case::Bullet::BulletType::FROST_BULLET:
			return BulletConfig::frostBeamTexturePath;

		case::Bullet::BulletType::TORPEDO:
			return BulletConfig::torpedoeTexturePath;
		}
	}

	const sf::Sprite& BulletView::GetBulletSprite() const
	{
		return bulletImage->GetSprite();
	}

	void BulletView::Destroy()
	{
		delete(bulletImage);
	}
}