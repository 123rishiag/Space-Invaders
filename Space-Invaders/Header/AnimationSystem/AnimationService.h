#pragma once
#include <vector>
#include <SFML/System/Vector2.hpp>
#include "../../Header/AnimationSystem/AnimationSystem.h"

namespace Animation
{
	enum class AnimationType
	{
		EXPLOSION,
		LOAD,
	};

	class AnimationService
	{
	private:
		std::vector<AnimationSystem*> animationSystemList;
		std::vector<AnimationSystem*> flaggedAnimationSystemList;

		AnimationSystemConfig GetAnimationSystemConfig(AnimationType animationType);
		void DestroyFlaggedAnimationSystem();
		void Destroy();

	public:
		AnimationService();
		virtual ~AnimationService();

		void Initialize();
		void Update();
		void Render();

		void Reset();

		void SpawnAnimationSystem(sf::Vector2f position, AnimationType animationType);
		void DestroyAnimationSystem(AnimationSystem* animationSystem);
	};
}