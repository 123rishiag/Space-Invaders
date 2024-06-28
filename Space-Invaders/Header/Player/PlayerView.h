#pragma once
#include <SFML/Graphics.hpp>

namespace Player {
    class PlayerController;

    class PlayerView
    {
    private:
        PlayerController* playerController; // ptr to player controller

        const sf::String playerTexturePath = "assets/textures/player_ship.png";
        const float playerSpriteWidth = 60.f;
        const float playerSpriteHeight = 60.f;

        sf::RenderWindow* gameWindow;

        sf::Texture playerTexture;
        sf::Sprite playerSprite;

        void InitializePlayerSprite();
        void ScalePlayerSprite();

    public:
        PlayerView();
        ~PlayerView();

        void Initialize(PlayerController* controller); // we pass a pointer of type controller because we need to use this in the view later.
        void Update();
        void Render();
    };
}