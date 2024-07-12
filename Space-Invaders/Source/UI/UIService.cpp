#include "../../Header/UI/UIService.h"
#include "../../Header/Main/GameService.h"
#include "../../Header/UI/UIElement/TextView.h" 
#include "../../Header/UI/MainMenu/MainMenuUIController.h"
#include "../../Header/UI/GameplayUI/GameplayUIController.h"

namespace UI
{
	using namespace Main;
	using namespace UIElement;
	using namespace Interface;
	using namespace MainMenu;
	using namespace GameplayUI;

	UIService::UIService()
	{
		mainMenuController = nullptr;
		gameplayUIController = nullptr;
		CreateControllers();
	}

	void UIService::CreateControllers()
	{
		mainMenuController = new MainMenu::MainMenuUIController();
		gameplayUIController = new GameplayUI::GameplayUIController();
	}

	UIService::~UIService()
	{
		Destroy();
	}

	void UIService::Initialize()
	{
		TextView::InitializeTextView();
		InitializeControllers();
	}

	void UIService::Update()
	{
		IUIController* uiController = GetCurrentUIController();
		if (uiController) uiController->Update();
	}

	void UIService::Render()
	{
		IUIController* uiController = GetCurrentUIController();
		if (uiController) uiController->Render();
	}

	void UIService::Show()
	{
		IUIController* uiController = GetCurrentUIController();
		if (uiController) uiController->Show();
	}

	void UIService::InitializeControllers()
	{
		mainMenuController->Initialize();
		gameplayUIController->Initialize();
	}

	IUIController* UIService::GetCurrentUIController()
	{
		switch (GameService::GetGameState())
		{
		case GameState::MAIN_MENU:
			return mainMenuController;
		case GameState::GAMEPLAY:
			return gameplayUIController;
		default:
			return nullptr;
		}
	}

	void UIService::Destroy()
	{
		delete(mainMenuController);
		delete(gameplayUIController);
	}
}
