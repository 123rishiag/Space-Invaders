#include "../../Header/Bullet/BulletController.h"
#include "../../Header/Bullet/BulletModel.h"
#include "../../Header/Bullet/BulletView.h"
#include "../../Header/Bullet/BulletConfig.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Bullet 
{
    using namespace Global;

    BulletController::BulletController(BulletType type) 
    {
        bulletView = new BulletView();
        bulletModel = new BulletModel(type);
    }
    BulletController::~BulletController() 
    {
        delete (bulletView);
        delete (bulletModel);
    }
    void BulletController::Initialize(sf::Vector2f position, Bullet::MovementDirection direction)
    {
        bulletView->Initialize(this);
        bulletModel->Initialize(position, direction);
    }
    void BulletController::Update()
    {
        UpdateProjectilePosition();
        bulletView->Update();
        HandleOutOfBounds();
    }
    void BulletController::Render()
    {
        bulletView->Render();
    }
    void BulletController::UpdateProjectilePosition() 
    {
        switch (bulletModel->GetMovementDirection())
        {
        case::Bullet::MovementDirection::UP:
            MoveUp();
            break;

        case::Bullet::MovementDirection::DOWN:
            MoveDown();
            break;
        }
    }
    void BulletController::MoveUp()
    {
        sf::Vector2f currentPosition = bulletModel->GetBulletPosition();
        currentPosition.y -= bulletModel->GetMovementSpeed() * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

        bulletModel->SetBulletPosition(currentPosition);
    }
    void BulletController::MoveDown()
    {
        sf::Vector2f currentPosition = bulletModel->GetBulletPosition();
        currentPosition.y += bulletModel->GetMovementSpeed() * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

        bulletModel->SetBulletPosition(currentPosition);
    }
    void BulletController::HandleOutOfBounds()
    {
        sf::Vector2f bulletPosition = GetProjectilePosition();
        sf::Vector2u windowSize = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow()->getSize();

        if (bulletPosition.x < 0 || bulletPosition.x > windowSize.x ||
            bulletPosition.y < 0 || bulletPosition.y > windowSize.y)
        {
            ServiceLocator::GetInstance()->GetBulletService()->DestroyBullet(this);
        }
    }
    sf::Vector2f BulletController::GetProjectilePosition()
    {
        return bulletModel->GetBulletPosition();
    }
    BulletType BulletController::GetBulletType()
    {
        return bulletModel->GetBulletType();
    }
}