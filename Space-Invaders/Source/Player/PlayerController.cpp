#include "../../Header/Player/PlayerController.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Event/EventService.h"
#include "../../Header/Player/PlayerModel.h"
#include "../../Header/Player/PlayerView.h"
#include "../../header/Bullet/BulletConfig.h"
#include "../../header/Entity/EntityConfig.h"
#include "../../header/Bullet/BulletController.h"
#include "../../header/Enemy/EnemyController.h"
#include "../../header/Powerup/PowerupController.h"
// #include<algorithm>

namespace Player {

	using namespace Global;
	using namespace Event;
	using namespace Time;
	using namespace Bullet;
	using namespace Entity;
	using namespace Enemy;
	using namespace Powerup;

	PlayerController::PlayerController()
	{
		playerView = new PlayerView();
		playerModel = new PlayerModel();
	}

	PlayerController::~PlayerController()
	{
		delete (playerView);
		delete (playerModel);
	}
	//the controller is responsible for calling the lifecycle methods for the other two
	void PlayerController::Initialize()
	{
		playerModel->Initialize();
		playerView->Initialize(this); // 'this' refers to the class we are currently inside
	}

	void PlayerController::Update()
	{
		switch (playerModel->GetPlayerState())
		{
		case::Player::PlayerState::ALIVE:
			ProcessPlayerInput();
			break;

		case::Player::PlayerState::FROZEN:
			UpdateFreezeDuration();
			break;
		}

		UpdatePowerupDuration();
		UpdateFireDuration();

		playerView->Update();
	}

	void PlayerController::Render()
	{
		playerView->Render(); // render the view
	}

	void PlayerController::Reset()
	{
		playerModel->Reset();
	}

	bool PlayerController::ProcessBulletCollision(ICollider* otherCollider)
	{
		if (playerModel->IsShieldEnabled())
			return false;

		BulletController* bulletController = dynamic_cast<BulletController*>(otherCollider);

		if (bulletController && bulletController->GetEntityType() != EntityType::PLAYER)
		{
			if (bulletController->GetBulletType() == BulletType::FROST_BULLET)
			{
				playerModel->SetPlayerState(PlayerState::FROZEN);
				playerModel->elapsedFreezeDuration = playerModel->freezeDuration;
			}
			else ServiceLocator::GetInstance()->GetGameplayService()->Restart();
			return true;
		}

		return false;
	}

	bool PlayerController::ProcessEnemyCollision(ICollider* otherCollider)
	{
		if (playerModel->IsShieldEnabled())
			return false;

		EnemyController* enemyController = dynamic_cast<EnemyController*>(otherCollider);
		if (enemyController)
		{
			ServiceLocator::GetInstance()->GetGameplayService()->Restart();
			return true;
		}
		return false;
	}

	bool PlayerController::ProcessPowerupCollision(ICollider* otherCollider)
	{
		PowerupController* powerupController = dynamic_cast<PowerupController*>(otherCollider);
		if (powerupController)
		{
			return true;
		}
		return false;
	}

	void PlayerController::UpdatePowerupDuration()
	{
		if (playerModel->elapsedShieldDuration > 0)
		{
			playerModel->elapsedShieldDuration -= ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

			if (playerModel->elapsedShieldDuration <= 0)
				DisableShield();
		}

		if (playerModel->elapsedRapidFireDuration > 0)
		{
			playerModel->elapsedRapidFireDuration -= ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

			if (playerModel->elapsedRapidFireDuration <= 0)
				DisableRapidFire();
		}

		if (playerModel->elapsedTripleLaserDuration > 0)
		{
			playerModel->elapsedTripleLaserDuration -= ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

			if (playerModel->elapsedTripleLaserDuration <= 0)
				DisableTripleLaser();
		}
	}

	void PlayerController::EnableShield()
	{
		playerModel->elapsedShieldDuration = playerModel->shieldPowerupDuration;
		playerModel->SetShieldState(true);
	}

	void PlayerController::DisableShield()
	{
		playerModel->SetShieldState(false);
	}

	void PlayerController::EnableRapidFire()
	{
		playerModel->elapsedRapidFireDuration = playerModel->rapidFirePowerupDuration;
		playerModel->SetRapidFireState(true);
	}

