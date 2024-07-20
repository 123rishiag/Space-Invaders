#include "../../Header/UI/MainMenu/InstructionUIController.h"
#include "../../Header/Main/GameService.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Sound/SoundService.h"

namespace UI
{
    namespace MainMenu
    {
        using namespace Global;
        using namespace Main;
        using namespace UIElement;
        using namespace Sound;

        InstructionUIController::InstructionUIController()
        {
            CreateImage();
            CreateButton();
            CreateText();
        }

        InstructionUIController::~InstructionUIController()
        {
            Destroy();
        }

        void InstructionUIController::Initialize()
        {
            InitializeImage();
            InitializeButton();
            InitializeText();

            RegisterButtonCallback();
        }

        void InstructionUIController::CreateImage()
        {
            backgroundImage = new ImageView();

            bunkerImage = new ImageView();

            zapperImage = new ImageView();
            subzeroImage = new ImageView();
            thunderSnakeImage = new ImageView();
            ufoImage = new ImageView();

            outscalBombImage = new ImageView();
            rapidFireImage = new ImageView();
            shieldImage = new ImageView();
            tripleLaserImage = new ImageView();
        }

        void InstructionUIController::CreateButton()
        {
            mainMenuButton = new ButtonView();
        }

        void InstructionUIController::CreateText()
        {
            controlsHeaderText = new TextView();
            controlsText = new TextView();

            elementHeaderText = new TextView();
            bunkerText = new TextView();

            enemiesHeaderText = new TextView();
            zapperText = new TextView();
            subzeroText = new TextView();
            thunderSnakeText = new TextView();
            ufoText = new TextView();

            powerupsHeaderText = new TextView();
            outscalBombText = new TextView();
            rapidFireText = new TextView();
            shieldText = new TextView();
            tripleLaserText = new TextView();
        }

        void InstructionUIController::InitializeImage()
        {
            sf::RenderWindow* gameWindow = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();
            backgroundImage->Initialize(Config::backgroundTexturePath, gameWindow->getSize().x, gameWindow->getSize().y, sf::Vector2f(0.f, 0.f));
            backgroundImage->SetImageAlpha(backgroundAlpha);

            bunkerImage->Initialize(Config::bunkerTexturePath, iconSize, iconSize, bunkerImagePosition);
            
            zapperImage->Initialize(Config::zapperTexturePath, iconSize, iconSize, zapperImagePosition);
            subzeroImage->Initialize(Config::subzeroTexturePath, iconSize, iconSize, subzeroImagePosition);
            thunderSnakeImage->Initialize(Config::thunderSnakeTexturePath, iconSize, iconSize, thunderSnakeImagePosition);
            ufoImage->Initialize(Config::ufoTexturePath, iconSize, iconSize, ufoImagePosition);

            outscalBombImage->Initialize(Config::outscalBombTexturePath, iconSize, iconSize, outscalBombImagePosition);
            rapidFireImage->Initialize(Config::rapidFireTexturePath, iconSize, iconSize, rapidFireImagePosition);
            shieldImage->Initialize(Config::shieldTexturePath, iconSize, iconSize, shieldImagePosition);
            tripleLaserImage->Initialize(Config::tripleLaserTexturePath, iconSize, iconSize, tripleLaserImagePosition);

        }

        void InstructionUIController::InitializeButton()
        {
            mainMenuButton->Initialize("Main Menu Button", Config::menuButtonTexturePath, buttonWidth, buttonHeight, sf::Vector2f(0, mainMenuButtonYPosition));
            mainMenuButton->SetCentreAligned();
        }

        void InstructionUIController::InitializeText()
        {
            controlsHeaderText->Initialize(
                "Game Controls",
                controlsHeaderTextPosition,
                FontType::BUBBLE_BOBBLE,
                instructionFontSize,
                instructionTextColor
            );
            controlsHeaderText->UnderlineText();
            controlsText->Initialize(
                "A/Left: Move Left \t\tD/Right: Move Right \t\tLeft Mouse: Shoot",
                controlsTextPosition,
                FontType::OPEN_SANS,
                instructionFontSize,
                instructionTextColor
            );

            elementHeaderText->Initialize(
                "Elements",
                elementHeaderTextPosition,
                FontType::BUBBLE_BOBBLE,
                instructionFontSize,
                instructionTextColor
            );
            elementHeaderText->UnderlineText();
            bunkerText->Initialize(
                "Bunker: Protects from enemy attacks",
                bunkerTextPosition,
                FontType::OPEN_SANS,
                instructionFontSize,
                instructionTextColor
            );

            enemiesHeaderText->Initialize(
                "Enemies",
                enemiesHeaderTextPosition,
                FontType::BUBBLE_BOBBLE,
                instructionFontSize,
                instructionTextColor
            );
            enemiesHeaderText->UnderlineText();
            zapperText->Initialize(
                "1. Zapper: Moves side-to-side, shoots laser, reduces player health",
                zapperTextPosition,
                FontType::OPEN_SANS,
                instructionFontSize,
                instructionTextColor
            );
            subzeroText->Initialize(
                "2. Subzero: Moves down, shoots torpedoes, destroys bunkers, reduces health",
                subzeroTextPosition,
                FontType::OPEN_SANS,
                instructionFontSize,
                instructionTextColor
            );
            thunderSnakeText->Initialize(
                "3. Thunder Snake: Fast diagonal movement, shoots frost beam, freezes player",
                thunderSnakeTextPosition,
                FontType::OPEN_SANS,
                instructionFontSize,
                instructionTextColor
            );
            ufoText->Initialize(
                "4. UFO: Side-to-side movement, drops power-ups",
                ufoTextPosition,
                FontType::OPEN_SANS,
                instructionFontSize,
                instructionTextColor
            );

            powerupsHeaderText->Initialize(
                "Power-ups",
                powerupsHeaderTextPosition,
                FontType::BUBBLE_BOBBLE,
                instructionFontSize,
                instructionTextColor
            );
            powerupsHeaderText->UnderlineText();
            outscalBombText->Initialize(
                "a) Outscal Bomb: Destroys all enemies",
                outscalBombTextPosition,
                FontType::OPEN_SANS,
                instructionFontSize,
                instructionTextColor
            );
            rapidFireText->Initialize(
                "b) Rapid Fire: Increases fire rate",
                rapidFireTextPosition,
                FontType::OPEN_SANS,
                instructionFontSize,
                instructionTextColor
            );
            shieldText->Initialize(
                "c) Shield: Protects from attacks",
                shieldTextPosition,
                FontType::OPEN_SANS,
                instructionFontSize,
                instructionTextColor
            );
            tripleLaserText->Initialize(
                "d) Triple Laser: Shoots three bullets simultaneously",
                tripleLaserTextPosition,
                FontType::OPEN_SANS,
                instructionFontSize,
                instructionTextColor
            );
        }

