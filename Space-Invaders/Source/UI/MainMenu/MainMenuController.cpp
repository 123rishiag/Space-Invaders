#include "../../Header/UI/MainMenu/MainMenuController.h"
#include "../../Header/Main/GameService.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Graphic/GraphicService.h"
#include "../../Header/Global/Config.h"

namespace UI
{
    namespace MainMenu //nested namespace since everything in MainMenu exists inside UI
    {
        using namespace Global;
        using namespace Main;
        using namespace Graphic;
        using namespace Sound;
        using namespace Event;

        MainMenuUIController::MainMenuUIController() { gameWindow = nullptr; }

        void MainMenuUIController::Initialize()
        {
            gameWindow = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();
            InitializeBackgroundImage();
            InitializeButtons();
        }

        void MainMenuUIController::InitializeBackgroundImage()
        {   //check if a texture loaded properly
            if (backgroundTexture.loadFromFile(Config::backgroundTexturePath))
            {   //if it did then set the bg image and scale it
                backgroundSprite.setTexture(backgroundTexture);
                ScaleBackgroundImage();
            }
        }

        void MainMenuUIController::ScaleBackgroundImage()
        {
            /*
            // Don't worry about the static_cast we will discuss it later. For now know that this function is
            // just scaling our background image based on the size of the game window
            */
            backgroundSprite.setScale(
                static_cast<float>(gameWindow->getSize().x) / backgroundSprite.getTexture()->getSize().x,
                static_cast<float>(gameWindow->getSize().y) / backgroundSprite.getTexture()->getSize().y
            );
        }

        void MainMenuUIController::InitializeButtons()
        {
            // check if the textures loaded
            if (LoadButtonTexturesFromFile())
            {
                // order of function calls matter
                SetButtonSprites();
                ScaleAllButtons();
                PositionButtons();
            }
        }
        // only returns true if all textures are loaded
        bool MainMenuUIController::LoadButtonTexturesFromFile()
        {
            return playButtonTexture.loadFromFile(Config::playButtonTexturePath) &&
                instructionsButtonTexture.loadFromFile(Config::instructionsButtonTexturePath) &&
                quitButtonTexture.loadFromFile(Config::quitButtonTexturePath);
        }

        void MainMenuUIController::SetButtonSprites()
        {
            playButtonSprite.setTexture(playButtonTexture);
            instructionsButtonSprite.setTexture(instructionsButtonTexture);
            quitButtonSprite.setTexture(quitButtonTexture);
        }


        void MainMenuUIController::ScaleAllButtons()
        {
            ScaleButton(&playButtonSprite);
            ScaleButton(&instructionsButtonSprite);
            ScaleButton(&quitButtonSprite);
        }

        void MainMenuUIController::ScaleButton(sf::Sprite* buttonToScale) const
        {
            buttonToScale->setScale(
                buttonWidth / buttonToScale->getTexture()->getSize().x,
                buttonHeight / buttonToScale->getTexture()->getSize().y
            );
        }

        void MainMenuUIController::PositionButtons()
        {
            float xPosition = (static_cast<float>(gameWindow->getSize().x) / 2) - buttonWidth / 2;

            playButtonSprite.setPosition({ xPosition, 500.f });
            instructionsButtonSprite.setPosition({ xPosition, 700.f });
            quitButtonSprite.setPosition({ xPosition, 900.f });
        }

        /*
          // First we get the location of the mouse on our screen.
          // If we register a click while the mouse is above a button,
          // then we do something based on which button it is
          // we will call processButtonInteractions() on update.
          */
        void MainMenuUIController::ProcessButtonInteractions()
        {
            sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(*gameWindow));

            if (ClickedButton(&playButtonSprite, mousePosition))
            {
                ServiceLocator::GetInstance()->GetSoundService()->PlaySound(SoundType::BUTTON_CLICK); //play button sound
                ServiceLocator::GetInstance()->GetSoundService()->PlayBackgroundMusic(); //play background music
                GameService::SetGameState(GameState::GAMEPLAY);
            }

            if (ClickedButton(&instructionsButtonSprite, mousePosition))
            {
                printf("Clicked Instruction Button \\n");
            }

            if (ClickedButton(&quitButtonSprite, mousePosition))
                gameWindow->close();
        }

        /*
        // This checks if the use left clicked on a sprite and then returns
        // true if the click happened while the mouse was overlapping with the
        // sprite.
        */
        bool MainMenuUIController::ClickedButton(sf::Sprite* buttonSprite, sf::Vector2f mousePosition)
        {
            EventService* eventService = ServiceLocator::GetInstance()->GetEventService();
            return eventService->PressedLeftMouseButton() && buttonSprite->getGlobalBounds().contains(mousePosition);
        }

        void MainMenuUIController::Update()
        {
            ProcessButtonInteractions();
        }

        void MainMenuUIController::Render()
        {
            gameWindow->draw(backgroundSprite);
            gameWindow->draw(playButtonSprite);
            gameWindow->draw(instructionsButtonSprite);
            gameWindow->draw(quitButtonSprite);
        }

    }
}