#include "../../Header/UI/UIService.h"
#include "../../Header/Main/GameService.h"
#include "../../header/UI/UIElement/TextView.h" 
#include "../../Header/UI/MainMenu/MainMenuUIController.h"

namespace UI
{
	using namespace Main;
	using namespace UIElement;
	using namespace Interface;
	using namespace MainMenu;

	UIService::UIService()
	{
		mainMenuController = nullptr;
		CreateControllers();
	}

	void UIService::CreateControllers()
	{
		mainMenuController = new MainMenu::MainMenuUIController();
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

	void UIService::ShowScreen()
	{
		IUIController* uiController = GetCurrentUIController();
		if (uiController) uiController->Show();
	}

	void UIService::InitializeControllers()
	{
		mainMenuController->Initialize();
	}

	IUIController* UIService::GetCurrentUIController()
	{
		switch (GameService::GetGameState())
		{
		case GameState::MAIN_MENU:
			return mainMenuController;

		default:
			return nullptr;
		}
	}

	void UIService::Destroy()
	{
		delete(mainMenuController);
	}
}
