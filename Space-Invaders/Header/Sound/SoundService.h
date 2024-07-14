#pragma once
#include "SFML/Audio.hpp"
#include <vector>

namespace Sound
{
	enum class SoundType
	{
		BUTTON_CLICK,
		EXPLOSION,
		BULLET_FIRE,
		POWERUP_ENABLED,
		POWERUP_DISABLED,
	};

	class SoundService
	{
	private:
		const int backgroundMusicVolume = 30;
		const int soundPoolSize = 10;

		sf::Music backgroundMusic;

		std::vector<sf::Sound> soundPool;
		int currentSoundIndex;

		sf::Sound soundEffect;
		sf::SoundBuffer bufferButtonClick;
		sf::SoundBuffer bufferExplosion;
		sf::SoundBuffer bulletFire;
		sf::SoundBuffer powerupEnabled;
		sf::SoundBuffer powerupDisabled;

		void LoadBackgroundMusicFromFile();
		void LoadSoundFromFile();

	public:
		SoundService();
		~SoundService();

		void Initialize();

		void PlaySound(SoundType soundType);
		void PlayBackgroundMusic();
	};
}