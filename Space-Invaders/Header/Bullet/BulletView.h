#pragma once
#include <SFML/Graphics.hpp>

namespace Bullet
{
    class BulletController;
    enum class BulletType;

    class BulletView
    {
    private:
        const float bulletSpriteWidth = 18.f;
        const float bulletSpriteHeight = 18.f;

        sf::RenderWindow* gameWindow;
        sf::Texture bulletTexture;
        sf::Sprite bulletSprite;

        BulletController* bulletController;

        void InitializeImage(BulletType type);
        void ScaleImage();

    public:
        BulletView();
        ~BulletView();

        void Initialize(BulletController* controller);
        void Update();
        void Render();
    };
}