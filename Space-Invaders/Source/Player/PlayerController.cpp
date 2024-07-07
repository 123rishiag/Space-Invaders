#include "../../Header/Player/PlayerController.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Event/EventService.h"
#include "../../Header/Player/PlayerModel.h"
#include "../../Header/Player/PlayerView.h"
#include<algorithm>

namespace Player {
	using namespace Global;
	using namespace Event;
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
		ProcessPlayerInput();
		playerView->Update(); // we update() the view
	}

	void PlayerController::Render()
	{
		playerView->Render(); // render the view
	}

	sf::Vector2f PlayerController::GetPlayerPosition() const
	{
		return playerModel->GetPlayerPosition();
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

	void PlayerController::FireBullet()
	{
		ServiceLocator::GetInstance()->GetBulletService()->SpawnBullet(Bullet::BulletType::LASER_BULLET,
			playerModel->GetPlayerPosition() + playerModel->barrelPositionOffset,
			Bullet::MovementDirection::UP);
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
}