#include "../Header/PlayerService.h"
#include "../Header/ServiceLocator.h"

PlayerService::PlayerService()
{
	gameWindow = nullptr;
}

PlayerService::~PlayerService() = default;

//init
void PlayerService::Initialize()
{
	gameWindow = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();
	InitializePlayerSprite();
}

//take our players input in update, then set the position.
//order is important here
void PlayerService::Update()
{
	ProcessPlayerInput();
	playerSprite.setPosition(GetPlayerPosition());
}

void PlayerService::Render()
{
	gameWindow->draw(playerSprite);
}

void PlayerService::ProcessPlayerInput()
{
	EventService* eventService = ServiceLocator::GetInstance()->GetEventService(); //get the event service object created in service locator
	// Handle keyboard input
	if (eventService->IsKeyboardEvent()) //check if a key has been pressed
	{
		if (eventService->PressedLeftKey())
		{
			Move(-1.0f * GetMoveSpeed());
		}

		if (eventService->PressedRightKey())
		{
			Move(1.0f * GetMoveSpeed());
		}
	}
}

void PlayerService::InitializePlayerSprite()
{
	if (playerTexture.loadFromFile(playerTexturePath))
	{
		playerSprite.setTexture(playerTexture);
	}
}

void PlayerService::Move(float offsetX) {
	position.x += offsetX;
}

//helper functions
sf::Vector2f PlayerService::GetPlayerPosition() { return position; }
int PlayerService::GetMoveSpeed() { return movementSpeed; }
int PlayerService::GetScore() const { return playerScore; }
void PlayerService::SetScore(int newScore) { playerScore = newScore; }