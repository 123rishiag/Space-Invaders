#pragma once
#include "SFML/Audio.hpp"

namespace Sound
{
	enum class SoundType
	{
		BUTTON_CLICK,
		EXPLOSION,
	};

	class SoundService
	{
	private:
		const int backgroundMusicVolume = 30;

		sf::Music backgroundMusic;
		sf::Sound soundEffect;
		sf::SoundBuffer bufferButtonClick;
		sf::SoundBuffer bufferExplosion;

		void LoadBackgroundMusicFromFile();
		void LoadSoundFromFile();

	public:
		void Initialize();

		void PlaySound(SoundType soundType);
		void PlayBackgroundMusic();
	};
}