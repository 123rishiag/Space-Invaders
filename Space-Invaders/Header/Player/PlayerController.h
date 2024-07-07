#pragma once
#include <SFML/Graphics.hpp>

namespace Player {
    enum class PlayerState;
    class PlayerModel;
    class PlayerView;

    class PlayerController
    {
    private:
        PlayerView* playerView;
        PlayerModel* playerModel;

        void ProcessPlayerInput();
        void FireBullet();
        void MoveLeft();
        void MoveRight();

    public:
        PlayerController();
        ~PlayerController();

        void Initialize();
        void Update();
        void Render();

        sf::Vector2f GetPlayerPosition() const;
    };
}