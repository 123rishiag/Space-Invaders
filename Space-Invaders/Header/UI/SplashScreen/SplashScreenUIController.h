#pragma once
#include "../../Header/UI/Interface/IUIController.h"
#include "../../Header/UI/UIElement/AnimatedImageView.h"

namespace UI
{
	namespace SplashScreen
	{
		class SplashScreenUIController : public Interface::IUIController
		{
		private:
			// Constants:
			const float logoAnimationDuration = 2.0f;
			const float logoWidth = 600.f;
			const float logoHeight = 134.f;

			UIElement::AnimatedImageView* outscalLogoView;

			void InitializeOutscalLogo();
			void FadeInAnimationCallback();
			void FadeOutAnimationCallback();
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