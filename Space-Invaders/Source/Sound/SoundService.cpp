#include "../../Header/Sound/SoundService.h"
#include "../../Header/Global/Config.h"

namespace Sound
{
	using namespace Global;

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
	}

	void SoundService::PlaySound(SoundType soundType)
	{
		switch (soundType)
		{
		case SoundType::BUTTON_CLICK:
			soundEffect.setBuffer(bufferButtonClick);
			break;
		case SoundType::EXPLOSION:
			soundEffect.setBuffer(bufferExplosion);
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