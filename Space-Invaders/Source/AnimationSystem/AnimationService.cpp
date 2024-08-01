#include "../../Header/AnimationSystem/AnimationService.h"
#include "../../Header/AnimationSystem/AnimationSystemConfig.h"
#include "../../Header/Global/Config.h"

namespace Animation
{
	AnimationService::AnimationService() { }

	AnimationService::~AnimationService() { Destroy(); }

	void AnimationService::Initialize() { }

	void AnimationService::Update()
	{
		for (AnimationSystem* animationSystem : animationSystemList)
			animationSystem->Update();

		DestroyFlaggedAnimationSystem();
	}

	void AnimationService::Render()
	{
		for (AnimationSystem* animationSystem : animationSystemList)
			animationSystem->Render();
	}

	void AnimationService::SpawnAnimationSystem(sf::Vector2f position, AnimationType animationType)
	{
		AnimationSystem* animationSystem = new AnimationSystem(GetAnimationSystemConfig(animationType));
		animationSystem->Initialize(position);
		animationSystemList.push_back(animationSystem);
	}

	void AnimationService::DestroyAnimationSystem(AnimationSystem* animationSystem)
	{
		flaggedAnimationSystemList.push_back(animationSystem);
		animationSystemList.erase(std::remove(animationSystemList.begin(), animationSystemList.end(), animationSystem), animationSystemList.end());
	}

	AnimationSystemConfig AnimationService::GetAnimationSystemConfig(AnimationType animationType)
	{
		switch (animationType)
		{
		case Animation::AnimationType::EXPLOSION:
			return AnimationSystemConfig(Global::Config::explosionTexturePath, 70.0f, 80.0f, 14.28f, 20.0f, 7, 0.03f);
		case Animation::AnimationType::LOAD:
			return AnimationSystemConfig(Global::Config::loadIconTexturePath, 70.0f, 80.0f, 14.28f, 15.5f, 12, 0.03f);
		}
	}

	void AnimationService::DestroyFlaggedAnimationSystem()
	{
		for (AnimationSystem* particleSystem : flaggedAnimationSystemList)
			delete (particleSystem);

		flaggedAnimationSystemList.clear();
	}

	void AnimationService::Reset() { Destroy(); }

	void AnimationService::Destroy()
	{
		for (AnimationSystem* animationSystem : animationSystemList)
			delete (animationSystem);
	}
}