#include "../Header/GameService.h"
#include "../Header/GraphicService.h"

void GameService::Initialize()
{
	serviceLocator->Initialize();
	InitializeVariables();
}

void GameService::InitializeVariables()
{
	gameWindow = serviceLocator->GetGraphicService()->GetGameWindow(); //set game window (it was null before this)
}

void GameService::Destroy()
{
	delete(gameWindow);
	//delete(serviceLocator);
}

GameService::GameService()
{
	serviceLocator = nullptr; // Set service locator to null
	gameWindow = nullptr; // Set game window to null
}

GameService::~GameService()
{
	Destroy(); // Clean up and release resources
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

bool GameService::IsRunning()
{
	// Returns true if the game window is open, indicating the game is still running
	return serviceLocator->GetGraphicService()->IsGameWindowOpen();
}

sf::RenderWindow* GameService::GetGameWindow()
{
	return gameWindow;
}