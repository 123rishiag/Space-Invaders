#include "../../Header/Player/PlayerModel.h"

namespace Player {
	PlayerModel::PlayerModel(Entity::EntityType ownerType) { 
		bulletOwner = ownerType;
	}

	PlayerModel::~PlayerModel() { }

	void PlayerModel::Initialize() { Reset(); }

	void PlayerModel::Reset()
	{
		playerState = PlayerState::ALIVE;
		playerPosition = initialPlayerPosition;
		playerScore = 0;
	}

	sf::Vector2f PlayerModel::GetPlayerPosition() const { return playerPosition; }

	void PlayerModel::SetPlayerPosition(sf::Vector2f position) { playerPosition = position; }

	int PlayerModel::GetPlayerScore() const { return playerScore; }

	void PlayerModel::SetPlayerScore(int score) { playerScore = score; }

	float PlayerModel::GetPlayerMoveSpeed() const { return playerMovementSpeed; }

	PlayerState PlayerModel::GetPlayerState() const { return playerState; }

	void PlayerModel::SetPlayerState(PlayerState state) { playerState = state; }

	Entity::EntityType PlayerModel::GetEntityType() const
	{
		return bulletOwner;
	}

}