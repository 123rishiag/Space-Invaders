#pragma once
#include "../../Header/UI/Interface/IUIController.h"

namespace UI
{
	namespace MainMenu
	{
		class MainMenuUIController;
	}

	class UIService : public Interface::IUIController
	{
	private:
		UI::MainMenuUIController* mainMenuController;

		IUIController* GetCurrentUIController();

		void CreateControllers();
		void InitializeControllers();
		void Destroy();

	public:
		UIService();
		~UIService();

		void Initialize();
		void Update();
		void Render();

		void ShowScreen();
	};
}
