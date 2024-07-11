#pragma once
#include <SFML/Graphics.hpp>
#include "../Collision/ICollider.h"
#include "../../Header/Entity/EntityConfig.h"
#include "../../header/Powerup/PowerupConfig.h"

namespace Player {
    enum class PlayerState;
    class PlayerModel;
    class PlayerView;

    class PlayerController : public Collision::ICollider
    {
    private:

        float elapsedShieldDuration;
        float elapsedRapidFireDuration;
        float elapsedTripleLaserDuration;

        float elapsedFireDuration;
        float elapsedFreezeDuration;

        PlayerView* playerView;
        PlayerModel* playerModel;

        void ProcessPlayerInput();
        void MoveLeft();
        void MoveRight();

        bool ProcessBulletCollision(ICollider* otherCollider);
        bool ProcessPowerupCollision(ICollider* otherCollider);
        bool ProcessEnemyCollision(ICollider* otherCollider);

        void UpdateFreezeDuration();
        void FreezePlayer();

        void UpdateFireDuration();
        void ProcessBulletFire();
        void FireBullet(bool bTripleLaser = false);
        void FireBullet(sf::Vector2f position);

        void UpdatePowerupDuration();

        void DisableShield();
        void DisableRapidFire();
        void DisableTripleLaser();

    public:
        PlayerController();
        ~PlayerController();

        void Initialize();
        void Update();
        void Render();

        void Reset();

        void EnableShield();
        void EnableRapidFire();
        void EnableTripleLaser();

        sf::Vector2f GetPlayerPosition() const;
        int GetPlayerScore() const;
        PlayerState GetPlayerState() const;
        Entity::EntityType GetEntityType() const;
        const sf::Sprite& GetColliderSprite() override;

        void OnCollision(ICollider* otherCollider) override;

    };
}