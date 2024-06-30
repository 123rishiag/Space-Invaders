#include "../../Header/Gameplay/GameplayService.h"
#include "../../Header/Gameplay/GameplayController.h"

namespace Gameplay
{
	GameplayService::GameplayService() { gameplayController = new GameplayController(); }

	GameplayService::~GameplayService() { delete (gameplayController); }

	void GameplayService::Initialize() { gameplayController->Initialize(); }

	void GameplayService::Update() { gameplayController->Update(); }

	void GameplayService::Render() { gameplayController->Render(); }
}