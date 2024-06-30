#pragma once
#include <SFML/Graphics.hpp>

namespace Gameplay
{
    class GameplayView
    {
    private:
        const sf::String backgroundTexturePath = "assets/textures/space_invaders_bg.png";

        sf::RenderWindow* gameWindow;
        sf::Texture backgroundTexture;
        sf::Sprite backgroundSprite;

        void InitializeBackgroundSprite();
        void ScaleBackgroundSprite();

    public:
        GameplayView();
        ~GameplayView();

        void Initialize();
        void Update();
        void Render();
    };
}