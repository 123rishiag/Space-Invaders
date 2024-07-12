#pragma once
#include <SFML/Graphics.hpp>
#include "../Collision/ICollider.h"
#include "../../Header/Entity/EntityConfig.h"
#include "../../Header/Powerup/PowerupConfig.h"
#include "../../Header/Player/PlayerModel.h"

namespace Player {
    enum class PlayerState;
    class PlayerView;

    class PlayerController : public Collision::ICollider
    {
    private:
        PlayerView* playerView;
        PlayerModel* playerModel;

        void ProcessPlayerInput();
        void MoveLeft();
        void MoveRight();

        void ProcessBulletCollision(ICollider* otherCollider);
        void ProcessPowerupCollision(ICollider* otherCollider);
        void ProcessEnemyCollision(ICollider* otherCollider);

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

        void DecreasePlayerLive();
        inline void IncreaseEnemiesKilled(int val) { PlayerModel::enemiesKilled += val; };

        sf::Vector2f GetPlayerPosition() const;
        PlayerState GetPlayerState() const;
        Entity::EntityType GetEntityType() const;

        const sf::Sprite& GetColliderSprite() override;
        void OnCollision(ICollider* otherCollider) override;

    };
}