#pragma once
#include "SFML/Audio.hpp"

namespace Sound
{
	enum class SoundType
	{
		BUTTON_CLICK,
	};

	class SoundService
	{
	private:
		const int backgroundMusicVolume = 30;

		sf::Music backgroundMusic;
		sf::Sound soundEffect;
		sf::SoundBuffer bufferButtonClick;

		void LoadBackgroundMusicFromFile();
		void LoadSoundFromFile();

	public:
		void Initialize();

		void PlaySound(SoundType soundType);
		void PlayBackgroundMusic();
	};
}