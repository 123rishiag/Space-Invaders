#pragma once
#include <SFML/Graphics.hpp>

namespace Player {
    enum class PlayerState //Our Enum
    {
        ALIVE,
        DEAD,
        // we will add more states later
    };

    class PlayerModel
    {

    private:
        const sf::Vector2f initialPlayerPosition = sf::Vector2f(950.f, 950.f);
        sf::Vector2f playerPosition;
        PlayerState playerState; //Declaration
        int playerScore;

    public:
        const sf::Vector2f leftMostPosition = sf::Vector2f(50.f, 950.f);
        const sf::Vector2f rightMostPosition = sf::Vector2f(1800.f, 950.f);

        const float playerMovementSpeed = 350.0f;

        PlayerModel();
        ~PlayerModel();

        void Initialize();

        void Reset();

        sf::Vector2f GetPlayerPosition() const;
        void SetPlayerPosition(sf::Vector2f position);

        int GetPlayerScore() const;
        void SetPlayerScore(int score);

        float GetPlayerMoveSpeed() const;

        PlayerState GetPlayerState() const;
        void SetPlayerState(PlayerState state);

    };
}