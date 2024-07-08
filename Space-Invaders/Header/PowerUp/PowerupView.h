#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/UI/UIElement/ImageView.h"

namespace Powerup
{
    class PowerupController;

    class PowerupView
    {
    private:
        const float powerupSpriteWidth = 30.f;
        const float powerupSpriteHeight = 30.f;

        PowerupController* powerupController;
        UI::UIElement::ImageView* powerupImage;

        void CreateUIElements();
        void InitializeImage();
        sf::String GetPowerupTexturePath();

        void Destroy();

    public:
        PowerupView();
        ~PowerupView();

        void Initialize(PowerupController* controller);
        void Update();
        void Render();
    };
}