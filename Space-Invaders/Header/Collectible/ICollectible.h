#pragma once
#include <SFML/System/Vector2.hpp>

namespace Collectible
{
	class ICollectible
	{
	public:
		virtual void OnCollected() = 0;
		virtual void Initialize(sf::Vector2f position) = 0;
		virtual void Update() = 0;
		virtual void Render() = 0;
		virtual sf::Vector2f GetCollectiblePosition() = 0;

		virtual ~ICollectible() {};
	};
}