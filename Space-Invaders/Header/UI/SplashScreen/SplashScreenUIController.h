#pragma once
#include "../../Header/UI/Interface/IUIController.h"
#include "../../Header/UI/UIElement/ImageView.h"

namespace UI
{
	namespace SplashScreen
	{
		class SplashScreenUIController : public Interface::IUIController
		{
		private:
			// Constants:
			const float splashScreenDuration = 2.0f;
			float elapsedDuration = 0.0f;
			const float logoWidth = 600.f;
			const float logoHeight = 134.f;

			UIElement::ImageView* outscalLogoView;

			void InitializeOutscalLogo();
			void UpdateTimer();
			void ShowMainMenu();
			sf::Vector2f GetLogoPosition();

		public:


			SplashScreenUIController();
			~SplashScreenUIController();

			void Initialize() override;
			void Update() override;
			void Render() override;
			void Show() override;
		};
	}
}