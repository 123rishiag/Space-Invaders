#include "../../Header/Enemy/EnemyView.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Graphic/GraphicService.h"
#include "../../Header/Enemy/EnemyController.h"

namespace Enemy
{
	using namespace Global;
	using namespace Graphic;

	EnemyView::EnemyView() { }

	EnemyView::~EnemyView() { }

	void EnemyView::Initialize(EnemyController* controller)
	{
		enemyController = controller;
		gameWindow = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();
		InitializeEnemySprite();
	}

	void EnemyView::InitializeEnemySprite()
	{
		if (enemyTexture.loadFromFile(enemyTexturePath)) //check if the texture loaded
		{
			enemySprite.setTexture(enemyTexture); //set the sprite
			ScaleEnemySprite(); // call the method to scale the sprite
		}
	}

	void EnemyView::ScaleEnemySprite()
	{
		// method to scale the Sprite according to our set dimensions. Don't worry about the static_cast, that will be discussed later.
		enemySprite.setScale(
			static_cast<float>(enemySpriteWidth) / enemySprite.getTexture()->getSize().x,
			static_cast<float>(enemySpriteHeight) / enemySprite.getTexture()->getSize().y
		);
	}

	void EnemyView::Update()
	{
		enemySprite.setPosition(enemyController->GetEnemyPosition());
	}

	void EnemyView::Render()
	{
		gameWindow->draw(enemySprite);
	}
}