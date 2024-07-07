#pragma once
#include <SFML/System/Vector2.hpp>
#include "../../Header/Bullet/BulletConfig.h"

namespace Projectile
{
	enum class MovementDirection;

	class IProjectile
	{
	public:
		virtual void Initialize(sf::Vector2f position, Bullet::MovementDirection direction) = 0;
		virtual void Update() = 0;
		virtual void Render() = 0;

		virtual void UpdateProjectilePosition() = 0;
		virtual sf::Vector2f GetProjectilePosition() = 0;

		virtual ~IProjectile() {};
	};
}
