#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Entity/EntityConfig.h"

namespace Player {
    enum class PlayerState //Our Enum
    {
        ALIVE,
        FROZEN,
        DEAD,
        // we will add more states later
    };

    class PlayerModel
    {

    private:

        const sf::Vector2f initialPlayerPosition = sf::Vector2f(950.f, 950.f);
        sf::Vector2f playerPosition;
        Entity::EntityType bulletOwner;
        PlayerState playerState; //Declaration
        int playerScore;

        bool bShield;
        bool bRapidFire;
        bool bTripleLaser;

    public:
        const sf::Vector2f leftMostPosition = sf::Vector2f(50.f, 950.f);
        const sf::Vector2f rightMostPosition = sf::Vector2f(1800.f, 950.f);
        const sf::Vector2f barrelPositionOffset = sf::Vector2f(20.f, -50.f); // we add this offset variable
        const sf::Vector2f secondWeaponPositionOffset = sf::Vector2f(45.f, 0.f);
        const sf::Vector2f thirdWeaponPositionOffset = sf::Vector2f(-45.f, 0.f);

        const float shieldPowerupDuration = 10.f;
        const float rapidFirePowerupDuration = 10.f;
        const float tripleLaserPowerupDuration = 10.f;

        const float freezeDuration = 2.f;

        const float fireCooldownDuration = 0.2f;
        const float rapidFireCooldownDuration = 0.05f;
        const float tripleLaserPositionOffset = 30.f;

        float elapsedShieldDuration;
        float elapsedRapidFireDuration;
        float elapsedTripleLaserDuration;

        float elapsedFireDuration;
        float elapsedFreezeDuration;

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

        Entity::EntityType GetEntityType() const;

        bool IsShieldEnabled();
        bool IsRapidFireEnabled();
        bool IsTripleLaserEnabled();

        void SetShieldState(bool value);
        void SetRapidFireState(bool value);
        void SetTripleFireState(bool value);

    };
}