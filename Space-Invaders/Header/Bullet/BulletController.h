#pragma once
#include "../../Header/Projectile/IProjectile.h"
#include "../../Header/Bullet/BulletConfig.h"
#include "../../Header/Entity/EntityConfig.h"
#include "../../Header/Collision/ICollider.h"

namespace Bullet
{
    class BulletView;
    class BulletModel;

    enum class BulletType;

    class BulletController : public Projectile::IProjectile, public Collision::ICollider
    {
    protected:
        BulletView* bulletView;
        BulletModel* bulletModel;

        void UpdateProjectilePosition() override;

        void ProcessBulletCollision(ICollider* otherCollider);
        void ProcessEnemyCollision(ICollider* otherCollider);
        void ProcessPlayerCollision(ICollider* otherCollider);
        void ProcessBunkerCollision(ICollider* otherCollider);

        void MoveUp();
        void MoveDown();
        void HandleOutOfBounds();

    public:
        BulletController(BulletType type, Entity::EntityType ownerType);
        virtual ~BulletController();

        void Initialize(sf::Vector2f position, Bullet::MovementDirection direction) override;
        void Update() override;
        void Render() override;

        sf::Vector2f GetProjectilePosition() override;
        BulletType GetBulletType();
        Entity::EntityType GetEntityType() const;

        const sf::Sprite& GetColliderSprite() override;
        void OnCollision(ICollider* otherCollider) override;
    };
}