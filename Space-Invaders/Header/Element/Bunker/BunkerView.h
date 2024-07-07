#pragma once
#include <SFML/Graphics.hpp>

namespace Element {

	class BunkerController;

	class BunkerView {
    private:
        const sf::String bunkerTexturePath = "assets/textures/bunker.png";

        const float bunkerSpriteWidth = 60.f;
        const float bunkerSpriteHeight = 60.f;

        BunkerController* bunkerController;

        sf::RenderWindow* gameWindow;
        sf::Texture bunkerTexture;
        sf::Sprite bunkerSprite;

        void InitializeBunkerSprite();
        void ScaleBunkerSprite();

    public:
        BunkerView();
        ~BunkerView();

        void Initialize(BunkerController* controller);
        void Update();
        void Render();
	};
}