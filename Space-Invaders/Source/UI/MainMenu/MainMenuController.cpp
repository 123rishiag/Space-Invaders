#include "../../Header/UI/MainMenu/MainMenuController.h"
#include "../../Header/Main/GameService.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Graphic/GraphicService.h"

namespace UI
{
    namespace MainMenu //nested namespace since everything in MainMenu exists inside UI
    {
        using namespace Global;
        using namespace Main;
        using namespace Graphic;

        MainMenuUIController::MainMenuUIController() { gameWindow = nullptr; }

        void MainMenuUIController::Initialize()
        {
            gameWindow = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();
            InitializeBackgroundImage();
            InitializeButtons();
        }

        void MainMenuUIController::InitializeBackgroundImage()
        {   //check if a texture loaded properly
            if (backgroundTexture.loadFromFile(backgroundTexturePath))
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
            return playButtonTexture.loadFromFile(playButtonTexturePath) &&
                instructionsButtonTexture.loadFromFile(instructionsButtonTexturePath) &&
                quitButtonTexture.loadFromFile(quitButtonTexturePath);
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

        void MainMenuUIController::Update()
        {
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