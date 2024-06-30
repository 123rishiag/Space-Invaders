#pragma once
#include <SFML/Graphics.hpp>

namespace Enemy
{
    class EnemyController;

    class EnemyView
    {
    private:
        const sf::String enemyTexturePath = "assets/textures/zapper.png";

        const float enemySpriteWidth = 60.f;
        const float enemySpriteHeight = 60.f;

        EnemyController* enemyController;

        sf::RenderWindow* gameWindow;
        sf::Texture enemyTexture;
        sf::Sprite enemySprite;

        void InitializeEnemySprite();
        void ScaleEnemySprite();

    public:
        EnemyView();
        ~EnemyView();

        void Initialize(EnemyController* controller);
        void Update();
        void Render();
    };
}