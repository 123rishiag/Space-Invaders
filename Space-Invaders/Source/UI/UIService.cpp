#include "../../Header/UI/UIService.h"
#include "../../Header/Main/GameService.h"
#include "../../Header/UI/MainMenu/MainMenuController.h"

namespace UI
{
	using namespace Main;
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
		InitializeControllers();
	}

	void UIService::Update()
	{
	}

	void UIService::Render()
	{
		mainMenuController->Render();
	}

	void UIService::InitializeControllers()
	{
		mainMenuController->Initialize();
	}

	void UIService::Destroy()
	{
		delete(mainMenuController);
	}
}
