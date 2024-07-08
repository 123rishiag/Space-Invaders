#pragma once
#include <SFML/Graphics.hpp>

namespace Powerup
{
    enum class PowerupType;

    class PowerupModel
    {
    private:
        float movementSpeed = 300.f;

        sf::Vector2f powerupPosition;
        PowerupType powerupType;

    public:
        PowerupModel(PowerupType type);
        ~PowerupModel();

        void Initialize(sf::Vector2f position);

        sf::Vector2f GetPowerupPosition();
        void SetPowerupPosition(sf::Vector2f position);

        PowerupType GetPowerupType();
        void SetPowerupType(PowerupType type);

        float GetMovementSpeed();
        void SetMovementSpeed(float speed);
    };
}