        void InstructionUIController::RegisterButtonCallback()
        {
            mainMenuButton->RegisterCallbackFuntion(std::bind(&InstructionUIController::MainMenuButtonCallback, this));
        }

        void InstructionUIController::MainMenuButtonCallback()
        {
            ServiceLocator::GetInstance()->GetSoundService()->PlaySound(SoundType::BUTTON_CLICK);
            GameService::SetGameState(GameState::MAIN_MENU);
        }

        void InstructionUIController::Update()
        {
            backgroundImage->Update();

            bunkerImage->Update();

            zapperImage->Update();
            subzeroImage->Update();
            thunderSnakeImage->Update();
            ufoImage->Update();

            outscalBombImage->Update();
            rapidFireImage->Update();
            shieldImage->Update();
            tripleLaserImage->Update();

            mainMenuButton->Update();

            controlsHeaderText->Update();
            controlsText->Update();

            elementHeaderText->Update();
            bunkerText->Update();

            enemiesHeaderText->Update();
            zapperText->Update();
            subzeroText->Update();
            thunderSnakeText->Update();
            ufoText->Update();

            powerupsHeaderText->Update();
            outscalBombText->Update();
            rapidFireText->Update();
            shieldText->Update();
            tripleLaserText->Update();

        }

        void InstructionUIController::Render()
        {
            backgroundImage->Render();

            bunkerImage->Render();

            zapperImage->Render();
            subzeroImage->Render();
            thunderSnakeImage->Render();
            ufoImage->Render();

            outscalBombImage->Render();
            rapidFireImage->Render();
            shieldImage->Render();
            tripleLaserImage->Render();

            mainMenuButton->Render();

            controlsHeaderText->Render();
            controlsText->Render();

            elementHeaderText->Render();
            bunkerText->Render();

            enemiesHeaderText->Render();
            zapperText->Render();
            subzeroText->Render();
            thunderSnakeText->Render();
            ufoText->Render();

            powerupsHeaderText->Render();
            outscalBombText->Render();
            rapidFireText->Render();
            shieldText->Render();
            tripleLaserText->Render();
        }

        void InstructionUIController::Show()
        {
            backgroundImage->Show();

            bunkerImage->Show();

            zapperImage->Show();
            subzeroImage->Show();
            thunderSnakeImage->Show();
            ufoImage->Show();

            outscalBombImage->Show();
            rapidFireImage->Show();
            shieldImage->Show();
            tripleLaserImage->Show();

            mainMenuButton->Show();

            controlsHeaderText->Show();
            controlsText->Show();

            elementHeaderText->Show();
            bunkerText->Show();

            enemiesHeaderText->Show();
            zapperText->Show();
            subzeroText->Show();
            thunderSnakeText->Show();
            ufoText->Show();

            powerupsHeaderText->Show();
            outscalBombText->Show();
            rapidFireText->Show();
            shieldText->Show();
            tripleLaserText->Show();

            ServiceLocator::GetInstance()->GetSoundService()->PlayBackgroundMusic();
        }

        void InstructionUIController::Destroy()
        {
            delete(backgroundImage);

            delete(bunkerImage);

            delete(zapperImage);
            delete(subzeroImage);
            delete(thunderSnakeImage);
            delete(ufoImage);

            delete(outscalBombImage);
            delete(rapidFireImage);
            delete(shieldImage);
            delete(tripleLaserImage);

            delete(mainMenuButton);

            delete(controlsHeaderText);
            delete(controlsText);

            delete(elementHeaderText);
            delete(bunkerText);

            delete(enemiesHeaderText);
            delete(zapperText);
            delete(subzeroText);
            delete(thunderSnakeText);
            delete(ufoText);

            delete(powerupsHeaderText);
            delete(outscalBombText);
            delete(rapidFireText);
            delete(shieldText);
            delete(tripleLaserText);
        }
    }
}
