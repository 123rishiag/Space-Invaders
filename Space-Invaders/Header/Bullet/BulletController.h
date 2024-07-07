#pragma once
#include "../../Header/Projectile/IProjectile.h"
#include "../../Header/Bullet/BulletConfig.h"

namespace Bullet
{
    class BulletView;
    class BulletModel;
    enum class BulletType;

    class BulletController : public Projectile::IProjectile 
    {
    protected:
        BulletView* bulletView;
        BulletModel* bulletModel;

        void UpdateProjectilePosition() override;

        void MoveUp();
        void MoveDown();
        void HandleOutOfBounds();

    public:
        BulletController(BulletType type);
        virtual ~BulletController();

        void Initialize(sf::Vector2f position, Bullet::MovementDirection direction) override;
        void Update() override;
        void Render() override;

        sf::Vector2f GetProjectilePosition() override;
        BulletType GetBulletType();
    };
}