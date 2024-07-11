#pragma once
#include <SFML/Graphics.hpp>

namespace Bullet
{
	enum class BulletType
	{
		LASER_BULLET,
		TORPEDO,
		FROST_BULLET,
	};

	enum class MovementDirection
	{
		UP,
		DOWN,
	};

	class BulletConfig
	{
	public:
		static const sf::String laserBulletTexturePath;
		static const sf::String torpedoeTexturePath;
		static const sf::String frostBeamTexturePath;

		static sf::String GetBulletTexturePath(BulletType bulletType);
	};
}