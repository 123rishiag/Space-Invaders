#pragma once
#include "../../Header/UI/Interface/IUIController.h"

namespace UI
{
	class MainMenuUIController;

	class UIService : public Interface::IUIController
	{
	private:
		MainMenuUIController* mainMenuController;

		IUIController* GetCurrentUIController();

		void CreateControllers();
		void InitializeControllers();
		void Destroy();

	public:
		UIService();
		~UIService();

		void Initialize() override;
		void Update() override;
		void Render() override;
		void Show() override;
	};
}
