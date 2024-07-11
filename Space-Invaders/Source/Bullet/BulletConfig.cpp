#include "../../Header/Bullet/BulletConfig.h"

namespace Bullet
{
	const sf::String BulletConfig::laserBulletTexturePath = "assets/textures/laser_bullet.png";

	const sf::String BulletConfig::torpedoeTexturePath = "assets/textures/torpedoe.png";

	const sf::String BulletConfig::frostBeamTexturePath = "assets/textures/frost_beam.png";

	sf::String BulletConfig::GetBulletTexturePath(BulletType bulletType)
	{
		switch (bulletType)
		{
		case::Bullet::BulletType::LASER_BULLET:
			return laserBulletTexturePath;

		case::Bullet::BulletType::FROST_BULLET:
			return torpedoeTexturePath;

		case::Bullet::BulletType::TORPEDO:
			return frostBeamTexturePath;
		}
	}
}