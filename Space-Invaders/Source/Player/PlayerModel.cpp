#include "../../Header/Player/PlayerModel.h"

PlayerModel::PlayerModel() { }

PlayerModel::~PlayerModel() { }

void PlayerModel::Initialize() { Reset(); }

void PlayerModel::Reset()
{
	playerState = PlayerState::ALIVE;
	playerPosition = initialPlayerPosition;
	playerScore = 0;
}

sf::Vector2f PlayerModel::GetPlayerPosition()
{
	return playerPosition;
}

void PlayerModel::SetPlayerPosition(sf::Vector2f position)
{
	playerPosition = position;
}

int PlayerModel::GetPlayerScore() const
{
	return playerScore;
}

void PlayerModel::SetPlayerScore(int score)
{
	playerScore = score;
}

float PlayerModel::GetPlayerMoveSpeed() const { return playerMovementSpeed; }

PlayerState PlayerModel::GetPlayerState()
{
	return playerState;
}

void PlayerModel::SetPlayerState(PlayerState state)
{
	playerState = state;
}