	void PlayerController::DisableRapidFire()
	{
		playerModel->SetRapidFireState(false);
	}

	void PlayerController::EnableTripleLaser()
	{
		playerModel->elapsedTripleLaserDuration = playerModel->tripleLaserPowerupDuration;
		playerModel->SetTripleFireState(true);
	}

	void PlayerController::DisableTripleLaser()
	{
		playerModel->SetTripleFireState(false);
	}

	sf::Vector2f PlayerController::GetPlayerPosition() const
	{
		return playerModel->GetPlayerPosition();
	}

	int PlayerController::GetPlayerScore() const
	{
		return playerModel->GetPlayerScore();
	}

	PlayerState PlayerController::GetPlayerState() const
	{
		return playerModel->GetPlayerState();
	}

	Entity::EntityType PlayerController::GetEntityType() const
	{
		return playerModel->GetEntityType();
	}

	const sf::Sprite& PlayerController::GetColliderSprite()
	{
		return playerView->GetPlayerSprite();
	}

	void PlayerController::OnCollision(ICollider* otherCollider)
	{
		if (ProcessPowerupCollision(otherCollider))
			return;

		if (ProcessBulletCollision(otherCollider))
			return;

		ProcessEnemyCollision(otherCollider);
	}

	void PlayerController::ProcessPlayerInput()
	{
		EventService* eventService = ServiceLocator::GetInstance()->GetEventService();

		if (eventService->PressedLeftKey() || eventService->PressedAKey())
		{
			MoveLeft();
		}

		if (eventService->PressedRightKey() || eventService->PressedDKey())
		{
			MoveRight();
		}

		if (eventService->PressedLeftMouseButton())
		{
			FireBullet();
		}
	}

	void PlayerController::MoveLeft()
	{
		sf::Vector2f currentPosition = playerModel->GetPlayerPosition();
		currentPosition.x -= playerModel->playerMovementSpeed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

		currentPosition.x = std::max(currentPosition.x, playerModel->leftMostPosition.x);
		playerModel->SetPlayerPosition(currentPosition);
	}
	void PlayerController::MoveRight()
	{
		sf::Vector2f currentPosition = playerModel->GetPlayerPosition();
		currentPosition.x += playerModel->playerMovementSpeed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

		currentPosition.x = std::min(currentPosition.x, playerModel->rightMostPosition.x);
		playerModel->SetPlayerPosition(currentPosition);
	}

	void PlayerController::UpdateFireDuration()
	{
		if (playerModel->elapsedFireDuration >= 0)
		{
			playerModel->elapsedFireDuration -= ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();
		}
	}

	void PlayerController::UpdateFreezeDuration()
	{
		if (playerModel->elapsedFreezeDuration > 0)
		{
			playerModel->elapsedFreezeDuration -= ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

			if (playerModel->elapsedFreezeDuration <= 0)
				playerModel->SetPlayerState(PlayerState::ALIVE);
		}
	}

	void PlayerController::ProcessBulletFire()
	{
		if (playerModel->elapsedFireDuration > 0) return;

		if (playerModel->IsTripleLaserEnabled())
			FireBullet(true);

		else FireBullet();

		if (playerModel->IsRapidFireEnabled())
			playerModel->elapsedFireDuration = playerModel->rapidFireCooldownDuration;

		else playerModel->elapsedFireDuration = playerModel->fireCooldownDuration;
	}

	void PlayerController::FireBullet(bool bTripleLaser)
	{
		sf::Vector2f bulletPosition = playerModel->GetPlayerPosition() + playerModel->barrelPositionOffset;
		FireBullet(bulletPosition);

		if (bTripleLaser)
		{
			FireBullet(bulletPosition + playerModel->secondWeaponPositionOffset);
			FireBullet(bulletPosition + playerModel->thirdWeaponPositionOffset);
		}
	}

	void PlayerController::FireBullet(sf::Vector2f position)
	{
		ServiceLocator::GetInstance()->GetBulletService()->SpawnBullet(BulletType::LASER_BULLET,
			position, Bullet::MovementDirection::UP, playerModel->GetEntityType());
	}
}