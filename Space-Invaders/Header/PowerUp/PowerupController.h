#pragma once
#include "../../Header/Collectible/ICollectible.h"
#include "../../Header/Collision/ICollider.h"

namespace Powerup
{
    class PowerupView;
    class PowerupModel;

    enum class PowerupType;

    class PowerupController : public Collectible::ICollectible, public Collision::ICollider
    {
    protected:
        PowerupView* powerupView;
        PowerupModel* powerupModel;

        virtual void ApplyPowerup() = 0;

        void UpdatePowerupPosition();
        void HandleOutOfBounds();

    public:
        PowerupController(PowerupType type);
        virtual ~PowerupController();

        void Initialize(sf::Vector2f position) override;
        void Update() override;
        void Render() override;

        void OnCollected() override;

        sf::Vector2f GetCollectiblePosition() override;
        PowerupType GetPowerupType();

        const sf::Sprite& GetColliderSprite() override;
        void OnCollision(ICollider* otherCollider) override;
    };
}