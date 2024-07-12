#include "../../Header/Player/PlayerService.h"
#include "../../Header/Player/PlayerController.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Collision/ICollider.h"

namespace Player {

	using namespace Global;
	using namespace Collision;

	PlayerService::PlayerService()
	{
		playerController = new PlayerController();
	}

	PlayerService::~PlayerService()
	{
		delete (playerController);
	}

	void PlayerService::Initialize()
	{
		playerController->Initialize();
		ServiceLocator::GetInstance()->GetCollisionService()->AddCollider(dynamic_cast<ICollider*>(playerController));
	}

	void PlayerService::Update()
	{
		playerController->Update();
	}

	void PlayerService::Render()
	{
		playerController->Render();
	}

	void PlayerService::EnableShield()
	{
		playerController->EnableShield();
	}

	void PlayerService::EnableRapidFire()
	{
		playerController->EnableRapidFire();
	}

	void PlayerService::EnableTripleLaser()
	{
		playerController->EnableTripleLaser();
	}

	void PlayerService::IncreaseEnemiesKilled(int val)
	{
		playerController->IncreaseEnemiesKilled(val);
	}

	void PlayerService::Reset()
	{
		playerController->Reset();
	}
}