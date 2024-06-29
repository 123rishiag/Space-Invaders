#include "../../Header/Main/GameService.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Main {
	using namespace Global;
	GameState GameService::currentState = GameState::BOOT;

	GameService::GameService()
	{
		serviceLocator = nullptr; // Set service locator to null
		gameWindow = nullptr; // Set game window to null
	}

	GameService::~GameService()
	{
		Destroy(); // Clean up and release resources
	}

	void GameService::Initialize()
	{
		serviceLocator->Initialize();
		InitializeVariables();
		ShowMainMenu();
	}

	void GameService::InitializeVariables()
	{
		gameWindow = serviceLocator->GetGraphicService()->GetGameWindow(); //set game window (it was null before this)
	}

	void GameService::Destroy()
	{
		delete(gameWindow);
	}

	void GameService::Ignite()
	{
		serviceLocator = ServiceLocator::GetInstance(); // Get ServiceLocator
		Initialize(); // Initialize services.
	}

	void GameService::Update()
	{
		serviceLocator->Update(); // Call update on the service locator which then updates all its managed services
	}

	void GameService::Render()
	{
		// Clears the game window with the background color provided by the graphic service
		gameWindow->clear(serviceLocator->GetGraphicService()->GetWindowColor());
		serviceLocator->Render(); // Render the current frame using the service locator
		gameWindow->display(); // Display the rendered frame on the game window
	}

	void GameService::ShowMainMenu()
	{
		SetGameState(GameState::MAIN_MENU);
	}

	bool GameService::IsRunning() const
	{
		// Returns true if the game window is open, indicating the game is still running
		return serviceLocator->GetGraphicService()->IsGameWindowOpen();
	}

	sf::RenderWindow* GameService::GetGameWindow() const
	{
		return gameWindow;
	}

	void GameService::SetGameState(GameState newState) { currentState = newState; }

	GameState GameService::GetGameState() { return currentState; }
}