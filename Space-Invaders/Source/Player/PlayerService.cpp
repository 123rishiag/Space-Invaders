#include "../../Header/Player/PlayerService.h"
#include "../../Header/Player/PlayerController.h"

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
}

void PlayerService::Update()
{
	playerController->Update();
}

void PlayerService::Render()
{
	playerController->Render();
}