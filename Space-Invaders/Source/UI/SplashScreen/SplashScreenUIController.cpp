#include "../../Header/UI/SplashScreen/SplashScreenUIController.h"
#include "../../Header/Main/GameService.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Graphic/GraphicService.h"
#include "../../Header/Sound/SoundService.h"
#include "../../Header/Global/Config.h"

namespace UI
{
    namespace SplashScreen
    {
        using namespace Main;
        using namespace Graphic;
        using namespace Global;
        using namespace UIElement;
        using namespace Sound;

        SplashScreenUIController::SplashScreenUIController()
        {
            outscalLogoView = new AnimatedImageView();
        }

        SplashScreenUIController::~SplashScreenUIController()
        {
            delete (outscalLogoView);
        }

        void SplashScreenUIController::Initialize()
        {
            InitializeOutscalLogo();
        }

        void SplashScreenUIController::Update()
        {
            outscalLogoView->Update();
        }

        void SplashScreenUIController::Render()
        {
            outscalLogoView->Render();
        }

        void SplashScreenUIController::InitializeOutscalLogo()
        {
            sf::Vector2f position = GetLogoPosition();
            outscalLogoView->Initialize(Config::outscalLogoTexturePath, logoWidth, logoHeight, position);

        }

        void SplashScreenUIController::FadeInAnimationCallback()
        {
            outscalLogoView->PlayAnimation(AnimationType::FADE_OUT, logoAnimationDuration, std::bind(&SplashScreenUIController::FadeOutAnimationCallback, this));
        }

        void SplashScreenUIController::FadeOutAnimationCallback()
        {
            ServiceLocator::GetInstance()->GetSoundService()->PlayBackgroundMusic();
            GameService::SetGameState(GameState::MAIN_MENU);
        }

        sf::Vector2f SplashScreenUIController::GetLogoPosition()
        {
            sf::RenderWindow* gameWindow = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();

            float xPosition = (gameWindow->getSize().x - logoWidth) / 2.0f;
            float yPosition = (gameWindow->getSize().y - logoHeight) / 2.0f;

            return sf::Vector2f(xPosition, yPosition);
        }

        void SplashScreenUIController::Show()
        {
            outscalLogoView->PlayAnimation(AnimationType::FADE_IN, logoAnimationDuration, std::bind(&SplashScreenUIController::FadeInAnimationCallback, this));
        }
    }
}