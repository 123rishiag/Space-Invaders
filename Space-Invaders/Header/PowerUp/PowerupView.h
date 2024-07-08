#pragma once
#include <SFML/Graphics.hpp>

namespace Powerup
{
    class PowerupController;
    enum class PowerupType;

    class PowerupView
    {
    private:
        const float powerupSpriteWidth = 30.f;
        const float powerupSpriteHeight = 30.f;

        sf::RenderWindow* gameWindow;
        sf::Texture powerupTexture;
        sf::Sprite powerupSprite;

        PowerupController* powerupController;

        void InitializeImage(PowerupType powerupType);
        void ScaleImage();

        void Destroy();

    public:
        PowerupView();
        ~PowerupView();

        void Initialize(PowerupController* controller);
        void Update();
        void Render();
    };
}