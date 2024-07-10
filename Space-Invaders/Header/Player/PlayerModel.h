#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Entity/EntityConfig.h"

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

        Entity::EntityType bulletOwner;

    public:
        const sf::Vector2f leftMostPosition = sf::Vector2f(50.f, 950.f);
        const sf::Vector2f rightMostPosition = sf::Vector2f(1800.f, 950.f);
        const sf::Vector2f barrelPositionOffset = sf::Vector2f(20.f, -50.f); // we add this offset variable

        const float playerMovementSpeed = 350.0f;

        PlayerModel(Entity::EntityType ownerType);
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

        Entity::EntityType GetEntityType() const;

    };
}