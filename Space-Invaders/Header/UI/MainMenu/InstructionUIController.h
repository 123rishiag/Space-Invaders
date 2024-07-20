#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/UI/Interface/IUIController.h"
#include "../../Header/UI/UIElement/ImageView.h"
#include "../../Header/UI/UIElement/ButtonView.h"
#include "../../Header/UI/UIElement/TextView.h"

namespace UI
{
    namespace MainMenu
    {
        class InstructionUIController : public Interface::IUIController
        {
        private:
            const float backgroundAlpha = 1000.f;

            const float buttonWidth = 400.f;
            const float buttonHeight = 140.f;

            const int iconSize = 40;
            const float imageTextSpacing = 10.f;
            const float segmentSpacing = 30.f;
            const int instructionFontSize = 24;
            const sf::Color instructionTextColor = sf::Color::White;

            const sf::Vector2f controlsHeaderTextPosition = sf::Vector2f(50.f, 20.f);
            const sf::Vector2f controlsTextPosition = sf::Vector2f(50.f, 2 * segmentSpacing);

            const sf::Vector2f elementHeaderTextPosition = sf::Vector2f(50.f, controlsTextPosition.y + iconSize + segmentSpacing);
            const sf::Vector2f bunkerImagePosition = sf::Vector2f(50.f, elementHeaderTextPosition.y + 2 * segmentSpacing);
            const sf::Vector2f bunkerTextPosition = sf::Vector2f(50.f + iconSize + imageTextSpacing, elementHeaderTextPosition.y + 2 * segmentSpacing);

            const sf::Vector2f enemiesHeaderTextPosition = sf::Vector2f(50.f, bunkerImagePosition.y + iconSize + segmentSpacing);
            const sf::Vector2f zapperImagePosition = sf::Vector2f(50.f, enemiesHeaderTextPosition.y + 2 * segmentSpacing);
            const sf::Vector2f zapperTextPosition = sf::Vector2f(50.f + iconSize + imageTextSpacing, enemiesHeaderTextPosition.y + 2 * segmentSpacing);
            const sf::Vector2f subzeroImagePosition = sf::Vector2f(50.f, zapperImagePosition.y + iconSize + segmentSpacing);
            const sf::Vector2f subzeroTextPosition = sf::Vector2f(50.f + iconSize + imageTextSpacing, zapperImagePosition.y + iconSize + segmentSpacing);
            const sf::Vector2f thunderSnakeImagePosition = sf::Vector2f(50.f, subzeroImagePosition.y + iconSize + segmentSpacing);
            const sf::Vector2f thunderSnakeTextPosition = sf::Vector2f(50.f + iconSize + imageTextSpacing, subzeroImagePosition.y + iconSize + segmentSpacing);
            const sf::Vector2f ufoImagePosition = sf::Vector2f(50.f, thunderSnakeImagePosition.y + iconSize + segmentSpacing);
            const sf::Vector2f ufoTextPosition = sf::Vector2f(50.f + iconSize + imageTextSpacing, thunderSnakeImagePosition.y + iconSize + segmentSpacing);

            const sf::Vector2f powerupsHeaderTextPosition = sf::Vector2f(50.f, ufoImagePosition.y + iconSize + segmentSpacing);
            const sf::Vector2f outscalBombImagePosition = sf::Vector2f(50.f, powerupsHeaderTextPosition.y + 2 * segmentSpacing);
            const sf::Vector2f outscalBombTextPosition = sf::Vector2f(50.f + iconSize + imageTextSpacing, powerupsHeaderTextPosition.y + 2 * segmentSpacing);
            const sf::Vector2f rapidFireImagePosition = sf::Vector2f(50.f, outscalBombImagePosition.y + iconSize + segmentSpacing);
            const sf::Vector2f rapidFireTextPosition = sf::Vector2f(50.f + iconSize + imageTextSpacing, outscalBombImagePosition.y + iconSize + segmentSpacing);
            const sf::Vector2f shieldImagePosition = sf::Vector2f(50.f, rapidFireImagePosition.y + iconSize + segmentSpacing);
            const sf::Vector2f shieldTextPosition = sf::Vector2f(50.f + iconSize + imageTextSpacing, rapidFireImagePosition.y + iconSize + segmentSpacing);
            const sf::Vector2f tripleLaserImagePosition = sf::Vector2f(50.f, shieldImagePosition.y + iconSize + segmentSpacing);
            const sf::Vector2f tripleLaserTextPosition = sf::Vector2f(50.f + iconSize + imageTextSpacing, shieldImagePosition.y + iconSize + segmentSpacing);

            float mainMenuButtonYPosition = static_cast<float>(tripleLaserImagePosition.y) + iconSize + segmentSpacing;


            UIElement::ImageView* backgroundImage;

            UIElement::ImageView* bunkerImage;

            UIElement::ImageView* zapperImage;
            UIElement::ImageView* subzeroImage;
            UIElement::ImageView* thunderSnakeImage;
            UIElement::ImageView* ufoImage;

            UIElement::ImageView* outscalBombImage;
            UIElement::ImageView* rapidFireImage;
            UIElement::ImageView* shieldImage;
            UIElement::ImageView* tripleLaserImage;

            UIElement::ButtonView* mainMenuButton;

            UIElement::TextView* controlsHeaderText;
            UIElement::TextView* controlsText;

            UIElement::TextView* elementHeaderText;
            UIElement::TextView* bunkerText;

            UIElement::TextView* enemiesHeaderText;
            UIElement::TextView* zapperText;
            UIElement::TextView* subzeroText;
            UIElement::TextView* thunderSnakeText;
            UIElement::TextView* ufoText;

            UIElement::TextView* powerupsHeaderText;
            UIElement::TextView* outscalBombText;
            UIElement::TextView* rapidFireText;
            UIElement::TextView* shieldText;
            UIElement::TextView* tripleLaserText;

            void CreateImage();
            void CreateButton();
            void CreateText();

            void InitializeImage();
            void InitializeButton();
            void InitializeText();

            void RegisterButtonCallback();
            void MainMenuButtonCallback();

            void Destroy();

        public:
            InstructionUIController();
            ~InstructionUIController();

            void Initialize() override;
            void Update() override;
            void Render() override;
            void Show() override;
        };
    }
}
