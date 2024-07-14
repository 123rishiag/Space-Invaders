#include "../../Header/Sound/SoundService.h"
#include "../../Header/Global/Config.h"

namespace Sound
{
	using namespace Global;

	SoundService::SoundService()
	{
		currentSoundIndex = 0;
		soundPool.resize(10); // Adjust the size based on how many simultaneous sounds you expect to play
	}

	SoundService::~SoundService() {	}

	void SoundService::Initialize()
	{
		LoadBackgroundMusicFromFile();
		LoadSoundFromFile();
	}

	void SoundService::LoadBackgroundMusicFromFile()
	{
		if (!backgroundMusic.openFromFile(Config::backgroundMusicPath)) //if this returns true then print error
			printf("Error loading background music file");
	}

	void SoundService::LoadSoundFromFile()
	{
		if (!bufferButtonClick.loadFromFile(Config::buttonClickSoundPath))
			printf("Error loading background music file");

		if (!bufferExplosion.loadFromFile(Config::explosionSoundPath))
			printf("Error loading explosion music file");

		if (!bulletFire.loadFromFile(Config::bulletFireSoundPath))
			printf("Error loading bullet fire music file");

		if (!powerupEnabled.loadFromFile(Config::powerupEnabledSoundPath))
			printf("Error loading powerup enabled music file");

		if (!powerupDisabled.loadFromFile(Config::powerupDisabledSoundPath))
			printf("Error loading powerup disabled music file");
	}

	void SoundService::PlaySound(SoundType soundType)
	{
		sf::Sound& soundEffect = soundPool[currentSoundIndex];
		currentSoundIndex = (currentSoundIndex + 1) % soundPool.size();

		switch (soundType)
		{
		case SoundType::BUTTON_CLICK:
			soundEffect.setBuffer(bufferButtonClick);
			break;
		case SoundType::EXPLOSION:
			soundEffect.setBuffer(bufferExplosion);
			break;
		case SoundType::BULLET_FIRE:
			soundEffect.setBuffer(bulletFire);
			break;
		case SoundType::POWERUP_ENABLED:
			soundEffect.setBuffer(powerupEnabled);
			break;
		case SoundType::POWERUP_DISABLED:
			soundEffect.setBuffer(powerupDisabled);
			break;
		default:
			printf("Invalid sound type");
			return;
		}
		soundEffect.play();
	}

	void SoundService::PlayBackgroundMusic()
	{
		backgroundMusic.setLoop(true);
		backgroundMusic.setVolume(backgroundMusicVolume);
		backgroundMusic.play();
	}
}