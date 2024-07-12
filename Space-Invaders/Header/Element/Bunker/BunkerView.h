#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/UI/UIElement/ImageView.h"

namespace Element 
{
    namespace Bunker
    {
        class BunkerController;

        class BunkerView {
        private:
            const float bunkerSpriteWidth = 80.f;
            const float bunkerSpriteHeight = 80.f;

            BunkerController* bunkerController;
            UI::UIElement::ImageView* bunkerImage;

            void CreateUIElements();
            void InitializeImage();
            sf::String GetBunkerTexturePath();

            void Destroy();

        public:
            BunkerView();
            ~BunkerView();

            void Initialize(BunkerController* controller);
            void Update();
            void Render();


            const sf::Sprite& GetBunkerSprite() const;
        };
    }
}