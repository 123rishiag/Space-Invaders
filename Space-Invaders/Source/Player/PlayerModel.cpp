#include "../../Header/Player/PlayerModel.h"

namespace Player {

	//forward declare
	int PlayerModel::playerLives;
	int PlayerModel::enemiesKilled;

	PlayerModel::PlayerModel() { 
		bulletOwner = Entity::EntityType::PLAYER;
	}
	PlayerModel::~PlayerModel() { }

	void PlayerModel::Initialize() { Reset(); }

	void PlayerModel::Reset()
	{
		playerState = PlayerState::ALIVE;
		playerPosition = initialPlayerPosition;

		playerLives = maxPlayerLives;
		enemiesKilled = 0;

		bShield = false;
		bRapidFire = false;
		bTripleLaser = false;
	}

	sf::Vector2f PlayerModel::GetPlayerPosition() const { return playerPosition; }
	void PlayerModel::SetPlayerPosition(sf::Vector2f position) { playerPosition = position; }
	float PlayerModel::GetPlayerMoveSpeed() const { return playerMovementSpeed; }
	PlayerState PlayerModel::GetPlayerState() const { return playerState; }
	void PlayerModel::SetPlayerState(PlayerState state) { playerState = state; }
	Entity::EntityType PlayerModel::GetEntityType() const {	return bulletOwner;	}

	bool PlayerModel::IsShieldEnabled()	{ return bShield; }
	bool PlayerModel::IsRapidFireEnabled() { return bRapidFire; }
	bool PlayerModel::IsTripleLaserEnabled() { return bTripleLaser; }
	void PlayerModel::SetShieldState(bool value) { bShield = value; }
	void PlayerModel::SetRapidFireState(bool value)	{ bRapidFire = value; }
	void PlayerModel::SetTripleFireState(bool value) {	bTripleLaser = value; }

}